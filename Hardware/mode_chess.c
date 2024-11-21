#include "stm32f10x.h" 
#include "Delay.h"
#include "Minmax.h"
#include "my_vision.h"
#include  "judge.h"
#include <stdlib.h>
#include <string.h> 

#include "Servomove.h"
#include "Serial.h"
#include "OLED.h"
#include "LED.h"


int best_result=0;
int recorde_distinction;////此处检查玩家移动棋子与否的函数


void wait_instructions(void)
{
	int k=1;
	while(k)
	{
		if(key==1)
		{
			k=0;
		}
	}
	key=0;
}


int MAN_result_five(void)
{
	
		if(board[0][1]==0&&board[1][0]==0&&board[1][2]==0&&board[2][1]==0)//判断人是否下到除对角外的点
		{
			return 0;//表示人没有下错
		}
		else
		{
			return 1;//人下错
		}

}




/*
   此部分流程如下:
*/
void machine_open(void)
{
		    //此函数装置执黑棋放入五号位（天元）
			xiaqi(-1,5);//5//换成机械臂控制
			LED8_ON();
	
			digit_to_Mark(5,-1);
			memcpy(last_board,board,sizeof(board));//存储人走之前的棋局
	
			//此函数用于接收唯一指定按键给装置的行动指令
			wait_instructions();
			LED8_OFF();
			
			//GPIO_SetBits(GPIOA, GPIO_Pin_8);//收到指令 开始计时 指示灯亮起
			request_vision();//此函数用于向k210发送串口数据
			Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
			                 //储存人走之后的棋局
			
	
			//作用为机器检测人下棋的位置，并将该位值记录下来
			int where_num_coordinate=MAN_SET_Chess();//检测人落子位置，并记入数组，计入board[][] 
			
			
			switch (where_num_coordinate) 
			{
			case 2:
			    xiaqi(-1,7);//7
				LED8_ON();
			 
			
				digit_to_Mark(7,-1);
				memcpy(last_board,board,sizeof(board));//存储人走之前的棋局
			
				
				//此函数用于接收唯一指定按键给装置的行动指令
				wait_instructions();
				LED8_OFF();
			
			
				request_vision();//此函数用于向k210发送串口数据
				Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
								 //储存人走之后的棋局
			
			   where_num_coordinate=MAN_SET_Chess();
			   if(where_num_coordinate!=3)
			   {
				   
					 xiaqi(-1,3);//3
					LED8_ON();
			   }
			   else if(where_num_coordinate==3)
			   {
					 xiaqi(-1,1);//1
				   LED8_ON();
				   
				   digit_to_Mark(1,-1);
				   memcpy(last_board,board,sizeof(board));//存储人走之前的棋局
				   
					//此函数用于接收唯一指定按键给装置的行动指令
					wait_instructions();
				     LED8_OFF();
					request_vision();//此函数用于向k210发送串口数据
					//此函数用于判断视觉是否传递棋盘信息
					Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
				   
					where_num_coordinate=MAN_SET_Chess();
				   if(where_num_coordinate==4)
				   {
					 xiaqi(-1,9);//9
					 LED8_ON();	
					   //-1   1   1 
					   // 1  -1   0
					   //-1   0  -1
				   }
				   else
				   {
						  xiaqi(-1,4);
					   LED8_ON();	
					   //-1   1  1 
					   //-1  -1  0
					   //-1   0  1
				   }
			   }

			   break;
			
			case 4:
			    xiaqi(-1,9);//9
				LED8_ON();
				digit_to_Mark(9,-1);
				memcpy(last_board,board,sizeof(board));//存储人走之前的棋局
			
				
			/*
				0  0  0
			    1 -1  0
			    0  0 -1
			*/
				//此函数用于接收唯一指定按键给装置的行动指令
				wait_instructions();
			   LED8_OFF();
				//此函数用于判断视觉是否传递棋盘信息				//GPIO_SetBits(GPIOA, GPIO_Pin_8);//收到指令 开始计时 指示灯亮起
				request_vision();//此函数用于向k210发送串口数据

				Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
			
			   where_num_coordinate=MAN_SET_Chess();
			   if(where_num_coordinate!=1)
			   {
					 xiaqi(-1,1);//1
				   LED8_ON();
				/*
				   -1  0  0
					1 -1  0
					0  0 -1
				*/
			   }
			   else if(where_num_coordinate==1)
			   {
					 xiaqi(-1,7);//7
				   LED8_ON();
				   digit_to_Mark(7,-1);
				   memcpy(last_board,board,sizeof(board));//存储人走之前的棋局
		    /*
			    1  0  0
			    1 -1  0
			   -1  0 -1
			*/   
				//此函数用于接收唯一指定按键给装置的行动指令
				wait_instructions();
				LED8_OFF();
				request_vision();//此函数用于向k210发送串口数据
				//此函数用于判断视觉是否传递棋盘信息
				Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
				   
				   where_num_coordinate=MAN_SET_Chess();
				   if(where_num_coordinate==3)
				   {
					  xiaqi(-1,7);//7
					  LED8_ON();	
					   // 1   0   1 
					   // 1  -1   0
					   //-1  -1  -1
				   }
				   else
				   {
					   xiaqi(-1,3);//3
					  LED8_ON();	
					   // 1   1  -1 
					   // 1  -1   0
					   //-1   0  -1
				   }
			   }
				break;
			case 6:
			    xiaqi(-1,1);//1
				LED8_ON();
				digit_to_Mark(1,-1);
				memcpy(last_board,board,sizeof(board));//存储人走之前的棋局
			
					
				//-1  0   0
				//0  -1   1
				//0   0   0
		  
				//此函数用于接收唯一指定按键给装置的行动指令
				wait_instructions();
			    LED8_OFF();
				request_vision();//此函数用于向k210发送串口数据
				//此函数用于判断视觉是否传递棋盘信息
				Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
			
			   where_num_coordinate=MAN_SET_Chess();
			   if(where_num_coordinate!=9)
			   {
					 xiaqi(-1,9);//9
				     LED8_ON();	
			   }
			   else if(where_num_coordinate==9)
			   {
				   //-1  0   0
				   //0  -1   1
				   //0   0   1
					xiaqi(-1,3);//3
				   LED8_ON();
				   digit_to_Mark(3,-1);
				   memcpy(last_board,board,sizeof(board));//存储人走之前的棋局	
				   //-1  0  -1
				   //0  -1   1
				   //0   0   1
					  
					//此函数用于接收唯一指定按键给装置的行动指令
					wait_instructions();
				    LED8_OFF();
					//GPIO_SetBits(GPIOA, GPIO_Pin_8);//收到指令 开始计时 指示灯亮起
					request_vision();//此函数用于向k210发送串口数据
					//此函数用于判断视觉是否传递棋盘信息
					Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
					   
					where_num_coordinate=MAN_SET_Chess();
				   if(where_num_coordinate==2)
				   {
				   //-1  1  -1
				   //0  -1   1
				   //0   0   1
					  xiaqi(-1,7);//7
					  LED8_ON();
					 
				   //-1  1  -1
				   //0  -1   1
				   //-1   0  1
				   }
				   else
				   {
						 xiaqi(-1,2);//2
					     LED8_ON();	
					   //-1  -1  -1
					   //0  -1   1
					   //1   0   1
				   }
			   }
			
			

				break;
			case 8:
				 xiaqi(-1,3);
				LED8_ON();
				digit_to_Mark(3,-1);
				memcpy(last_board,board,sizeof(board));//存储人走之前的棋局
			
			
			     
				//0   0   -1
				//0  -1   0
				//0   1   0
			  
				//此函数用于接收唯一指定按键给装置的行动指令
				wait_instructions();
				LED8_OFF();
				//GPIO_SetBits(GPIOA, GPIO_Pin_8);//收到指令 开始计时 指示灯亮起
				request_vision();//此函数用于向k210发送串口数据
				//此函数用于判断视觉是否传递棋盘信息
				Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
			
			    where_num_coordinate=MAN_SET_Chess();
			   if(where_num_coordinate!=7)
			   {
				   xiaqi(-1,7);//7
				   LED8_ON();	
				   //0   0   -1
				   //0  -1    0
				   //-1   1   0
			
			   }
			   else if(where_num_coordinate==7)
			   {
					//0   0   -1
					//0  -1   0
					//1   1   0
					 xiaqi(-1,9);//9
				   LED8_ON();
				   digit_to_Mark(9,-1);
				   memcpy(last_board,board,sizeof(board));//存储人走之前的棋局
				    
					//0   0  -1
					//0  -1   0
					//1   1  -1
					  
					//此函数用于接收唯一指定按键给装置的行动指令
					wait_instructions();
				    LED8_OFF();
					//GPIO_SetBits(GPIOA, GPIO_Pin_8);//收到指令 开始计时 指示灯亮起
					request_vision();//此函数用于向k210发送串口数据
					//此函数用于判断视觉是否传递棋盘信息
					Awaiting_Vision();//用于接受串口传送的信息，收到键码更改时，跳出循环
				   
					where_num_coordinate=MAN_SET_Chess();
				   if(where_num_coordinate==6)
				   {
					//0   0  -1
					//0  -1   1
					//1   1  -1
					  xiaqi(-1,1);//1
					   LED8_ON();
					//-1   0  -1
					//0  -1   1
					//1   1  -1
				   
				   }
				   else
				   {
						 xiaqi(-1,6);
					     LED8_ON();
					//1   0  -1
					//0  -1   -1
					//1   1  -1
				   }
			   }
			
			 break;
		   }

}




