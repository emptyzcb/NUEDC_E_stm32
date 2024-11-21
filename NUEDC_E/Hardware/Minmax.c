const int BOARD_SIZE = 3;//���̴�С
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
����: ����ά����ת��Ϊһά�����������
������
	X��������λ�� X=0 1 2
	y��������λ�� Y=0 1 2
����ֵ:
	�ԾŹ���Ϊ��׼�������������
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

����: ���������� ���������
������
	digit�����������������
	chess:��Ҫ��ǵ��������� 1��ʾ���� -1��ʾ����
����ֵ:
	�ԾŹ���Ϊ��׼�������������
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


   //��ʼ������
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


   //����Ƿ��п�λ��0Ϊ�� 1Ϊ��
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

���ã�����Ƿ�����һ�ʤ
������
	��
����ֵ:
	0 Ϊ�޻�ʤ״̬ -10Ϊ����ʤ 10Ϊ����ʤ

*/

int evaluate_board(void) 
	{
    //�������
    for (int row = 0; row < BOARD_SIZE; ++row) 
	{
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) 
		{
            if (board[row][0] == 1) return 10; //���ӻ�ʤ
            else if (board[row][0] == -1) return -10;//���ӻ�ʤ
        }
        if (board[0][row] == board[1][row] && board[1][row] == board[2][row]) 
		{
            if (board[0][row] == 1) return 10;//���ӻ�ʤ
            else if (board[0][row] == -1) return -10;//���ӻ�ʤ
        }
    }
    //���Խ�
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
	{
        if (board[0][0] == 1) return 10;//���ӻ�ʤ
        else if (board[0][0] ==-1) return -10;//���ӻ�ʤ
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
	{
        if (board[0][2] == 1) return 10;//���ӻ�ʤ
        else if (board[0][2] == -1) return -10;//���ӻ�ʤ
    }
	
    return 0;
}


/*

���ã�/MinMax�㷨��Alpha-Beta��֦�汾�ĺ���
	
������
	player:Ϊ��������ִ����
	depth���������
	alpha���������ֵ 
    isMaximizing:�isMaximizingΪ1��ʾaiΪ������
����ֵ:

*/
int minmax_ab(int player, int depth, int alpha, int beta,int isMaximizing)
{
    int score = evaluate_board();//���ü��

    //�����Ϸ�Ѿ����� ��ﵽ���̽����ȣ��򷵻ص÷�
    if (score == 10 || score == -10 || is_board_full() || depth == 0) 
	{
        return score;//���ص÷�
    }

    if (isMaximizing)//�ж��Ƿ�Ϊ������
	{
        int best = -56635;//��¼����״̬ ��best=-65535��ζ�ŵ�ǰ�������
        for (int i = 0; i < BOARD_SIZE; ++i)//���������ϵ�ÿһ��λ��
		{
            for (int j = 0; j < BOARD_SIZE; ++j)
			{
                if (board[i][j] == 0) 
				{
                    board[i][j] = player;
                    best = max(best, minmax_ab(player, depth - 1, alpha, beta, !isMaximizing));
                    alpha = max(alpha, best);
                    board[i][j] = 0;//�ָ�
                    if (beta <= alpha)
					{
                        break;
                    }
                }
            }
        }
        return best;
    }
    else //���������� �ҵ���Сֵ
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

���ã����������������λ
������
	chess���β�Ϊ�����ִ����ɫ 1Ϊ�� -1Ϊ��
����ֵ:
	best_where:������������λ���ԾŹ������
1 2 3
4 5 6
7 8 9
*/
int computer_move(int chess) 
{
	int best_where;
	
    int best_val = -65535;//�����������ֵ
    int best_move_row = -1;//�����������λ�õ���
    int best_move_col = -1;//�����������λ�õ���
 
    for (int i = 0; i < BOARD_SIZE; ++i) 
	{
		
        for (int j = 0; j < BOARD_SIZE; ++j) 
		{
			
            if (board[i][j] == 0) 
			{
                board[i][j] = chess;//��ʱ���� aa������
                int move_val = minmax_ab(chess, 5, -65535, 65535, 0); //1ΪaiΪ������
				
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






