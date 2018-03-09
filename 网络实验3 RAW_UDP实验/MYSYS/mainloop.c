//#include "MPC563M_qs.h" /* Use proper include file like mpc5510.h or mpc5554.h */
//#include "ccp.h"
//#include "MC33905_routines.h"
//#include "ndata.h"
////#include "global_var.h"
//#include "cal_var.h"

//temp
#include "typedefs.h"
#include "other_global_var.h"
#include "global_fun.h"
#include "led.h"
//#include "main.h"
//#include "freemaster.h"
//#include "fs_gpio.h"       /* SIU pin configuration */
//#include "etpu_util.h"     /* General C Functions for the eTPU */
//#include "etpu_gct.h"      /* eTPU configuration */
//#include "etpu_crank.h"    /* eTPU CRANK API */
//#include "etpu_cam.h"      /* eTPU CAM API */
//#include "etpu_spark.h"    /* eTPU SPARK API */
//#include "etpu_fuel.h"     /* eTPU FUEL API */
//#include "etpu_inj.h"      /* eTPU INJ API */
//#include "etpu_knock.h"    /* eTPU KNOCK API */
//#include "etpu_tg.h"       /* eTPU TG API */
////yabo
//#include "etpu_pwm.h"
//#include "etpu_oc.h" 
//#include "flash_op.h"


//uint8_t MTASK_p1_ID[3]={0};
//uint8_t MTASK_p2_ID[3]={0};
//uint8_t LV_QUEUEWRONG[3]={0};
//uint8_t MTASK_queue[3][32]={0};

//uint8_t count_10MS=2;
//uint8_t count_100MS=20;
//uint8_t count_1000MS=200;

//uint16_t time5ms[21]={0};
//uint16_t time10ms[21]={0};
//uint16_t time100ms[21]={0};
//uint16_t time1000ms[21]={0};


void ecu_main_enter(void);
void Art_conf(void);



void (*const MTASK_fun[48])(void) = {
   task_bas00,
   task_bas01,
   task_bas02,
   task_bas03,
   task_bas04,
   task_bas05,
   task_bas06,
   task_bas07,
   task_bas08,
   task_bas09,
   task_bas0A,
   task_bas0B,
   task_bas0C,
   task_bas0D,
   task_bas0E,
   task_bas0F,
   task_bas10,
   task_bas11,
   task_bas12,
   task_bas13,
   task_bas14,
   task_bas15,
   task_bas16,
   task_bas17,
   task_bas18,
   task_bas19,
   task_bas1A,
   task_bas1B,
   task_bas1C,
   task_bas1D,
   task_bas1E,
   task_bas1F,
   task_bas20,
   task_bas21,
   task_bas22,
   task_bas23,
   task_bas24,
   task_bas25,
   task_bas26,
   task_bas27,
   task_bas28,
   task_bas29,
   task_bas2A,
   task_bas2B,
   task_bas2C,
   task_bas2D,
   task_bas2E,
   task_bas2F,
  };

	
	
void (*const task_event_table[6])(void)={
	task_event_0,
	task_event_1,
	task_event_2,
    task_event_3,
    task_event_4,
    task_event_5,
	};
	
void (*const task_5ms[5])(void)={
	task_5ms_timer_0,
	task_5ms_timer_1,
	task_5ms_timer_2,
	task_5ms_timer_3,
	task_5ms_timer_4,
	};

void (*const task_10ms[10])(void)={
	task_10ms_timer_0,
	task_10ms_timer_1,
	task_10ms_timer_2,
	task_10ms_timer_3,
	task_10ms_timer_4,
	task_10ms_timer_5,
	task_10ms_timer_6,
	task_10ms_timer_7,
	task_10ms_timer_8,
	task_10ms_timer_9,	
	};
	
void (*const task_100ms[10])(void)={
	task_100ms_timer_0,
	task_100ms_timer_1,
	task_100ms_timer_2,
	task_100ms_timer_3,
	task_100ms_timer_4,
	task_100ms_timer_5,
	task_100ms_timer_6,
	task_100ms_timer_7,
	task_100ms_timer_8,
	task_100ms_timer_9,
	};
	
