#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"
#include "Serial.h"
#include "OLED.h"
#include "Timer4.h"

#define 	AnglebBEGIN 145//横向
#define  	AnglefBEGIN 90//纵向
#define  	AnglerBEGIN 90//纵向

int speed=50;//舵机等待时间
int Angleb,Anglef,Angler,flag=1;//Anglec,

//舵机初始参数调整

const int bMin = 30;
const int bMax = 170;

const int fMin = 14;//前臂最小值
const int fMax = 128;//前臂最大值

const int rMin = 52;//后臂最小值
const int rMax = 150;//后臂最大值

//const int cMin = 0;
//const int cMax = 100;


void Servo_Init(void)
{
	PWM_Init();									//初始化舵机的底层PWM
}


/**
  * 函    数：舵机设置角度
  * 参    数：Angle 要设置的舵机角度，范围：0~180
  * 返 回 值：无
  */
void Servob(int Angleb)//底座舵机 对应P0
{
	float b=Angleb;
	PWM_SetCompare1(b/ 180 * 2000 + 500);	//设置占空比
												//将角度线性变换，对应到舵机要求的占空比范围上
}

void Servof(int Anglef)//前舵机  对应P1
{
	float f=Anglef;
	PWM_SetCompare2(f / 180 * 2000 + 500);	//设置占空比
												//将角度线性变换，对应到舵机要求的占空比范围上
}

void Servor(int Angler)//后舵机  对应P2
{
	float r=Angler;
	PWM_SetCompare3(r / 180 * 2000 + 500);	//设置占空比
												//将角度线性变换，对应到舵机要求的占空比范围上
}

//void Servoc(int Anglec)//钳子舵机  对应P3///////改成那个真空泵 180为打开,0为关闭

//{
//	float c=Anglec;
//	PWM_SetCompare4(c / 180 * 2000 + 500);	//设置占空比
//		
//	//将角度线性变换，对应到舵机要求的占空比范围上
//}


void beng(int a)//泵
{
	float beng=a;
	PWM2_SetCompare1(beng/ 180 * 2000 + 500);	//设置占空比
												//将角度线性变换，对应到舵机要求的占空比范围上
}

void famen(int b)//阀门
{
	float famen=b;
	PWM2_SetCompare2(famen / 180 * 2000 + 500);	//设置占空比
												//将角度线性变换，对应到舵机要求的占空比范围上
}

void beng_ON(void)
{
	beng(180);
}

void beng_OFF(void)
{
	beng(0);
}
///////////////////////////////////////定时器版本泵函数
void BENG(void)
{
	beng_ON();
	Timer4_Init();
}


void famen_ON(void)
{
	famen(180);
}
void famen_OFF(void)
{
	famen(0);
}



void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		Num++;
		if(Num>=10) //定时10s
		{
			beng_OFF();
			Num=0;
			TIM_Cmd(TIM4,DISABLE);
		}
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}




void angelshow(void)
{
		OLED_ShowNum(1, 10, Angleb, 3);	
		OLED_ShowNum(2, 10, Anglef, 3);
		OLED_ShowNum(3, 10, Angler, 3);
//		OLED_ShowNum(4, 10, Anglec, 3);
}


void Servomove(){//普通驱动所有舵机(直接驱动,比较粗鲁)
	Servob(Angleb);
	Delay_ms(10);
	Servof(Anglef);
	Delay_ms(10);
	Servor(Angler);
	Delay_ms(10);
//	Servoc(Anglec);
//	Delay_ms(10);
}

void Servobegin (void)//舵机返回初始状态函数
{
	Angleb=AnglebBEGIN;
	Anglef=AnglefBEGIN;
	Angler=AnglerBEGIN;
//	Anglec=40;
	Servomove();
	angelshow();
}
//AnglebBEGIN
//AnglefBEGIN
//AnglerBEGIN


