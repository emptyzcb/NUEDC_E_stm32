#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "stdio.h"
#include "mode_chess.h"
#include <stdlib.h>
#include <string.h> 
#include "Minmax.h"
#include "my_vision.h"
#include  "judge.h"

#include "Timer4.h"
#include "LED.h"
#include "Serial.h"
#include "Servo.h"

#include "Servomove.h"
#include "SerialContral.h"
/*
说明：
	此程序中：
		(1)棋子颜色采用 1代表白棋 -1代表黑棋 0代表无棋 
*/




int main(void)
{

	LED_Init();
	OLED_Init();
	init_board();
	Servo_Init();
	Servobegin();       //串口初始化
	Serial_Init();         //PWM
	
	
//    OLED_ShowString(1, 1, "Angleb0:");
//    OLED_ShowString(2, 1, "Anglef1:");
//    OLED_ShowString(3, 1, "Angler2:");
//    OLED_ShowString(4, 1, "Anglec3:");    
	angelshow();
    
    Serial_Printf(" \n+++++++Welcome to my mechanical++++++++\r\n");
	
	//变量区
	int8_t judge=2; //区分先手
	
	//int Mode=0;
//	int m=0;
	
	//Mode=Mode_Get();
    
	//OLED_ShowString(1, 1, "m:");
    //OLED_ShowString(2, 1, "Anglef1:");




		Delay_ms(1000);
		
		
	  /////循环外面执行
	  	//提子落子测试

//		tizi(zi1);
//		luozi(ge1);		
		
		//合体提子落子测试
//		xiaqi(-1,1);
//		Delay_ms(1500);
		
		//格子之间互补测试
//		for(int i=1;i<=9;i++)
//		{
//			if(i!=5) six(i,5);
//			Delay_ms(1000);
//		}


//     	//测试第一二问
		yiqi(10,5);//e代表走哪颗子    f代表几号格子


////4,5问 下棋函数,执行此函数,输入需要提起子的颜色和落下格的编号,即可执行将其提起落下,并将机械臂返回原位
//		xiaqi(int c,int d)//c -1为黑色,1为白色    d代表几号格子
	



		
		

	while(1)
	{
		//正经主程序
//		switch(Mode)
//		{
//			case 0 : break;      
//			case 1://第一二问解决方案
//			//m++;
//			if(start==1)
//			{
//			//	m++;
//				yiqi(TI,FANG);
//				start=0;
//			}
//				break;
//			case 3:
//				
//				break;
//			case 4:
//				
//				//此函数用于接收唯一指定按键给装置的行动指令，没有行动指令 不予执行下文程序
//				wait_instructions();//用于接受串口传送的行动指令，在串口中更改键码值跳出此死循环            1
//				LED8_OFF();	
//				
//				request_vision();//此函数用于向k210发送串口数据
//				//此函数用于判断视觉是否传递棋盘信息
//			
//				Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
//				
//				OLED_ShowString(4,9,"no");
//				judge=judge_the_opening();//用于先手判断，返回1 机器先手 返回0 人先手
//			
//				OLED_ShowNum(4,0,judge,3);
//			
//				switch(judge)
//				{
//					case 1://机器先手
//							machine_open();//用于执行第四题的固定走法
//							break;
//					case 0://人先手				
//							man_open();
//							break;
//			    }
//				break;
//			}
//			//OLED_ShowNum(1,5,m,3);
//			
			
			
		//机械臂调试函数
				
	    //初始测试程序
//		Angleb += 10;			//角度变量自增30
//		Servob(Angleb);
//		Delay_ms(700);
//		if (Angleb > 180)			//角度变量超过180后
//		{
//			Angleb = 90;				//角度变量归零
//		}
//		angelshow();
		
		
//		Anglef += 10;			//角度变量自增30
//		Servof(Anglef);
//		Delay_ms(700);
//		if (Anglef > 110)			//角度变量超过180后
//		{
//			Anglef = 50;				//角度变量归零
//		}
//		angelshow();
		
		
		
//		Angler += 10;			//角度变量自增30
//		Servor(Angler);
//		Delay_ms(700);
//		if (Angler > 110)			//角度变量超过180后
//		{
//			Angler = 50;				//角度变量归零
//		}
//		angelshow();
		


//	    //次级测试程序
//		servorCmd(85);
//		Delay_ms(1000);
//		servorCmd(105);
//		Delay_ms(1000);


//		//高级测试程序

//		Delay_ms(500);
//		servoCmd();
		
		
		//文本数据包串口测试程序
//		if (Serial_RxFlag == 1)		//如果接收到数据包
//		{
//			OLED_ShowString(4, 1, "                ");
//			OLED_ShowString(4, 1, Serial_RxPacket);				//OLED清除指定位置，并显示接收到的数据包
//			
//			/*将收到的数据包与预设的指令对比，以此决定将要执行的操作*/
//			if (strcmp(Serial_RxPacket, "MOVEr85") == 0)			//如果收到LED_ON指令
//			{
//				servorCmd(85);									//点亮LED
//				Serial_SendString("Servo_Mover85_OK\r\n");				//串口回传一个字符串LED_ON_OK
//				OLED_ShowString(4, 1, "                ");
//				OLED_ShowString(4, 1, "Servo_Mover85_OK");				//OLED清除指定位置，并显示LED_ON_OK
//			}
//			else if (strcmp(Serial_RxPacket, "MOVEr105") == 0)	//如果收到LED_OFF指令
//			{
//				servorCmd(105);									//熄灭LED
//				Serial_SendString("MOVEr105_OK\r\n");			//串口回传一个字符串LED_OFF_OK
//				OLED_ShowString(4, 1, "                ");
//				OLED_ShowString(4, 1, "MOVEr105_OK");			//OLED清除指定位置，并显示LED_OFF_OK
//			}
//			else						//上述所有条件均不满足，即收到了未知指令
//			{
//				Serial_SendString("ERROR_COMMAND\r\n");			//串口回传一个字符串ERROR_COMMAND
//				OLED_ShowString(4, 1, "                ");
//				OLED_ShowString(4, 1, "ERROR_COMMAND");			//OLED清除指定位置，并显示ERROR_COMMAND
//			}
//			
//			Serial_RxFlag = 0;			//处理完成后，需要将接收数据包标志位清零，否则将无法接收后续数据包
//		}

		//文本调试串口函数测试
		Serialcmd();


        //hex串口函数测试
//		Serial2_SendByte(0x88);
//		Delay_ms(500);

//		if (Serial2_GetRxFlag() == 1)	//如果接收到数据包
//		{
//			OLED_ShowHexNum(2, 1, Serial2_RxPacket[0], 2);	//显示接收的数据包
//			OLED_ShowHexNum(2, 4, Serial2_RxPacket[1], 2);
//			OLED_ShowHexNum(2, 7, Serial2_RxPacket[2], 2);	//显示接收的数据包
//			
//			OLED_ShowHexNum(3, 1, Serial2_RxPacket[3], 2);
//			OLED_ShowHexNum(3, 4, Serial2_RxPacket[4], 2);	//显示接收的数据包
//			OLED_ShowHexNum(3, 7, Serial2_RxPacket[5], 2);
//			
//			OLED_ShowHexNum(4, 1, Serial2_RxPacket[6], 2);
//			OLED_ShowHexNum(4, 4, Serial2_RxPacket[7], 2);	//显示接收的数据包
//			OLED_ShowHexNum(4, 7, Serial2_RxPacket[8], 2);
//		}
		
		
		//双定时器分开pwm测试	
//		Angleb += 10;			//角度变量自增30
//		Beng +=10;
//		Servob(Angleb);
//		beng(Beng);
//		
//		Delay_ms(700);
//		if (Angleb > 110)			//角度变量超过180后
//		{
//			Angleb = 50;				//角度变量归零
//		}
//		
//		if (Beng > 80)			//角度变量超过180后
//		{
//			Beng = 30;				//角度变量归零
//		}
//		angelshow();

		//泵和阀门测试
//		famen_OFF();
//		beng_ON();
//		Delay_ms(3000);
//		beng_OFF();

//		Delay_ms(3000);

//		beng_OFF();
//		famen_ON();
//		Delay_ms(1500);
//		famen_OFF();
		


	  }
	


}



