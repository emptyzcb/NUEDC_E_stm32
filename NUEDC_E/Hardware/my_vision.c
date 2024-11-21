#include "stm32f10x.h"
#include "Serial.h"
#include "OLED.h"
#include "Minmax.h"
/*
此函数用于向k210发送串口数据，以求视觉能够发送棋盘信息(该功能不在此处处理，不予讨论)
此函数仅向K210单项发送请求

*/

void request_vision(void)
{
	Serial2_SendByte(0x88);
}


/*

此函数用于判断串口是否收到视觉传回棋盘信息

不在此处处理传回信息，传回信息在串口中断函数中更改

如果未收到信息，不予执行其他程序

*/

void Awaiting_Vision(void)
{
	int k=1;
	while(k)
	{
		OLED_ShowString(4,9,"ka");
		//request_vision();//此函数用于向k210发送串口数据
		if(Awaiting_Vision_judge==1)
		{
			//把a赋值给board
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					
					board[i][j]=a[i][j];
					
					//单纯的显示调试函数
//					OLED_ShowNum(1,1,board[0][0],1);
//					OLED_ShowNum(1,4,board[0][1],1);
//					OLED_ShowNum(1,6,board[0][2],1);
//					
//					OLED_ShowNum(2,1,board[1][0],1);
//					OLED_ShowSignedNum(2,3,board[1][1],2);
//					OLED_ShowNum(2,6,board[1][2],1);
//					
//					OLED_ShowNum(3,1,board[2][0],1);
//					OLED_ShowNum(3,4,board[2][1],1);
//					OLED_ShowNum(3,6,board[2][2],1);
				}
			}
			k=0;
		}
	}
	Awaiting_Vision_judge=0;
}