void (*const task_1000ms[10])(void)={
	task_1000ms_timer_0,
	task_1000ms_timer_1,
	task_1000ms_timer_2,
	task_1000ms_timer_3,
	task_1000ms_timer_4,
	task_1000ms_timer_5,
	task_1000ms_timer_6,
	task_1000ms_timer_7,
	task_1000ms_timer_8,
	task_1000ms_timer_9,	
	};	
	
	
	void ini_main_loop(void)
{
	uint8_t i,j;
	

for(i=0;i<3;i++) 
{
  MTASK_p1_ID[i]=0;
  MTASK_p2_ID[i]=0;
  LV_QUEUEWRONG[i]=0;
  for(j=0;j<32;j++)     
  {
    MTASK_queue[i][j]=0;
   }
}
                               
task_event_flag=0;;                 
                                  
count_10MS=2;                 
count_100MS=20;                 
count_1000MS=200;                 
  
  for(i=0;i<21;i++)
  {               
   time5ms[i]=0;                 
   time10ms[i]=0;                 
   time100ms[i]=0;                 
   time1000ms[i]=0;      
  }  
  	ecu_main_enter();
	//time1000ms[0] = 1;
  	     
}    
   
void task_timer_fun(void);
void task_event_fun(void);
void task_queue_fun(void);

void task_add_fun(uint8_t task_num,uint8_t task_queue_num)
{
	
	task_queue_num=task_queue_num-1;
                                *(MTASK_queue[task_queue_num] + MTASK_p2_ID[task_queue_num]) = task_num;
			                   MTASK_p2_ID[task_queue_num] = (MTASK_p2_ID[task_queue_num]+ 1) & 0x1F;  ////????????????
		            	        if(MTASK_p2_ID[task_queue_num] == MTASK_p1_ID[task_queue_num])
			                    	{ 
					                      LV_QUEUEWRONG[0]=1;
					                      MTASK_p2_ID[task_queue_num] = (MTASK_p2_ID[task_queue_num] + 1) & 0x1F;
			                       }		                       
			                       
}

void ecu_main_loop(void)
{           
  while(1) 
  {     

//test_cpp_fun();
           //****************5ms???????????????????????????
               task_timer_fun();
            //****************event?¼???????
               task_event_fun();
            //****************???????????
               task_queue_fun();
  }
}



