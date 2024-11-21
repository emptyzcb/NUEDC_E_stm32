#include "stm32f10x.h" 
#include "Servo.h"
#include "Delay.h"
#include "Serial.h"
#include "Timer4.h"

//ʮ���ӵ�λ��
//��Ӧ����Ƕȵ���������{b , f , r }
//ִ��ʱ��ִ��b,r,Ȼ��ִ��
int zi1[3] ={90,84,119};
int zi2[3] ={74,55,46};
int zi3[3] ={64,65,98};
int zi4[3] ={75,49,68};
int zi5[3]= {133,55,69};
	
//��
int zi6[3] ={155,70,81};///
int zi7[3] ={146,76,94};///
int zi8[3] ={138,73,106};///okk
int zi9[3] ={131,85,125};///okk
int zi10[3] ={127,97,150};///

	//�Ÿ����ӵ�λ��
int ge1[3] ={73,65,96};////////
int ge2[3]= {98,64,87};//okk
int ge3[3] ={121,65,90};//ok

int ge4[3] ={81,72,113};///////////
int ge5[3] ={99,67,110};//okk
int ge6[3]= {116,71,112};/////////

int ge7[3] ={86,94,143};//ok
int ge8[3] ={99,78,137};//okk
int ge9[3] ={112,88,138};//				

	
//һ���������� �˺����������û�е�۵��˶�״̬
void servoCmd(void)//˳��(b,f,r)
	//b 0~180;f 85~108;r 65~115;
{

	 int robotmove[3][3] = {
		//b   f   r
	// 180 85-108 65-115	
		 {84,107,100},
		 {170,107,100},
		 {84,85,70}
	 };
		 
	for (int i = 0; i < 3; i++) {
	//Delay_ms(1000);
	servobCmd(robotmove[i][0]);
	Delay_ms(10);
	servofCmd(robotmove[i][1]);
	Delay_ms(10);
	servorCmd(robotmove[i][2]);
		
	//angelshow();
	}
}


////���Ӻ���,ִ�д˺���,������Ҫ�����ӵ�λ��,����ִ�н�������
void tizi (int a[])// ��������ָ��,��Ϊ�����׵�ַ
{
	//ȷ���ô�ֱλ��
	servobCmd(a[0]);
	Delay_ms(10);
	servorCmd(a[2]);
	Delay_ms(10);
	
	//��ֱ�����е��
	servofCmd(a[1]);
	Delay_ms(10);

	//������ձ� ��������
	famen_OFF();
//	beng_ON();
//	Delay_ms(1500);
//	beng_OFF();
	BENG();
	servofCmd(a[1]-15);
	if(a[2]>=145&&a[0]>=155) servofCmd(a[1]-20);
	
	Delay_ms(1000);
	//��ֱ�����е��
	servofCmd(a[1]+25);
	Delay_ms(1000);
}


////���Ӻ���,ִ�д˺���,������Ҫ���¸��λ��,����ִ�н�������,������е�۷���ԭλ
void luozi (int b[])// ��������ָ��,��Ϊ�����׵�ַ
{
	//ȷ���ô�ֱλ��
	servobCmd(b[0]);
	Delay_ms(10);
	servorCmd(b[2]);
	Delay_ms(10);
	
	//��ֱ�����е��
	servofCmd(b[1]);
	Delay_ms(500);

	//�������� ��������
//	beng_OFF();
	famen_ON();
	Delay_ms(2000);
	
	
	servofCmd(b[1]+30);
	
	famen_OFF();
//	famen_ON();
//	Delay_ms(500);
//	famen_OFF();
	
	//���س�ʼ״̬
	ServoBegin();	
}



////4,5�� ���庯��,ִ�д˺���,������Ҫ�����ӵ���ɫ�����¸�ı��,����ִ�н�����������,������е�۷���ԭλ
void xiaqi(int c,int d)//c -1Ϊ��ɫ,1Ϊ��ɫ    d�����Ÿ���
{
	int hei=1,bai=6;
	if(c==-1) switch (hei)
	{
		case 1:tizi(zi1);hei++;break;
		case 2:tizi(zi2);hei++;break;
		case 3:tizi(zi3);hei++;break;
		case 4:tizi(zi4);hei++;break;
		case 5:tizi(zi5);hei++;break;
		//default:
	}
	
	if(c==1) switch (bai)
	{
		case 6:tizi(zi6);bai++;break;
		case 7:tizi(zi7);bai++;break;
		case 8:tizi(zi8);bai++;break;
		case 9:tizi(zi9);bai++;break;
		case 10:tizi(zi10);bai++;break;
		//default:
	}

	Delay_ms(1000);
	//�����ӵĺ���	
	switch (d)
	{
		case 1:luozi(ge1);break;
		case 2:luozi(ge2);break;
		case 3:luozi(ge3);break;
		case 4:luozi(ge4);break;
		case 5:luozi(ge5);break;
		case 6:luozi(ge6);break;
		case 7:luozi(ge7);break;
		case 8:luozi(ge8);break;
		case 9:luozi(ge9);break;
		//default:
	}
}
	
////1,2�� ���庯��,ִ�д˺���,������Ҫ�����ӵ���ɫ�����¸�ı��,����ִ�н�����������,������е�۷���ԭλ
void yiqi(int e,int f)//e�������Ŀ���    f�����Ÿ���
{
	switch (e)
	{
		case 1:tizi(zi1);break;
		case 2:tizi(zi2);break;
		case 3:tizi(zi3);break;
		case 4:tizi(zi4);break;
		case 5:tizi(zi5);break;
		case 6:tizi(zi6);break;
		case 7:tizi(zi7);break;
		case 8:tizi(zi8);break;
		case 9:tizi(zi9);break;
		case 10:tizi(zi10);break;
		//default:
	}

	Delay_ms(1000);
	//�����ӵĺ���	
	switch (f)
	{
		case 1:luozi(ge1);break;
		case 2:luozi(ge2);break;
		case 3:luozi(ge3);break;
		case 4:luozi(ge4);break;
		case 5:luozi(ge5);break;
		case 6:luozi(ge6);break;
		case 7:luozi(ge7);break;
		case 8:luozi(ge8);break;
		case 9:luozi(ge9);break;
		//default:
	}
}	
	
////6�� ��以������,ִ�д˺���,������Ӽ��������������,����ִ�н�����������,������е�۷���ԭλ
void six(int g,int h)//g��������ô��   f�����Ÿ���
{
	switch (g)
	{
		case 1:tizi(ge1);break;
		case 2:tizi(ge2);break;
		case 3:tizi(ge3);break;
		case 4:tizi(ge4);break;
		case 5:tizi(ge5);break;
		
		case 6:tizi(ge6);break;
		case 7:tizi(ge7);break;
		case 8:tizi(ge8);break;
		case 9:tizi(ge9);break;
		//default:
	}

	Delay_ms(1000);
	//�����ӵĺ���	
	switch (h)
	{
		case 1:luozi(ge1);break;
		case 2:luozi(ge2);break;
		case 3:luozi(ge3);break;
		case 4:luozi(ge4);break;
		case 5:luozi(ge5);break;
		
		case 6:luozi(ge6);break;
		case 7:luozi(ge7);break;
		case 8:luozi(ge8);break;
		case 9:luozi(ge9);break;
		//default:
	}
}	

	
	
