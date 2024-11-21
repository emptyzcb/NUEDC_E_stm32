#ifndef __MINMAX_H
#define __MINMAX_H

void digit_to_Mark(int digit,int chess);
int xy_to_digit(int x,int y);
void init_board(void);
int is_board_full(void);
int evaluate_board(void);
int minmax_ab(int player, int depth, int alpha, int beta,int isMaximizing);
int computer_move(int chess);

extern int board[3][3];
extern int last_board[3][3];

#endif



