const int BOARD_SIZE = 3;//棋盘大小
int board[BOARD_SIZE][BOARD_SIZE];
	 
int max(int a,int b)
{
	return a>b?a:b;
}

int min(int a,int b)
{
	return a<b?a:b;
}


/*
作用: 将二维坐标转换为一维棋盘坐标编码
参数：
	X：坐标行位置 X=0 1 2
	y：坐标列位置 Y=0 1 2
返回值:
	以九宫格为标准的棋盘坐标编码
1 2 3
4 5 6
7 8 9
*/
int xy_to_digit(int x,int y)
{
	int c;
	if(x==0&&y==0)
	{
		c=1;
	}
	else if(x==0&&y==1)
	{
		c=2;
	}
	else if(x==0&&y==2)
	{
		c=3;
	}
	else if(x==1&&y==0)
	{
		c=4;
	}
	else if(x==1&&y==1)
	{
		c=5;
	}
	else if(x==1&&y==2)
	{
		c=6;
	}
	else if(x==2&&y==0)
	{
		c=7;
	}
	else if(x==2&&y==1)
	{
		c=8;
	}
	else if(x==2&&y==2)
	{
		c=9;
	}
	else
	{
		c=15;
	}
	
	return c;


}



/*

作用: 以数字输入 并标记棋盘
参数：
	digit：数字棋盘坐标编码
	chess:想要标记的棋子种类 1表示白子 -1表示黑子
返回值:
	以九宫格为标准的棋盘坐标编码
1 2 3
4 5 6
7 8 9

*/
void digit_to_Mark(int digit,int chess)
{
	if(digit==1)
	{
		board[0][0]=chess;
	}
	else if(digit==2)
	{
		board[0][1]=chess;
	}
	else if(digit==3)
	{
		board[0][2]=chess;
	}
	else if(digit==4)
	{
		board[1][0]=chess;
	}
	else if(digit==5)
	{
		board[1][1]=chess;
	}
	else if(digit==6)
	{
		board[1][2]=chess;
	}
	else if(digit==7)
	{
		board[2][0]=chess;
	}
	else if(digit==8)
	{
		board[2][1]=chess;
	}
	else if(digit==9)
	{
		board[2][2]=chess;
	}
	


}


   //初始化棋盘
void init_board(void) 
{
    for (int i = 0; i < BOARD_SIZE; ++i) 
	{
        for (int j = 0; j < BOARD_SIZE; ++j) 
		{
            board[i][j] =0;
        }
    }
}


   //检查是否有空位，0为无 1为有
int is_board_full()
{
    for (int i = 0; i < BOARD_SIZE; ++i) 
	{
        for (int j = 0; j < BOARD_SIZE; ++j) 
		{
            if (board[i][j] == 0) 
			{
                return 0;
            }
        }
    }
	
    return 1;
}





/*

作用：检测是否有玩家获胜
参数：
	无
返回值:
	0 为无获胜状态 -10为黑棋胜 10为白棋胜

*/

int evaluate_board(void) 
	{
    //检查行列
    for (int row = 0; row < BOARD_SIZE; ++row) 
	{
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) 
		{
            if (board[row][0] == 1) return 10; //白子获胜
            else if (board[row][0] == -1) return -10;//黑子获胜
        }
        if (board[0][row] == board[1][row] && board[1][row] == board[2][row]) 
		{
            if (board[0][row] == 1) return 10;//白子获胜
            else if (board[0][row] == -1) return -10;//黑子获胜
        }
    }
    //检查对角
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
	{
        if (board[0][0] == 1) return 10;//白子获胜
        else if (board[0][0] ==-1) return -10;//黑子获胜
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
	{
        if (board[0][2] == 1) return 10;//白子获胜
        else if (board[0][2] == -1) return -10;//黑子获胜
    }
	
    return 0;
}


/*

作用：/MinMax算法的Alpha-Beta减枝版本的核心
	
参数：
	player:为最大化玩家所执棋子
	depth：搜索深度
	alpha：最大评估值 
    isMaximizing:琲sMaximizing为1表示ai为最大化玩家
返回值:

*/
int minmax_ab(int player, int depth, int alpha, int beta,int isMaximizing)
{
    int score = evaluate_board();//调用检测

    //如果游戏已经结束 或达到最大探索深度，则返回得分
    if (score == 10 || score == -10 || is_board_full() || depth == 0) 
	{
        return score;//返回得分
    }

    if (isMaximizing)//判断是否为最大化玩家
	{
        int best = -56635;//记录评估状态 令best=-65535意味着当前是最差结果
        for (int i = 0; i < BOARD_SIZE; ++i)//遍历棋盘上的每一个位置
		{
            for (int j = 0; j < BOARD_SIZE; ++j)
			{
                if (board[i][j] == 0) 
				{
                    board[i][j] = player;
                    best = max(best, minmax_ab(player, depth - 1, alpha, beta, !isMaximizing));
                    alpha = max(alpha, best);
                    board[i][j] = 0;//恢复
                    if (beta <= alpha)
					{
                        break;
                    }
                }
            }
        }
        return best;
    }
    else //不是最大玩家 找到最小值
	{
        int best = 65535;
        for (int i = 0; i < BOARD_SIZE; ++i) 
		{
			 
            for (int j = 0; j < BOARD_SIZE; ++j) 
			{
				
                if (board[i][j] == 0)
				{
					
                    board[i][j] = (player == 1) ? -1 : 1;
                    best = min(best, minmax_ab(player, depth - 1, alpha, beta, !isMaximizing));
                    beta = min(beta, best);
                    board[i][j] = 0;
                    if (beta <= alpha) 
					{
                        break;
                    }
                }
            }
        }
        return best;
    }
}

/*

作用：计算计算机最佳下棋位
参数：
	chess：形参为计算机执棋颜色 1为白 -1为黑
返回值:
	best_where:计算机最佳下棋位，以九宫格编码
1 2 3
4 5 6
7 8 9
*/
int computer_move(int chess) 
{
	int best_where;
	
    int best_val = -65535;//储存最佳评估值
    int best_move_row = -1;//储存最佳下棋位置的行
    int best_move_col = -1;//储存最佳下棋位置的列
 
    for (int i = 0; i < BOARD_SIZE; ++i) 
	{
		
        for (int j = 0; j < BOARD_SIZE; ++j) 
		{
			
            if (board[i][j] == 0) 
			{
                board[i][j] = chess;//临时放置 aa的棋子
                int move_val = minmax_ab(chess, 5, -65535, 65535, 0); //1为ai为最大化玩家
				
                board[i][j] = 0;
				 
                if (move_val > best_val) 
				{
                    best_val = move_val;
                    best_move_row = i;
                    best_move_col = j;
                }
            }
        }
    }

    //board[best_move_row][best_move_col] = chess;
	best_where=xy_to_digit(best_move_row,best_move_col);
	
	return best_where;
}


//int main(void)
//{
//	
//	OLED_Init();
//	//init_board();
//	int i=1;
//	int result;
//	while(1)
//	{
//		if(i)
//		{
//			result=computer_move(1);
//			
//			i--;
//		}
//		OLED_ShowSignedNum(1,1,result,3);
//		OLED_ShowSignedNum(2,1,M,3);
//		OLED_ShowSignedNum(3,1,W,3);
//	}
//		
//}






