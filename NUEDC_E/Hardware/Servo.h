#ifndef __SERVO_H
#define __SERVO_H

extern int Angleb,Anglef,Angler,flag,speed;//Anglec

void Servo_Init(void);
void Servob(int Angleb);
void Servof(int Anglef);
void Servor(int Angler);
//void Servoc(int Anglec);

void beng(int a);
void famen(int b);

void beng_ON(void);
void beng_OFF(void);
void BENG(void);
void famen_ON(void);
void famen_OFF(void);

//初始状态设置 以及舵机运动到此情况
void Servomove(void);
void Servobegin (void);//暴躁版,最开始用

void ServoMove(void);
void ServoBegin (void);//温和版,运行过程中用


//显示函数
void angelshow(void);


//以下是三个控制舵机函数
void servobCmd(int toPos);
void servofCmd(int);
void servorCmd(int);
//void servocCmd(int);


//舵机整体运动控制函数
void servoCmd(void);

#endif
