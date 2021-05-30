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
		
		//TODO �ж��ź��Ƿ�ʱ�������ʱ�����ط��ź�	��������timer0 ���ж��жϼ� ��ʱ�Ƿ����
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