void task_timer_fun(void)
{
//	uint8_t temp_i=0;
	uint8_t temp_i5=0;
	uint8_t temp_i10=0;
	uint8_t temp_i100=0;
	uint8_t temp_i1000=0;

		if(Lv_5ms==1)
	          {
	             Lv_5ms=0;
	             //
	             task_add_fun(0x1c,0x01);
	             
	            
	             
	              
	
              //****************5ms????K??????
		            for(temp_i5=0;temp_i5<5;temp_i5++)
		          {
                     if(time5ms[temp_i5]!=0)       //?ö???????
                                      {
									       time5ms[temp_i5]--;
 								          if(time5ms[temp_i5]==0)
								           {
                                             (*(task_5ms+temp_i5))();
								           }
								          
									  }
			         }
			         //************5ms????????? ??'10MS??????
			                              
                  if((--count_10MS)==0)
                  	{
                  		count_10MS=2;
                  		//************????10ms???????
                  	//temp	
                   //   fs_etpu_cam_get_states(&cam_instance, &cam_states);
                     //fs_etpu_cam_copy_log(&cam_instance, &etpu_cam_log[0]);
                //test_int32_001=eTPU->TB1R_A.R;
                  		
//             fs_etpu_crank_get_states(&crank_instance, &crank_states);      		
//                  		
//    test_int8_001 =sys_status2;
    


 //test_int8_004=N_GRD;
 //test_int8_003=PWL_DLY_CTR;
 //test test_int16_001 = time1000ms[0];
 
//   test_int8_001 = C_test_int8_001; //yabo add
   //test_int8_002 = C_test_int8_002; //yabo add
   /* test
   switch(C_test_int8_003)
   {
   	case 1:
   		TCO_AD = C_test_int8_004;
   		break;
   	case 2:
   		test_int32_001 = *(uint32_t *)(C_test_int32_001);
   		test_int32_002 = *(uint32_t *)(C_test_int32_002);   		
   		break;   		
   	default:
   		break;	   	
   }
 test */


     
       
                         task_add_fun(0x1d,0x01);
                         task_add_fun(0x00,0x01);  //????00????
                  	//	LV_CYC_LIM10MS_SYS_STATE=1;
                  		task_add_fun(0x0C,0x01);  //????0C????
                  		task_add_fun(0x0D,0x01);  //????0D???? Art_tq_mang
                  	
                  		  		task_add_fun(0x0e,0x01);  //????0D????   art_iga
                  		 
//                  		if(LV_ES==0)
//                  		{
//                  			task_add_fun(0x09,0x01); //Art_eng_state_10ms	
//                  			task_add_fun(0x0b,0x01); //art_tps_sp_10ms	
//                  		}
//                  		task_add_fun(0x0F,0x02);   //art_LAM_main
//                  		task_add_fun(0x08,0x02); //art_is_control
                  	
                     	task_add_fun(0x21,0x02);  //????21???? //VVT_10MS
                  		 //****************10ms????K??????
                  		                            //****************10ms????K??????
		                    for(temp_i10=0;temp_i10<10;temp_i10++)
		                    {
                                  if(time10ms[temp_i10]!=0)       //?ö???????
                                      {
									                       time10ms[temp_i10]--;
 								                         if(time10ms[temp_i10]==0)
								                           {
                                  (*(task_10ms+temp_i10))();
								                           }
								          
									                    }
			                }
                  	}   //if((--count_10MS)==0)
                  	//*************10ms????????? ??'100MS??????
                  	       if((--count_100MS)==0)  //100Ms ????
                        {
                           count_100MS=20;
                           task_event_flag|=0x01;
                     
                           //************????100ms???????
                           	task_add_fun(0x01,0x01);  //????01????
			                       
			                  task_add_fun(0x1e,0x01);
			                  
			                  task_add_fun(0x07,0x03);  //????07????????3.
			                  
			                  task_add_fun(0x10,0x02);  //
			                  
			                  task_add_fun(0x11,0x02);  //  art_cp
			                  
			                 
                           
                           //****************100ms????K??????
		                       for(temp_i100=0;temp_i100<10;temp_i100++)
		                       {
                                if(time100ms[temp_i100]!=0)       //?ö???????
                                      {                                        
									                     time100ms[temp_i100]--;
 								                         if(time100ms[temp_i100]==0)
								                          {
                                             (*(task_100ms+temp_i100))();
								                           }
								          
									                   }
			                   }
                       } //if((--count_100MS)==0)
                        //*************100ms????????? ??'1000MS??????       
                                if((--count_1000MS)==0)  //1000Ms ????
                                   {
                                     count_1000MS=200;
																		  task_add_fun(0x0a,0x01); 
                                      //************????1000ms???????
                                        task_add_fun(0x02,0x01);  //????02????    
                                
                                         task_add_fun(0x09,0x02);
                                          
                                       //****************1000ms????K??????
		                                 for(temp_i1000=0;temp_i1000<10;temp_i1000++)
		                                  {
                                               if(time1000ms[temp_i1000]!=0)       //?ö???????
                                                {
									                                   time1000ms[temp_i1000]--;
 								                                     if(time1000ms[temp_i1000]==0)
								                    {
                                                       (*(task_1000ms+temp_i1000))();
								                    }
								          
									                     }
			                             }
						            }  //*if((--count_1000MS)==0)  //1000Ms ????        
            } //if(Lv_5ms==1)
	
}
void task_event_fun(void)
{
uint16_t temp_task_mask=0x01;
uint16_t temp_task_num=0;
                        while((task_event_flag!= 0)&&(temp_task_num<6))  //? BIT_S58  ??j6??????
                    {
                 
                        	  if(task_event_flag&temp_task_mask)
                        		{
                        		
                        	                            
                        			 task_event_flag=task_event_flag&(~temp_task_mask);
                        			 if(temp_task_num<6)          //??jh??6??????
                        			 	{
                        		     	task_event_table[temp_task_num]();
                        		      }
                        		  	
                        		}
                        
                                   	temp_task_mask=temp_task_mask*2;
                        	    	temp_task_num++;                       			
                    
                        	
                   } 
}

void task_queue_fun(void)
{       
        uint8_t  i;
		uint8_t  temp_fun_id;
		

              i=0; 
              while(i<3)
              {
              	 if(MTASK_p2_ID[i] != MTASK_p1_ID[i])
                {  
                				  
               temp_fun_id=*(MTASK_queue[i] + MTASK_p1_ID[i]);
               MTASK_p1_ID[i] = (MTASK_p1_ID[i] + 1) & 0x1F;

	      	      MTASK_fun[temp_fun_id]();
	      	      i=3;
                }
                else
                {
                 	i++;               	
                }

              }
       
    /****
    
                  	 if(MTASK_p2_ID[0] != MTASK_p1_ID[0])
                {  
                				  
               temp_fun_id=*(MTASK_queue[0] + MTASK_p1_ID[0]);
               MTASK_p1_ID[0] = (MTASK_p1_ID[0] + 1) & 0x1F;

	      	      MTASK_fun[temp_fun_id]();
	      	     
                }
                else    if(MTASK_p2_ID[1] != MTASK_p1_ID[1])
                {  
                				  
               temp_fun_id=*(MTASK_queue[1] + MTASK_p1_ID[1]);
               MTASK_p1_ID[1] = (MTASK_p1_ID[1] + 1) & 0x1F;

	      	      MTASK_fun[temp_fun_id]();
	      	      
                } 
                else    if(MTASK_p2_ID[2] != MTASK_p1_ID[2])
                {  
                				  
               temp_fun_id=*(MTASK_queue[2] + MTASK_p1_ID[2]);
               MTASK_p1_ID[2] = (MTASK_p1_ID[2] + 1) & 0x1F;

	      	      MTASK_fun[temp_fun_id]();
	      	     
                }   
                ********/                   
}


