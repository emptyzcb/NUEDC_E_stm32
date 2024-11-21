#ifndef __CHESS_H_
#define __CHESS_H


typedef struct 
{
	int stones_Black;//黑子
	int stones_White;//白字
	
	int Board[3][3];//棋盘坐标3*3//1为有子，0为无子
}Chess;



#endif