void man_open(void)
{
		best_result=computer_move(1);//白棋为1 黑棋为-1 机器为白
		OLED_ShowNum(4,5,best_result,3);
		xiaqi(1,best_result);
		LED8_ON();

		while(1)
		{
//.............................................................................................................................................
			time_return:
			wait_instructions();
			LED8_OFF();
			
			request_vision();//此函数用于向k210发送串口数据
			Awaiting_Vision();//此函数用于判断视觉是否传递棋盘信息
			
				
			//此处检查玩家移动棋子与否的函数,返回1 棋子被移动 返回0 没有被移走
			recorde_distinction=judge_the_board();
			if(recorde_distinction==1)
			{
				//被移动棋子的老坐标
				int old_c=distinction_arr[0]==0?distinction_arr[2]:distinction_arr[3];
				//被移动棋子的新坐标
				int new_c=distinction_arr[0]!=0?distinction_arr[2]:distinction_arr[3];
				OLED_ShowNum(1,1,old_c,1);
				OLED_ShowNum(1,1,new_c,1);
				six(new_c,old_c);
				
				recorde_distinction=0;
				goto time_return;////////////////////goto 
				
			}				
			
			best_result=computer_move(1);
			
			//调试测试
			//OLED_ShowNum(4,5,best_result,3);
			
			
			xiaqi(1,best_result);
			LED8_ON();
			
			digit_to_Mark(best_result,1);
			memcpy(last_board,board,sizeof(board));				
//...............................................................................................................................................
		
		 }
	   //break;
		 
}





