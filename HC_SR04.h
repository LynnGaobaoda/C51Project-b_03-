#ifndef _HC_SR04_H_
#define _HC_SR04_H_

extern unsigned char Time;
extern unsigned char Distance;
sbit Trig=P2^0;	
sbit Echo=P2^1;

void HC_SR04_SendTrig(void);
void CountCM(void);
void HC_SR04_Init(void);


#endif
