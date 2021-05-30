#include <REGX52.H>
#include "HC_SR04.h"
#include "LCD1602.h"
#include "Delay.h"

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Distance:");
	HC_SR04_Init();
	
	while(1){
		HC_SR04_SendTrig();
		
		//TODO 判断信号是否超时，如果超时，则重发信号	可以利用timer0 的中断判断即 计时是否溢出
		//
		
		while(!Echo);
		TR0=1;
		while(Echo);
		TR0=0;
		CountCM();
		
		LCD_ShowNum(2,1,Distance,3);
		Delay(1000);
	}	
}