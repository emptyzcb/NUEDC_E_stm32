#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>

//extern uint8_t Serial_TxPacket0[];
extern uint8_t Serial_RxPacket0[];
extern uint8_t Serial2_RxPacket[];
extern int a[9][9];
extern int key,TI,FANG,start,Awaiting_Vision_judge,mode_out,Mode;

extern char Serial_RxPacket[];
extern uint8_t Serial_RxFlag;
extern uint8_t Serial2_RxFlag;

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);

void Serial2_SendByte(uint8_t Byte);

//void Serial_SendPacket(void);//发数据包
uint8_t Serial_GetRxFlag(void);
uint8_t Serial2_GetRxFlag(void);

#endif
