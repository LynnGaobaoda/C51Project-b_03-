#include <REGX52.H>


/**
	C51单片机HC_SR04超神波芯片模块测距
	
	作者：Lynn
  */
  


sbit Trig=P2^0;	//发送信号 10us高电平
sbit Echo=P2^1;	//接收信号 高电平持续时间表示 声速时长
unsigned int Time;
unsigned int Distance;


/**
  *	@brief	HC_SR04初始化
  *	@param	无	
  *	@retval	无
  */
void HC_SR04_Init(void)
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0;	
	TH0 = 0;		
	TF0 = 0;		
	TR0 = 0;
	Trig=0;
	Echo=0;
}

/**
  *	@brief	HC_SR04发送10us高电平给Trig
  *	@param	无	
  *	@retval	无
  */
void HC_SR04_SendTrig(void)
{
	unsigned char i;
	Trig=1;
	
	i = 10;
	while (--i);
	
	Trig=0;
}

/**
  *	@brief	计算距离
  *	@param	无	
  *	@retval	无
  */
void CountCM(void)
{
	Time=TH0*256+TL0;
	TH0=0;
	TL0=0;
	Distance=(Time*17)/1000;	//s=vt/2
}