void servobCmd(int toPos) //b作例子 控制函数
{
	int fromPos;
	if (toPos >= bMin && toPos <= bMax) {//看是否符合要求
        fromPos = Angleb;  // 获取当前电机角度值用于“电机运动起始角度值”
      } 
	else {
        Serial_Printf("+Warning: Base Servo Value Out Of Limit!\r\n");//串口打印程序
        return;
      }
	
	  
	  if (fromPos <= toPos) { //如果“起始角度值”小于“目标角度值”
    for (int i = fromPos; i <= toPos; i++) {
		Angleb=i;
		Servob(Angleb);
		Delay_ms (speed);
    }
  }  else { //否则“起始角度值”大于“目标角度值”
    for (int i = fromPos; i >= toPos; i--) {
		Angleb=i;
		Servob(Angleb);
		Delay_ms(speed);
    }
  }
  Serial_Printf("+OK now Angleb:%d\r\n ",Angleb);
  angelshow();
	  
}

void servofCmd(int toPos) //f作例子 控制函数
{
	int fromPos;
	if (toPos >= fMin && toPos <= fMax) {
        fromPos = Anglef;  // 获取当前电机角度值用于“电机运动起始角度值”
      } 
	else {
        Serial_Printf("+Warning: Force Servo Value Out Of Limit!\r\n");//串口打印程序
		flag=0;
        return;
      }
	  if (fromPos <= toPos) { //如果“起始角度值”小于“目标角度值”
    for (int i = fromPos; i <= toPos; i++) {
		Anglef=i;
		Servof(Anglef);
		Delay_ms (speed);
    }
  }  else { //否则“起始角度值”大于“目标角度值”
    for (int i = fromPos; i >= toPos; i--) {
		Anglef=i;
		Servof(Anglef);
		Delay_ms(speed);
    }
  }
  flag=1;
  Serial_Printf("+OK now Anglef:%d\r\n ",Anglef);
  angelshow();
}


void servorCmd(int toPos) //r作例子 控制函数
{
	int fromPos;
	if (toPos >= rMin && toPos <= rMax) {//看是否符合要求
        fromPos = Angler;  // 获取当前电机角度值用于“电机运动起始角度值”
      } 
	else {
        Serial_Printf("+Warning: Rear Servo Value Out Of Limit!\r\n");//串口打印程序
        return;
      }
	
	  
	  if (fromPos <= toPos) { //如果“起始角度值”小于“目标角度值”
    for (int i = fromPos; i <= toPos; i++) {
		Angler=i;
		Servor(Angler);
		Delay_ms (speed);
    }
  }  else { //否则“起始角度值”大于“目标角度值”
    for (int i = fromPos; i >= toPos; i--) {
		Angler=i;
		Servor(Angler);
		Delay_ms(speed);
    }
  }
  Serial_Printf("+OK now Angler:%d\r\n ",Angler);
  angelshow();
	  
}

//void servocCmd(int toPos) //r作例子 控制函数
//{
//	int fromPos;
//	if (toPos >= cMin && toPos <= cMax) {//看是否符合要求
//        fromPos = Anglec;  // 获取当前电机角度值用于“电机运动起始角度值”
//      } 
//	
//	else {
//        Serial_Printf("+Warning: Calw Servo Value Out Of Limit!\r\n");//串口打印程序
//        return;
//      }
//	
//	  
//	  if (fromPos <= toPos) { //如果“起始角度值”小于“目标角度值”
//    for (int i = fromPos; i <= toPos; i++) {
//		Anglec=i;
//		Servoc(Anglec);
//		Delay_ms (speed);
//    }
//  }  else { //否则“起始角度值”大于“目标角度值”
//    for (int i = fromPos; i >= toPos; i--) {
//		Anglec=i;
//		Servoc(Anglec);
//		Delay_ms(speed);
//    }
//  }
//  Serial_Printf("+OK now Anglec:%d\r\n ",Anglec);
//  angelshow();
//	  
//}

void ServoMove(){//普通驱动所有舵机(直接驱动,比较粗鲁)
	servobCmd(Angleb);
	Delay_ms(800);
	servofCmd(Anglef);
	Delay_ms(800);
	servorCmd(Angler);
	Delay_ms(800);
//	servocCmd(Anglec);
//	Delay_ms(10);
}

void ServoBegin (void)//舵机返回初始状态函数
{
	Angleb=AnglebBEGIN;
	Anglef=AnglefBEGIN;
	Angler=AnglerBEGIN;
	ServoMove();
	angelshow();
}
