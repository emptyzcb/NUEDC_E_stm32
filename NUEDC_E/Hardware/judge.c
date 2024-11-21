#include "stm32f10x.h"
#include "Minmax.h"
#include <stdlib.h> 
#include <string.h> 
#include "mode_chess.h"
#include "judge.h"


int last_board[3][3];
int distinction_arr[4];

/*
	用于判断先手状态
	返回1 机器先手
	返回0 人先手
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
如果 返回值为1 则对应数组distinction_arr[0]
和distinction_arr[2]表示同一位置的不同信息
前者表示位置的棋子（白 黑 空） 后者表示坐标


*/

int judge_the_board(void)
{
//	int new_chess;//什么棋子
	int k;//逻辑变量

	
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


//void MAN_SET_Chess(void)//作用为机器检测人下棋的位置，并将该位值记录下来，并返回改位置的映射单数字坐标
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



