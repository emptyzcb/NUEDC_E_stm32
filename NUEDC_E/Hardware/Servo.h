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

//��ʼ״̬���� �Լ�����˶��������
void Servomove(void);
void Servobegin (void);//�����,�ʼ��

void ServoMove(void);
void ServoBegin (void);//�ºͰ�,���й�������


//��ʾ����
void angelshow(void);


//�������������ƶ������
void servobCmd(int toPos);
void servofCmd(int);
void servorCmd(int);
//void servocCmd(int);


//��������˶����ƺ���
void servoCmd(void);

#endif