void ecu_main_enter(void)
{
//    //lq_xg_01_01
//   Art_conf();
//   //***************????????????l???????INI =0
//   
//   
//   
//   while(Lv_5ms!=1)	
//   {
//   	
//   }
//	 task_add_fun(0x05,0x01);   //????05????????1
//	 task_add_fun(0x0c,0x01);   //????0C????????1
//	
	
}

void Art_conf(void)
{
	
	
	
}







void task_bas04(void)
{
	
}

void task_bas05(void)
{


//	task_add_fun(0x06,0x01);   //????06????????1
}



void task_bas0C(void)  
{
  //yabo 
//  SW_in_ini();
//  
//  ART_SYS_STATE();
}

void task_bas00(void)
{
	
}

void task_bas01(void)
{
	
}

void task_bas02(void)
{
	
}

void task_bas03(void)
{
	
}

void task_bas06(void)
{
	
}

void task_bas07(void)
{
	
}

void task_bas08(void)
{
	
}

void task_bas09(void)
{
	
}

void task_bas0A(void)
{
		LED1=~LED1;
}

void task_bas0B(void)
{
	
}

void task_bas0D(void)
{
	
}

void task_bas0E(void)
{
	
}

void task_bas0F(void)
{
	
}

void task_bas10(void)
{
	
}

void task_bas11(void)
{
	
}

void task_bas1A(void)
{
	
}

void task_bas12(void)
{
	
}
void task_bas13(void)
{
	
}
void task_bas14(void)
{
	
}
void task_bas15(void)
{
	
}
void task_bas16(void)
{
	
}
void task_bas17(void)
{
	
}
void task_bas18(void)
{
//	ART_SYS_STATE();
}
void task_bas19(void)
{
	
}

void task_bas1B(void)
{

}
void task_bas1C(void)  //5MS DAQ  TEST
{
		//ccpDaq(3);
}
void task_bas1D(void) //10MS DAQ  TEST
{
	 
}
void task_bas1E(void) //100MS DAQ  TEST
{


}
void task_bas1F(void)
{
	
}

void   task_bas20(void)
{
	
}

void   task_bas22(void)  
{
	
}

void   task_bas21(void)  
{
	
}

void   task_bas2B(void)  
{
	
}

void   task_bas2C(void)  
{
	
}

void   task_bas2D(void)  
{
	
}

void   task_bas2E(void)  
{
	
}

void   task_bas23(void)
{
	
}

void   task_bas24(void)
{
	
}

void   task_bas25(void)
{
	
}

void   task_bas26(void)
{
	
}

void   task_bas27(void)
{
	
}

void   task_bas28(void)
{
	
}

void   task_bas29(void)
{
	
}

void   task_bas2A(void)
{
	
}

void   task_bas2F(void)
{
	
}

void task_event_0(void)
{
     	
}

void task_event_1(void)
{
     	
}

void task_event_2(void)
{
	//ccpCommand(RxCANData);	
}

void task_event_3(void)   //cyc ????  
{
//
// 
//	 task_add_fun(0x03,0x01);   //????03????????1
//      
//    if(LV_CYC_LIM10MS_SYS_STATE==0)
//    {
//   	  task_add_fun(0x18,0x01);   //????0X18????????1    
//   	   	
//    }
//    task_add_fun(0x1A,0x01);    //????0X1A????????1  ART_TI.
//    task_add_fun(0x2B,0x01);    //????0X1A????????1  ART_TI_COP.
}

void task_event_4(void)  //VVT_IN
{
     
//	  fs_etpu_crank_get_states(&crank_instance, &crank_states);

//	   Task_VVT_360CRKFUN01();
//	   Task_VVT_360CRKFUN02();
}

void task_event_5(void)  //VVT_EX
{
	
}
