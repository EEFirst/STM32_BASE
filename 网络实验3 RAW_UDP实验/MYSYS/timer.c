//#include "MPC563M_qs.h" /* Use proper include file like mpc5510.h or mpc5554.h */
//#include "ccp.h"
//#include "MC33905_routines.h"
//#include "typedefs.h"

////#include "sys_init.h"

////#include "global_var.h"
////#include "cal_var.h"

////#include "main.h"
//////#include "freemaster.h"
////#include "fs_gpio.h"       /* SIU pin configuration */

#include "led.h"
void task_5ms_timer_0(void)   
{
	

	
}

void task_5ms_timer_1(void)
{
	
}

void task_5ms_timer_2(void)
{
	
}

void task_5ms_timer_3(void)
{
	
}

void task_5ms_timer_4(void)
{
	
}


void task_10ms_timer_0(void)  //C_T_MAX_REST
{
 
}

void task_10ms_timer_1(void)  //C_T_MIN_ECU_REST
{

    
}

void task_10ms_timer_2(void)     //C_T_LSHPWM_UP_FAST_VB_COR
{
 
}

void task_10ms_timer_3(void)
{

}

void task_10ms_timer_4(void)
{

}
void task_10ms_timer_5(void)
{


}

void task_10ms_timer_6(void)
{
	
}
void task_10ms_timer_7(void)
{
	
}

void task_10ms_timer_8(void)
{
	
}
void task_10ms_timer_9(void)
{
	
}

//*******************100MS TIMER

void task_100ms_timer_0(void)  //  EFP
{

}

void task_100ms_timer_1(void)
{

   
}

void task_100ms_timer_2(void)   //T_CH
{

}

void task_100ms_timer_3(void)
{
	
}

void task_100ms_timer_4(void)  //暂时模拟TPS复位 成功指示。影响 POWERLAUNCH延时
{


}

void task_100ms_timer_5(void)
{
	
}

void task_100ms_timer_6(void)
{
	
}

void task_100ms_timer_7(void)
{
	
}
void task_100ms_timer_8(void)
{
	
}

void task_100ms_timer_9(void)
{
	
}

//***********************1000MS     
void task_1000ms_timer_0(void)      //powerlaunch 
{
	LED1 = ~LED1;

}

void task_1000ms_timer_1(void)  //   Art_TEG_DYN_timer_1000ms
{
  	           	

}

void task_1000ms_timer_2(void)  //Art_LSH_UP_timer_1000ms
{
	   
}

void task_1000ms_timer_3(void)   //ART_V_LSH_UP_READY_1000MS_TIMER
{ 
   
  
}

void task_1000ms_timer_4(void)
{

}

void task_1000ms_timer_5(void)    //ON_CFA_ES
{

}
void task_1000ms_timer_6(void)
{
	
}
void task_1000ms_timer_7(void)
{
	
}
void task_1000ms_timer_8(void)
{
	
}
void task_1000ms_timer_9(void)
{

}
