#ifndef __SERVOMOVE_H
#define __SERVOMOVE_H
extern int zi1[3];
extern int zi2[3] ;
extern int zi3[3] ;
extern int zi4[3];
extern int zi5[3];
	
extern int zi6[3];
extern int zi7[3];
extern int zi8[3];
extern int zi9[3];
extern int zi10[3];

	//九个格子的位置
extern int ge1[3];
extern int ge2[3];
extern int ge3[3];
extern int ge4[3];
extern int ge5[3];
extern int ge6[3];
extern int ge7[3];
extern int ge8[3];
extern int ge9[3];	


void servoCmd(void);
void tizi (int a[]);
void luozi (int b[]);
void xiaqi(int c,int d)	;
void yiqi(int e,int f);
void six(int g,int h);

#endif

