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
˵����
	�˳����У�
		(1)������ɫ���� 1������� -1������� 0�������� 
*/




int main(void)
{

	LED_Init();
	OLED_Init();
	init_board();
	Servo_Init();
	Servobegin();       //���ڳ�ʼ��
	Serial_Init();         //PWM
	
	
//    OLED_ShowString(1, 1, "Angleb0:");
//    OLED_ShowString(2, 1, "Anglef1:");
//    OLED_ShowString(3, 1, "Angler2:");
//    OLED_ShowString(4, 1, "Anglec3:");    
	angelshow();
    
    Serial_Printf(" \n+++++++Welcome to my mechanical++++++++\r\n");
	
	//������
	int8_t judge=2; //��������
	
	//int Mode=0;
//	int m=0;
	
	//Mode=Mode_Get();
    
	//OLED_ShowString(1, 1, "m:");
    //OLED_ShowString(2, 1, "Anglef1:");




		Delay_ms(1000);
		
		
	  /////ѭ������ִ��
	  	//�������Ӳ���

//		tizi(zi1);
//		luozi(ge1);		
		
		//�����������Ӳ���
//		xiaqi(-1,1);
//		Delay_ms(1500);
		
		//����֮�以������
//		for(int i=1;i<=9;i++)
//		{
//			if(i!=5) six(i,5);
//			Delay_ms(1000);
//		}


//     	//���Ե�һ����
		yiqi(10,5);//e�������Ŀ���    f�����Ÿ���


////4,5�� ���庯��,ִ�д˺���,������Ҫ�����ӵ���ɫ�����¸�ı��,����ִ�н�����������,������е�۷���ԭλ
//		xiaqi(int c,int d)//c -1Ϊ��ɫ,1Ϊ��ɫ    d�����Ÿ���
	



		
		

	while(1)
	{
		//����������
//		switch(Mode)
//		{
//			case 0 : break;      
//			case 1://��һ���ʽ������
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
//				//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ�û���ж�ָ�� ����ִ�����ĳ���
//				wait_instructions();//���ڽ��ܴ��ڴ��͵��ж�ָ��ڴ����и��ļ���ֵ��������ѭ��            1
//				LED8_OFF();	
//				
//				request_vision();//�˺���������k210���ʹ�������
//				//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ
//			
//				Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
//				
//				OLED_ShowString(4,9,"no");
//				judge=judge_the_opening();//���������жϣ�����1 �������� ����0 ������
//			
//				OLED_ShowNum(4,0,judge,3);
//			
//				switch(judge)
//				{
//					case 1://��������
//							machine_open();//����ִ�е�����Ĺ̶��߷�
//							break;
//					case 0://������				
//							man_open();
//							break;
//			    }
//				break;
//			}
//			//OLED_ShowNum(1,5,m,3);
//			
			
			
		//��е�۵��Ժ���
				
	    //��ʼ���Գ���
//		Angleb += 10;			//�Ƕȱ�������30
//		Servob(Angleb);
//		Delay_ms(700);
//		if (Angleb > 180)			//�Ƕȱ�������180��
//		{
//			Angleb = 90;				//�Ƕȱ�������
//		}
//		angelshow();
		
		
//		Anglef += 10;			//�Ƕȱ�������30
//		Servof(Anglef);
//		Delay_ms(700);
//		if (Anglef > 110)			//�Ƕȱ�������180��
//		{
//			Anglef = 50;				//�Ƕȱ�������
//		}
//		angelshow();
		
		
		
//		Angler += 10;			//�Ƕȱ�������30
//		Servor(Angler);
//		Delay_ms(700);
//		if (Angler > 110)			//�Ƕȱ�������180��
//		{
//			Angler = 50;				//�Ƕȱ�������
//		}
//		angelshow();
		


//	    //�μ����Գ���
//		servorCmd(85);
//		Delay_ms(1000);
//		servorCmd(105);
//		Delay_ms(1000);


//		//�߼����Գ���

//		Delay_ms(500);
//		servoCmd();
		
		
		//�ı����ݰ����ڲ��Գ���
//		if (Serial_RxFlag == 1)		//������յ����ݰ�
//		{
//			OLED_ShowString(4, 1, "                ");
//			OLED_ShowString(4, 1, Serial_RxPacket);				//OLED���ָ��λ�ã�����ʾ���յ������ݰ�
//			
//			/*���յ������ݰ���Ԥ���ָ��Աȣ��Դ˾�����Ҫִ�еĲ���*/
//			if (strcmp(Serial_RxPacket, "MOVEr85") == 0)			//����յ�LED_ONָ��
//			{
//				servorCmd(85);									//����LED
//				Serial_SendString("Servo_Mover85_OK\r\n");				//���ڻش�һ���ַ���LED_ON_OK
//				OLED_ShowString(4, 1, "                ");
//				OLED_ShowString(4, 1, "Servo_Mover85_OK");				//OLED���ָ��λ�ã�����ʾLED_ON_OK
//			}
//			else if (strcmp(Serial_RxPacket, "MOVEr105") == 0)	//����յ�LED_OFFָ��
//			{
//				servorCmd(105);									//Ϩ��LED
//				Serial_SendString("MOVEr105_OK\r\n");			//���ڻش�һ���ַ���LED_OFF_OK
//				OLED_ShowString(4, 1, "                ");
//				OLED_ShowString(4, 1, "MOVEr105_OK");			//OLED���ָ��λ�ã�����ʾLED_OFF_OK
//			}
//			else						//�������������������㣬���յ���δָ֪��
//			{
//				Serial_SendString("ERROR_COMMAND\r\n");			//���ڻش�һ���ַ���ERROR_COMMAND
//				OLED_ShowString(4, 1, "                ");
//				OLED_ShowString(4, 1, "ERROR_COMMAND");			//OLED���ָ��λ�ã�����ʾERROR_COMMAND
//			}
//			
//			Serial_RxFlag = 0;			//������ɺ���Ҫ���������ݰ���־λ���㣬�����޷����պ������ݰ�
//		}

		//�ı����Դ��ں�������
		Serialcmd();


        //hex���ں�������
//		Serial2_SendByte(0x88);
//		Delay_ms(500);

//		if (Serial2_GetRxFlag() == 1)	//������յ����ݰ�
//		{
//			OLED_ShowHexNum(2, 1, Serial2_RxPacket[0], 2);	//��ʾ���յ����ݰ�
//			OLED_ShowHexNum(2, 4, Serial2_RxPacket[1], 2);
//			OLED_ShowHexNum(2, 7, Serial2_RxPacket[2], 2);	//��ʾ���յ����ݰ�
//			
//			OLED_ShowHexNum(3, 1, Serial2_RxPacket[3], 2);
//			OLED_ShowHexNum(3, 4, Serial2_RxPacket[4], 2);	//��ʾ���յ����ݰ�
//			OLED_ShowHexNum(3, 7, Serial2_RxPacket[5], 2);
//			
//			OLED_ShowHexNum(4, 1, Serial2_RxPacket[6], 2);
//			OLED_ShowHexNum(4, 4, Serial2_RxPacket[7], 2);	//��ʾ���յ����ݰ�
//			OLED_ShowHexNum(4, 7, Serial2_RxPacket[8], 2);
//		}
		
		
		//˫��ʱ���ֿ�pwm����	
//		Angleb += 10;			//�Ƕȱ�������30
//		Beng +=10;
//		Servob(Angleb);
//		beng(Beng);
//		
//		Delay_ms(700);
//		if (Angleb > 110)			//�Ƕȱ�������180��
//		{
//			Angleb = 50;				//�Ƕȱ�������
//		}
//		
//		if (Beng > 80)			//�Ƕȱ�������180��
//		{
//			Beng = 30;				//�Ƕȱ�������
//		}
//		angelshow();

		//�úͷ��Ų���
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



