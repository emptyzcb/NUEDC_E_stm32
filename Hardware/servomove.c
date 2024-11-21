#include "stm32f10x.h" 
#include "Servo.h"
#include "Delay.h"
#include "Serial.h"
#include "Timer4.h"

//十个子的位置
//对应舵机角度的三个坐标{b , f , r }
//执行时先执行b,r,然后执行
int zi1[3] ={18,77,92};
int zi2[3] ={51,69,101};
int zi3[3] ={59,80,115};
int zi4[3] ={66,86,132};
int zi5[3]= {69,76,158};
	
//白
int zi6[3] ={156,70,80};///
int zi7[3] ={146,76,94};///okk
int zi8[3] ={137,73,106};///okk
int zi9[3] ={131,85,125};///okk
int zi10[3] ={127,97,150};///

	//九个格子的位置
int ge1[3] ={73,65,92};////////
int ge2[3]= {98,64,85};//okk
int ge3[3] ={121,65,88};//ok

int ge4[3] ={79,73,116};///////////
int ge5[3] ={99,66,106};//okk
int ge6[3]= {115,73,111};/////////

int ge7[3] ={84,94,144};//ok
int ge8[3] ={98,78,135};//okk
int ge9[3] ={110,88,139};//				

	




int hei=1,bai=6;

//一个动作函数 此函数可以设置机械臂的运动状态
void servoCmd(void)//顺序(b,f,r)
	//b 0~180;f 85~108;r 65~115;
{

	 int robotmove[3][3] = {
		//b   f   r
	// 180 85-108 65-115	
		 {84,107,100},
		 {170,107,100},
		 {84,85,70}
	 };
		 
	for (int i = 0; i < 3; i++) {
	//Delay_ms(1000);
	servobCmd(robotmove[i][0]);
	Delay_ms(10);
	servofCmd(robotmove[i][1]);
	Delay_ms(10);
	servorCmd(robotmove[i][2]);
		
	//angelshow();
	}
}


////提子函数,执行此函数,输入需要提起子的位置,即可执行将其提起
void tizi (int a[])// 函数调用指针,即为数组首地址
{
	//确定好垂直位置
	servobCmd(a[0]);
	Delay_ms(100);
	servorCmd(a[2]);
	Delay_ms(100);
	Delay_ms(500);
	
	//垂直降落机械臂
	servofCmd(a[1]);
	Delay_ms(500);

	//触发真空泵 提起棋子
//	famen_OFF();
//	beng_ON();
//	Delay_ms(1500);
//	beng_OFF();
	BENG();
	
	servofCmd(a[1]-18);
//	if(a[2]>=140||a[0]>=155) servofCmd(a[1]-20);
	
	Delay_ms(1500);
	//垂直升起机械臂
	servofCmd(a[1]+20);
//	if(a[2]>=140||a[0]>=155) servofCmd(a[1]+40);
	
	Delay_ms(1000);
}


////落子函数,执行此函数,输入需要落下格的位置,即可执行将其落下,并将机械臂返回原位
void luozi (int b[])// 函数调用指针,即为数组首地址
{
	//确定好垂直位置
	servobCmd(b[0]);
	Delay_ms(10);
	servorCmd(b[2]);
	Delay_ms(10);
	
	//垂直降落机械臂
	servofCmd(b[1]);
	Delay_ms(500);

	//触发阀门 放下棋子
//	beng_OFF();
	famen_ON();
	Delay_ms(2000);
//	servofCmd(b[1]+30);
	famen_OFF();
//	famen_ON();
//	Delay_ms(500);
//	famen_OFF();
	
	//返回初始状态
	ServoBegin();	
}



////4,5问 下棋函数,执行此函数,输入需要提起子的颜色和落下格的编号,即可执行将其提起落下,并将机械臂返回原位
void xiaqi(int c,int d)//c -1为黑色,1为白色    d代表几号格子
{
	
	if(c==-1) switch (hei)
	{
		case 1:tizi(zi1);hei++;break;
		case 2:tizi(zi2);hei++;break;
		case 3:tizi(zi3);hei++;break;
		case 4:tizi(zi4);hei++;break;
		case 5:tizi(zi5);hei++;break;
		//default:
	}
	
	if(c==1) switch (bai)
	{
		case 6:tizi(zi6);bai++;break;
		case 7:tizi(zi7);bai++;break;
		case 8:tizi(zi8);bai++;break;
		case 9:tizi(zi9);bai++;break;
		case 10:tizi(zi10);bai++;break;
		//default:
	}

	Delay_ms(1000);
	//落下子的函数	
	switch (d)
	{
		case 1:luozi(ge1);break;
		case 2:luozi(ge2);break;
		case 3:luozi(ge3);break;
		case 4:luozi(ge4);break;
		case 5:luozi(ge5);break;
		case 6:luozi(ge6);break;
		case 7:luozi(ge7);break;
		case 8:luozi(ge8);break;
		case 9:luozi(ge9);break;
		//default:
	}
}
	
////1,2问 移棋函数,执行此函数,输入需要提起子的颜色和落下格的编号,即可执行将其提起落下,并将机械臂返回原位
void yiqi(int e,int f)//e代表走哪颗子    f代表几号格子
{
	switch (e)
	{
		case 1:tizi(zi1);break;
		case 2:tizi(zi2);break;
		case 3:tizi(zi3);break;
		case 4:tizi(zi4);break;
		case 5:tizi(zi5);break;
		
		case 6:tizi(zi6);break;
		case 7:tizi(zi7);break;
		case 8:tizi(zi8);break;
		case 9:tizi(zi9);break;
		case 10:tizi(zi10);break;
		//default:
	}

	Delay_ms(1000);
	//落下子的函数	
	switch (f)
	{
		case 1:luozi(ge1);break;
		case 2:luozi(ge2);break;
		case 3:luozi(ge3);break;
		case 4:luozi(ge4);break;
		case 5:luozi(ge5);break;
		case 6:luozi(ge6);break;
		case 7:luozi(ge7);break;
		case 8:luozi(ge8);break;
		case 9:luozi(ge9);break;
		//default:
	}
}	
	
////6问 格间互补函数,执行此函数,输入格子间老坐标和新坐标,即可执行将其提起落下,并将机械臂返回原位
void six(int g,int h)//g代表子怎么走   f代表几号格子
{
	switch (g)
	{
		case 1:tizi(ge1);break;
		case 2:tizi(ge2);break;
		case 3:tizi(ge3);break;
		case 4:tizi(ge4);break;
		case 5:tizi(ge5);break;
		
		case 6:tizi(ge6);break;
		case 7:tizi(ge7);break;
		case 8:tizi(ge8);break;
		case 9:tizi(ge9);break;
		//default:
	}

	Delay_ms(1000);
	//落下子的函数	
	switch (h)
	{
		case 1:luozi(ge1);break;
		case 2:luozi(ge2);break;
		case 3:luozi(ge3);break;
		case 4:luozi(ge4);break;
		case 5:luozi(ge5);break;
		
		case 6:luozi(ge6);break;
		case 7:luozi(ge7);break;
		case 8:luozi(ge8);break;
		case 9:luozi(ge9);break;
		//default:
	}
}	

	
	
