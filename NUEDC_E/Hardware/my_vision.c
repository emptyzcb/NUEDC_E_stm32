#include "stm32f10x.h"
#include "Serial.h"
#include "OLED.h"
#include "Minmax.h"
/*
�˺���������k210���ʹ������ݣ������Ӿ��ܹ�����������Ϣ(�ù��ܲ��ڴ˴�������������)
�˺�������K210���������

*/

void request_vision(void)
{
	Serial2_SendByte(0x88);
}


/*

�˺��������жϴ����Ƿ��յ��Ӿ�����������Ϣ

���ڴ˴���������Ϣ��������Ϣ�ڴ����жϺ����и���

���δ�յ���Ϣ������ִ����������

*/

void Awaiting_Vision(void)
{
	int k=1;
	while(k)
	{
		OLED_ShowString(4,9,"ka");
		//request_vision();//�˺���������k210���ʹ�������
		if(Awaiting_Vision_judge==1)
		{
			//��a��ֵ��board
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					
					board[i][j]=a[i][j];
					
					//��������ʾ���Ժ���
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


