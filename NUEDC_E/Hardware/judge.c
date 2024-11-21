#include "stm32f10x.h"
#include "Minmax.h"
#include <stdlib.h> 
#include <string.h> 
#include "mode_chess.h"
#include "judge.h"


int last_board[3][3];
int distinction_arr[4];

/*
	�����ж�����״̬
	����1 ��������
	����0 ������
*/

int judge_the_opening(void)
{
	int num=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==0)
			{
				num++;
			}
		}
	}
	if(num==9)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


/*
��� ����ֵΪ1 ���Ӧ����distinction_arr[0]
��distinction_arr[2]��ʾͬһλ�õĲ�ͬ��Ϣ
ǰ�߱�ʾλ�õ����ӣ��� �� �գ� ���߱�ʾ����


*/

int judge_the_board(void)
{
//	int new_chess;//ʲô����
	int k;//�߼�����

	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]!=last_board[i][j])
			{
				k++;
				if(k==1)
				{
					distinction_arr[0]=board[i][j];
					distinction_arr[2]=xy_to_digit(i,j);
				}
				if(k==2)
				{
					distinction_arr[1]=board[i][j];
					distinction_arr[3]=xy_to_digit(i,j);
				}
			}
		}
	}
	if(k==2)
	{
		return 1; 
	}
	 
	return 0;


}


//void MAN_SET_Chess(void)//����Ϊ��������������λ�ã�������λֵ��¼�����������ظ�λ�õ�ӳ�䵥��������
int MAN_SET_Chess(void)
{
	int man_newchess_where;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]!=last_board[i][j])
			{
				man_newchess_where=xy_to_digit(i,j);
			}
		}
	}
	return man_newchess_where;

}



