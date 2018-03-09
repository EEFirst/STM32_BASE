#ifndef _OTHER_GLOBAL_VAR_H_
#define _OTHER_GLOBAL_VAR_H_

/********************  Dependent Include files here **********************/
#include "typedefs.h"
//#include "nc_data.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const uint16_t TDC[4];
extern const uint8_t CYC_NUM0[4];

extern const uint8_t ad_ch1[22];

extern const uint8_t ad_ch2[16]; //15 爆震

//initializated variable
extern uint8_t MTASK_p1_ID[3];
extern uint8_t MTASK_p2_ID[3];
extern uint8_t LV_QUEUEWRONG[3];
extern uint8_t MTASK_queue[3][32];

extern uint8_t count_10MS;
extern uint8_t count_100MS;
extern uint8_t count_1000MS;

extern uint16_t time5ms[21];
extern uint16_t time10ms[21];
extern uint16_t time100ms[21];
extern uint16_t time1000ms[21];


////extern uint32_t AN_ResultInMv[40];     /* ADC conversion result in millivolts */
////extern uint32_t AN_Result[40];         /* ADC conversion result  */
////extern uint16_t ad_buf[AD_CH_MAX_NUM];
//extern uint8_t  RxCANData[8];

extern uint8_t  ipnum01;   
extern uint8_t  ipnum02;       
extern uint8_t  iplienum;      
extern uint16_t ipratio01;   
extern uint16_t ipratio02;  

extern uint8_t  Lv_5ms;
extern uint8_t  Lv_10ms; 
extern uint8_t  Lv_100ms;
extern uint8_t  Lv_1000ms;
extern uint32_t PIT0Ctr;	/* Counter for eMIOS channel 0 interrupts */
extern uint8_t  lv_IO0_led_flag;
extern uint8_t  Lv_CAN_A_BUF01I_flag;
extern uint8_t  Lv_CAN_A_BUF15I_flag;

extern uint16_t task_event_flag;
extern uint32_t CAN_A_BUF01_CTR;
extern uint32_t CAN_A_BUF15_CTR;
extern uint32_t CAN_A_BUF15_CTR_inMain;
extern uint8_t  ad_ch;
extern uint8_t  ad_ch1_p;
extern uint8_t  ad_ch2_p;
extern uint8_t  ad1_ch_id_10ms;
extern uint8_t  ad2_ch_id_100ms;
extern uint8_t  map_ctr_0;
extern uint8_t  map_ctr_1;
extern uint32_t map_sum_0;
extern uint32_t map_sum_1;
extern uint8_t  soft_err_st_0;
extern uint8_t  LV_adc_busy_last;
extern uint8_t  sys_status2;
extern uint8_t  trip_cdn_state;
extern uint8_t  gr_mt_temp;
extern uint8_t  gr_mt_temp_last;
extern uint16_t ecu_ini_cnt;
//extern uint24_t tcr1_crk_now; 
//extern uint24_t tcr1_crk_last; 
extern uint8_t  count_art_temp_fun;

extern uint8_t  tq_fun_time;
extern uint8_t  tq_fun_time_100ms;
extern uint8_t  tq_fun_time_1000ms;

//从观察量中取出，以后可能不需要放在观察量
extern uint8_t  VS_PER_op;
extern uint8_t  inder_oc2;
extern uint8_t  V_IGK_BAS_N_cnt;
extern uint8_t  V_IGK_BAS_cnt;
extern uint8_t  VB_MES_P;
extern uint8_t  N_DIF_STATE;
extern uint8_t  INH_SWI_IV_OP;
extern uint8_t  PWL_DLY_CTR;          //不等0 表示有其他任务未完成 POWERLAUNCH不能结束。不能断电。
extern uint8_t  EFP_POUT_STATE_0;    //LV_IGA 对EFP的影响
extern uint8_t  EFP_POUT_STATE_1;    //VS     对EFP的影响
extern uint8_t  EFP_POUT_STATE_2;    //N      对EFP的影响
extern uint8_t  T_PU_COUNT;
extern uint8_t  PAT_INH_IV_last;
extern uint8_t  NR_SEL_CYL_CTR;
extern uint16_t INH_SWI_IV_PRE;
extern uint16_t V_IGK_MES_S;
extern uint16_t VB_MES_S;
//extern uint24_t SOI_BSW;
//extern uint24_t EOI_BSW;
//extern uint24_t TI_BSW;
//extern uint24_t TI_ADD_BSW; 		          		
//extern int24_t  tcr2_now;
extern uint32_t last_match_time_OC2;
extern uint32_t VS_GAIN_TEMP;
extern uint32_t VS_INT_TIME;
extern uint32_t VS_INT_TIME_LAST;
extern uint16_t AR_RED_AD_ADD_LAST;
extern uint16_t AR_RED_AD_FAC_LAST;
extern uint16_t AR_RED_DIF_I_REL_last;
extern uint16_t TPS_FIL_MTC_last;
extern uint16_t LAM_MV_1_old;
extern uint8_t  LAM_P_CTR_1_AD;
extern uint8_t  LAM_P_CTR_1_PL;
extern uint16_t LAM_MV_1_temp;
extern uint16_t LAM_MV_LPF_1_temp;
extern uint16_t N_TEMP_T_N_DIF_SAMPLE; 
extern uint16_t N_TEMP_T_N_DIF_RIS;
extern uint16_t CTR_T_N_DIF_SAMPLE_10MS;
extern uint16_t CTR_T_N_DIF_RIS_10MS;
extern uint16_t CTR_T_MAX_RIS_10MS;
extern uint8_t  IGA_ST_old;
extern uint8_t  ADD_WF_NUM;
extern uint8_t  VS_STATE_CFA_LAST;
extern uint8_t  STATE_CFA_IS_old;
extern uint32_t TQ_DIF_I_IS_32t;
//extern uint24_t T_SEG_AV;
//extern uint24_t T_REG_PREV;   
//extern uint24_t T_REG_AV;
extern uint8_t  N_GRD_OLD;
extern uint16_t MAF_MDL_CON_11;
extern uint16_t MAF_LAST;
extern uint16_t MAP_THR;
extern uint16_t MAP_CPS;
extern uint16_t cycnr_hys_puc;
extern uint8_t  SOI_TCO;
extern uint16_t TI_1_TEMP;
extern uint16_t ti_lgrd_ast_tco;
extern uint16_t TIB_prev;

//yabo 
extern uint8_t   LV_temp_PSTE_old;
extern uint8_t   LV_temp_LAMP_old;



//单独增加的
extern struct crank_states_t crank_states;
extern struct offset Offset1;
extern struct offset Offset2;



#ifdef __cplusplus
}
#endif

#endif  /* _OTHER_GLOBAL_VAR_H_ */

