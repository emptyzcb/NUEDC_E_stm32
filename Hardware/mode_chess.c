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
int recorde_distinction;////�˴��������ƶ��������ĺ���


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


//void AI_SET_Chess(ʲô�壬������)
void AI_SET_Chass(int what,int X,int y)
{
	//..............................................
	/*�������̵�ָ��λ��
	
	.........( Control_set_chess(what,x,y); )
	
	ʵ�ִ���
	void Control_set_chess(int what,int X,int y)
	{
		//�˴�Ϊ���ƴ���
	
	}
	
	*/	
	
	
	//...........................................
	/*�����������ϼ�¼����
	
	.........( record_chess(x,y); )
	
	ʵ�ִ��룺
	void record_chess(int what,int x,int y)
	{
		board[x][y]=what;
	}
	
	*/
	Delay_s(15);
}





int MAN_result_five(void)
{
	
		if(board[0][1]==0&&board[1][0]==0&&board[1][2]==0&&board[2][1]==0)//�ж����Ƿ��µ����Խ���ĵ�
		{
			return 0;//��ʾ��û���´�
		}
		else
		{
			return 1;//���´�
		}

}




/*
   �˲�����������:
*/
void machine_open(void)
{
		    //�˺���װ��ִ����������λ����Ԫ��
			xiaqi(-1,5);//5//���ɻ�е�ۿ���
	
			digit_to_Mark(5,-1);
			memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
	
			//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
			wait_instructions();
			//GPIO_SetBits(GPIOA, GPIO_Pin_8);//�յ�ָ�� ��ʼ��ʱ ָʾ������
			request_vision();//�˺���������k210���ʹ�������
			Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
			                 //��������֮������
	
			//����Ϊ��������������λ�ã�������λֵ��¼����
			int where_num_coordinate=MAN_SET_Chess();//���������λ�ã����������飬����board[][] 
			
			
			switch (where_num_coordinate) 
			{
			case 2:
			    xiaqi(-1,7);//7
			 
			
				digit_to_Mark(7,-1);
				memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
			
				
				//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
				wait_instructions();
			    GPIO_ResetBits(GPIOA, GPIO_Pin_8);
				//GPIO_SetBits(GPIOA, GPIO_Pin_8);//�յ�ָ�� ��ʼ��ʱ ָʾ������
				request_vision();//�˺���������k210���ʹ�������
				Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
								 //��������֮������
			
			   where_num_coordinate=MAN_SET_Chess();
			   if(where_num_coordinate!=3)
			   {
				   
					 xiaqi(-1,3);//3
				   
				   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
			   }
			   else if(where_num_coordinate==3)
			   {
					 xiaqi(-1,1);//1
				   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
				   
				   digit_to_Mark(1,-1);
				   memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
				   
					//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
					wait_instructions();
				     GPIO_ResetBits(GPIOA, GPIO_Pin_8);
					request_vision();//�˺���������k210���ʹ�������
					//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ
					Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
				   
					where_num_coordinate=MAN_SET_Chess();
				   if(where_num_coordinate==4)
				   {
					 xiaqi(-1,9);//9
					 GPIO_SetBits(GPIOA, GPIO_Pin_8);	
					   //-1   1   1 
					   // 1  -1   0
					   //-1   0  -1
				   }
				   else
				   {
						  xiaqi(-1,4);
					   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
					   //-1   1  1 
					   //-1  -1  0
					   //-1   0  1
				   }
			   }

			   break;
			
			case 4:
			    xiaqi(-1,9);//9
				digit_to_Mark(9,-1);
				memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
			
			GPIO_SetBits(GPIOA, GPIO_Pin_8);	
			/*
				0  0  0
			    1 -1  0
			    0  0 -1
			*/
				//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
				wait_instructions();
			    GPIO_ResetBits(GPIOA, GPIO_Pin_8);
				//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ				//GPIO_SetBits(GPIOA, GPIO_Pin_8);//�յ�ָ�� ��ʼ��ʱ ָʾ������
				request_vision();//�˺���������k210���ʹ�������

				Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
			
			   where_num_coordinate=MAN_SET_Chess();
			   if(where_num_coordinate!=1)
			   {
					 xiaqi(-1,1);//1
				   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
				/*
				   -1  0  0
					1 -1  0
					0  0 -1
				*/
			   }
			   else if(where_num_coordinate==1)
			   {
					 xiaqi(-1,7);//7
				   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
				   digit_to_Mark(7,-1);
				   memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
		    /*
			    1  0  0
			    1 -1  0
			   -1  0 -1
			*/   
				//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
				wait_instructions();
				GPIO_ResetBits(GPIOA, GPIO_Pin_8);
				//GPIO_SetBits(GPIOA, GPIO_Pin_8);//�յ�ָ�� ��ʼ��ʱ ָʾ������
				request_vision();//�˺���������k210���ʹ�������
				//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ
				Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
				   
				   where_num_coordinate=MAN_SET_Chess();
				   if(where_num_coordinate==3)
				   {
					  xiaqi(-1,7);//7
					   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
					   // 1   0   1 
					   // 1  -1   0
					   //-1  -1  -1
				   }
				   else
				   {
					   xiaqi(-1,3);//3
					   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
					   // 1   1  -1 
					   // 1  -1   0
					   //-1   0  -1
				   }
			   }
				break;
			case 6:
			    xiaqi(-1,1);//1
				digit_to_Mark(1,-1);
				memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
			
				GPIO_SetBits(GPIOA, GPIO_Pin_8);	
				//-1  0   0
				//0  -1   1
				//0   0   0
		  
				//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
				wait_instructions();
			     GPIO_ResetBits(GPIOA, GPIO_Pin_8);
				//GPIO_SetBits(GPIOA, GPIO_Pin_8);//�յ�ָ�� ��ʼ��ʱ ָʾ������
				request_vision();//�˺���������k210���ʹ�������
				//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ
				Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
			
			   where_num_coordinate=MAN_SET_Chess();
			   if(where_num_coordinate!=9)
			   {
					 xiaqi(-1,9);//9
				     GPIO_SetBits(GPIOA, GPIO_Pin_8);	
			   }
			   else if(where_num_coordinate==9)
			   {
				   //-1  0   0
				   //0  -1   1
				   //0   0   1
					xiaqi(-1,3);//3
				   digit_to_Mark(3,-1);
				   memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
				   
					GPIO_SetBits(GPIOA, GPIO_Pin_8);	
				   //-1  0  -1
				   //0  -1   1
				   //0   0   1
					  
					//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
					wait_instructions();
				     GPIO_ResetBits(GPIOA, GPIO_Pin_8);
					//GPIO_SetBits(GPIOA, GPIO_Pin_8);//�յ�ָ�� ��ʼ��ʱ ָʾ������
					request_vision();//�˺���������k210���ʹ�������
					//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ
					Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
					   
					where_num_coordinate=MAN_SET_Chess();
				   if(where_num_coordinate==2)
				   {
				   //-1  1  -1
				   //0  -1   1
				   //0   0   1
					  xiaqi(-1,7);//7
					  GPIO_SetBits(GPIOA, GPIO_Pin_8);	
					 
				   //-1  1  -1
				   //0  -1   1
				   //-1   0  1
				   }
				   else
				   {
						 xiaqi(-1,2);//2
					     GPIO_SetBits(GPIOA, GPIO_Pin_8);	
					   //-1  -1  -1
					   //0  -1   1
					   //1   0   1
				   }
			   }
			
			

				break;
			case 8:
				 xiaqi(-1,3);
				digit_to_Mark(3,-1);
				memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
			
			
			     GPIO_SetBits(GPIOA, GPIO_Pin_8);	
				//0   0   -1
				//0  -1   0
				//0   1   0
			  
				//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
				wait_instructions();
			  GPIO_ResetBits(GPIOA, GPIO_Pin_8);
				//GPIO_SetBits(GPIOA, GPIO_Pin_8);//�յ�ָ�� ��ʼ��ʱ ָʾ������
				request_vision();//�˺���������k210���ʹ�������
				//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ
				Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
			
			    where_num_coordinate=MAN_SET_Chess();
			   if(where_num_coordinate!=7)
			   {
				   xiaqi(-1,7);//7
				   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
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
				   digit_to_Mark(9,-1);
				   memcpy(last_board,board,sizeof(board));//�洢����֮ǰ�����
				     GPIO_SetBits(GPIOA, GPIO_Pin_8);	
					//0   0  -1
					//0  -1   0
					//1   1  -1
					  
					//�˺������ڽ���Ψһָ��������װ�õ��ж�ָ��
					wait_instructions();
				    GPIO_ResetBits(GPIOA, GPIO_Pin_8);
					//GPIO_SetBits(GPIOA, GPIO_Pin_8);//�յ�ָ�� ��ʼ��ʱ ָʾ������
					request_vision();//�˺���������k210���ʹ�������
					//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ
					Awaiting_Vision();//���ڽ��ܴ��ڴ��͵���Ϣ���յ��������ʱ������ѭ��
				   
					where_num_coordinate=MAN_SET_Chess();
				   if(where_num_coordinate==6)
				   {
					//0   0  -1
					//0  -1   1
					//1   1  -1
					  xiaqi(-1,1);//1
					   GPIO_SetBits(GPIOA, GPIO_Pin_8);	
					//-1   0  -1
					//0  -1   1
					//1   1  -1
				   
				   }
				   else
				   {
						 xiaqi(-1,6);
					     GPIO_SetBits(GPIOA, GPIO_Pin_8);	
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
		best_result=computer_move(1);//����Ϊ1 ����Ϊ-1 ����Ϊ��
		OLED_ShowNum(4,5,best_result,3);
		xiaqi(1,best_result);
		LED8_ON();

		while(1)
		{
//.............................................................................................................................................
			
			wait_instructions();
			LED8_ON();
			
			request_vision();//�˺���������k210���ʹ�������
			Awaiting_Vision();//�˺��������ж��Ӿ��Ƿ񴫵�������Ϣ
			
				
			//�˴��������ƶ��������ĺ���,����1 ���ӱ��ƶ� ����0 û�б�����
			recorde_distinction=judge_the_board();
			if(recorde_distinction==1)
			{
				//���ƶ����ӵ�������
				int old_c=distinction_arr[0]==0?distinction_arr[2]:distinction_arr[3];
				//���ƶ����ӵ�������
				int new_c=distinction_arr[0]!=0?distinction_arr[2]:distinction_arr[3];
				OLED_ShowNum(1,1,old_c,1);
				OLED_ShowNum(1,1,new_c,1);
				six(old_c,new_c);
				
				recorde_distinction=0;
			}				
			
			best_result=computer_move(1);
			
			//���Բ���
			//OLED_ShowNum(4,5,best_result,3);
			
			
			xiaqi(1,best_result);
			GPIO_SetBits(GPIOA, GPIO_Pin_8);
			
			digit_to_Mark(best_result,1);
			memcpy(last_board,board,sizeof(board));				
//...............................................................................................................................................
		
		 }
	   //break;
		 
}





