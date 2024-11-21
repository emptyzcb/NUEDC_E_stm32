#include "stm32f10x.h" 
#include "Servo.h"
#include "Delay.h"
#include "Serial.h"
#include "OLED.h"
#include "string.h"

//设置一个手柄控制
int moveStep = 1; //每次手柄控制时舵机移动量
extern int Angleb,Anglef,Angler;//,Anglec;

void Serialcmd(void)
{
	int AngleB=100,AngleF=100,AngleR=100;//,AngleC=100;
	if (Serial_RxFlag == 1)		//如果接收到数据包
		{
			OLED_ShowString(4, 1, "                ");
			OLED_ShowString(4, 1, "COMMAND:");
			OLED_ShowString(4, 9, Serial_RxPacket);				
			Delay_ms(200);
	
			switch (Serial_RxPacket[0]) {
				//底座的
				case '4':  // Base向左
					Serial_SendString("Received Command: Base Turn Left\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "B Turn Left_OK");
					AngleB = Angleb - moveStep;
					servobCmd(AngleB);
					if(flag==1)Angleb=AngleB;
					break;

				case '6':  // Base向右
					Serial_SendString("Received Command: Base Turn Right\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "B Turn RIGHT_OK");
					AngleB = Angleb + moveStep;
					servobCmd(AngleB);
					Angleb=AngleB;
					break;
				//前臂的
				case 's':  // fArm向下
					Serial_SendString("Received Command: Force Turn Down\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, " Turn Down_OK");
					AngleF = Anglef - moveStep;
					servofCmd(AngleF);
					if(flag==1)Anglef=AngleF;
					break;

				case 'w':  // fArm向上
					Serial_SendString("Received Command: Force Turn Up\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "F Turn Up_OK");
					AngleF = Anglef + moveStep;
					servofCmd(AngleF);
					if(flag==1)Anglef=AngleF;
					break;
				//后臂的
				case 'd':  // rArm向下
					Serial_SendString("Received Command: Rear Turn Down\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "R Turn Down_OK");
					AngleR = Angler - moveStep;
					servorCmd(AngleR);
					if(flag==1)Angler=AngleR;
					break;

				case 'a':  // rArm向上
					Serial_SendString("Received Command: Rear Turn Up\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "R Turn Up_OK");
					AngleR = Angler + moveStep;
					servorCmd(AngleR);
					if(flag==1)Angler=AngleR;
					break;
				//阀门
				case '5':  // famen 打开
					Serial_SendString("Received Command: famen open\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "famen Open_OK");
				
						famen_ON();
						Delay_ms(1500);
						famen_OFF();

					break;
				//泵
				case '8':  // beng打开
					Serial_SendString("Received Command: beng open\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "C Turn Open_OK");
				
						
						BENG();
				
					break;
				
				case 'i'://回到初始状态
					ServoBegin ();	
					Serial_SendString("Now is the status of beginning\r\n");
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "BWGINNING");
					break;
						
				default:
					Serial_SendString("ERROR_COMMAND\r\n");			//串口回传一个字符串ERROR_COMMAND
					OLED_ShowString(4, 1, "                ");
					OLED_ShowString(4, 1, "ERROR_COMMAND");			//OLED清除指定位置，并显示ERROR_COMMAND
					
			}
					
			
			Serial_RxFlag = 0;			//处理完成后，需要将接收数据包标志位清零，否则将无法接收后续数据包
		}
	}


