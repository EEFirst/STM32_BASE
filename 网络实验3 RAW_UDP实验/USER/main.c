#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	
#include "timer.h"
#include "sram.h"
#include "malloc.h"
#include "string.h"
#include "usmart.h"	
#include "lwip/netif.h"
#include "lwip_comm.h"
#include "lwipopts.h"
#include "udp_demo.h"
/************************************************
 ALIENTEK战舰STM32开发板LWIP实验
 基于RAW API的UDP实验
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

extern void ecu_main_loop(void);
extern void ini_main_loop(void);

extern u8 udp_demo_flag;  //UDP 测试全局状态标记变量
//加载UI
//mode:
//bit0:0,不加载;1,加载前半部分UI
//bit1:0,不加载;1,加载后半部分UI
void lwip_test_ui(u8 mode)
{
	u8 speed;
	u8 buf[30]; 
	POINT_COLOR=RED;
	if(mode&1<<0)
	{
		LCD_Fill(30,30,lcddev.width,110,WHITE);	//清除显示
		LCD_ShowString(30,30,200,16,16,"WARSHIP STM32F103");
		LCD_ShowString(30,50,200,16,16,"Ethernet lwIP Test");
		LCD_ShowString(30,70,200,16,16,"ATOM@ALIENTEK");
		LCD_ShowString(30,90,200,16,16,"2015/3/21"); 	
	}
	if(mode&1<<1)
	{
		LCD_Fill(30,110,lcddev.width,lcddev.height,WHITE);	//清除显示
		LCD_ShowString(30,110,200,16,16,"lwIP Init Successed");
		if(lwipdev.dhcpstatus==2)sprintf((char*)buf,"DHCP IP:%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);//打印动态IP地址
		else sprintf((char*)buf,"Static IP:%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);//打印静态IP地址
		LCD_ShowString(30,130,210,16,16,buf); 
		speed=DM9000_Get_SpeedAndDuplex();//得到网速
		if(speed&1<<1)LCD_ShowString(30,150,200,16,16,"Ethernet Speed:10M");
		else LCD_ShowString(30,150,200,16,16,"Ethernet Speed:100M");
		LCD_ShowString(30,170,200,16,16,"PORT: 8089");
		LCD_ShowString(30,170,200,16,16,"KEY0: Send data");
	}
}

int main(void)
{	 
//	u8 key;
//	delay_init();	    	//延时函数初始化	  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	uart_init(115200);	 	//串口初始化为115200
// 	LED_Init();			    //LED端口初始化
//	LCD_Init();				//初始化LCD
//	KEY_Init();	 			//初始化按键
//	TIM3_Int_Init(1000,719);//定时器3频率为100hz
// 	usmart_dev.init(72);	//初始化USMART		
// 	FSMC_SRAM_Init();		//初始化外部SRAM
//	my_mem_init(SRAMIN);		//初始化内部内存池
//	my_mem_init(SRAMEX);		//初始化外部内存池
//	POINT_COLOR = RED; 		
//	lwip_test_ui(1);		//加载前半部分UI		    
//	while(lwip_comm_init()) //lwip初始化
//	{
//		LCD_ShowString(30,110,200,20,16,"LWIP Init Falied!");
//		delay_ms(1200);
//		LCD_Fill(30,110,230,130,WHITE); //清除显示
//		LCD_ShowString(30,110,200,16,16,"Retrying...");  
//	}
//	LCD_ShowString(30,110,200,20,16,"LWIP Init Success!");
// 	LCD_ShowString(30,130,200,16,16,"DHCP IP configing...");
//#if LWIP_DHCP   //使用DHCP
//	while((lwipdev.dhcpstatus!=2)&&(lwipdev.dhcpstatus!=0XFF))//等待DHCP获取成功/超时溢出
//	{
//		lwip_periodic_handle();	//LWIP内核需要定时处理的函数
//		lwip_pkt_handle();	
//	}
//#endif
//	lwip_test_ui(2);		//加载后半部分UI 
//	delay_ms(500);			//延时1s
//	delay_ms(500);
//	udp_demo_test();  		//UDP 模式
//  	while(1)
//	{	
//		key = KEY_Scan(0);
//		if(key == KEY1_PRES)		//按KEY1键建立连接
//		{
//			if((udp_demo_flag & 1<<5)) printf("UDP连接已经建立,不能重复连接\r\n");	//如果连接成功,不做任何处理
//			else udp_demo_test();		//当断开连接后,调用udp_demo_test()函数
//		}
//		delay_ms(10);
//	}
	LED_Init();
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIM4_Int_Init(49,7199);//10Khz的计数频率，计数到5000为500ms  
	ini_main_loop();
	ecu_main_loop();
}
