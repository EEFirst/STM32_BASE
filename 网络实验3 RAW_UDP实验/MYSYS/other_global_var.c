#include "other_global_var.h"
//#include "cal_var.h"
//#include "etpu_gct.h"  //TDC1_DEG

//*********************const********************** 
//const uint16_t TDC[4] = {TDC1_DEG, TDC2_DEG, TDC3_DEG, TDC4_DEG};
//const uint8_t CYC_NUM0[4]={2,0,3,1};

////const uint8_t ad_ch1[22]={VB_AD_CHAN, V_IGK_AD_CHAN, TPS_1_AD_CHAN, TPS_2_AD_CHAN, PV_1_AD_CHAN, PV_2_AD_CHAN,  MAP_AD_CHAN, MAP_UP_AD_CHAN,IGA_AD_CHAN, VLS_UP_AD_CHAN, VLS_DOWN_AD_CHAN,VOUT1_AD_CHAN, VOUT2_AD_CHAN, TCO_AD_CHAN, TIA_AD_CHAN, FTL_AD_CHAN, TACE_AD_CHAN, KNKS_AD_CHAN, ACREQ_AD_CHAN, CRU_BAS_AD_CHAN, ACP_AD_CHAN, ALTER_AD_CHAN};
//const uint8_t ad_ch1[22]={VB_AD_CHAN, V_IGK_AD_CHAN, TPS_1_AD_CHAN, TPS_2_AD_CHAN, PV_1_AD_CHAN, PV_2_AD_CHAN,  MAP_AD_CHAN, MAP_UP_AD_CHAN,IGA_AD_CHAN, VLS_UP_AD_CHAN, VLS_DOWN_AD_CHAN, ACREQ_AD_CHAN, VOUT1_AD_CHAN, VOUT2_AD_CHAN, TCO_AD_CHAN, TIA_AD_CHAN, FTL_AD_CHAN, TACE_AD_CHAN, KNKS_AD_CHAN, CRU_BAS_AD_CHAN, ACP_AD_CHAN, ALTER_AD_CHAN};

//const uint8_t ad_ch2[16]={0, 15, 2, 0, 4, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 0,}; //15 爆震



//initializated variable
uint8_t MTASK_p1_ID[3] = {0};
uint8_t MTASK_p2_ID[3] = {0};
uint8_t LV_QUEUEWRONG[3] = {0};
uint8_t MTASK_queue[3][32] = {0};

uint8_t count_10MS=2;
uint8_t count_100MS=20;
uint8_t count_1000MS=200;

uint16_t time5ms[21] = {0};
uint16_t time10ms[21] = {0};
uint16_t time100ms[21] = {0};
uint16_t time1000ms[21] = {0};


uint32_t AN_ResultInMv[40] = {0};     /* ADC conversion result in millivolts */
uint32_t AN_Result[40] = {0};         /* ADC conversion result  */
//uint16_t ad_buf[AD_CH_MAX_NUM] = {0};
uint8_t  RxCANData[8] = {0};

uint8_t  ipnum01=0;   
uint8_t  ipnum02=0;       
uint8_t  iplienum=0;      
uint16_t ipratio01=0;   
uint16_t ipratio02=0;  

uint8_t  Lv_5ms = 0;
uint8_t  Lv_10ms = 0; 
uint8_t  Lv_100ms = 0;
uint8_t  Lv_1000ms = 0;
uint32_t PIT0Ctr = 0;	/* Counter for eMIOS channel 0 interrupts */
uint8_t  lv_IO0_led_flag = 0;
uint8_t  Lv_CAN_A_BUF01I_flag = 0;
uint8_t  Lv_CAN_A_BUF15I_flag = 0;

uint16_t task_event_flag = 0;
uint32_t CAN_A_BUF01_CTR = 0;
uint32_t CAN_A_BUF15_CTR = 0;
uint32_t CAN_A_BUF15_CTR_inMain = 0;
uint8_t  ad_ch = 0;
uint8_t  ad_ch1_p = 0;
uint8_t  ad_ch2_p = 0;
uint8_t  ad1_ch_id_10ms = 0;
uint8_t  ad2_ch_id_100ms = 0;
uint8_t  map_ctr_0 = 0;
uint8_t  map_ctr_1 = 0;
uint32_t map_sum_0 = 0;
uint32_t map_sum_1 = 0;
uint8_t  soft_err_st_0 = 0;
uint8_t  LV_adc_busy_last = 0;
uint8_t  sys_status2 = 0;
uint8_t  trip_cdn_state = 0;
uint8_t  gr_mt_temp = 0;
uint8_t  gr_mt_temp_last = 0;
uint16_t ecu_ini_cnt = 0;
////uint24_t tcr1_crk_now = 0; 
////uint24_t tcr1_crk_last = 0; 
uint8_t  count_art_temp_fun = 0;

uint8_t  tq_fun_time = 0;
uint8_t  tq_fun_time_100ms = 0;
uint8_t  tq_fun_time_1000ms = 0;

//从观察量中取出，以后可能不需要放在观察量
uint8_t  VS_PER_op = 0;
uint8_t  inder_oc2 = 0;
uint8_t  V_IGK_BAS_N_cnt = 0;
uint8_t  V_IGK_BAS_cnt = 0;
uint8_t  VB_MES_P = 0;
uint8_t  N_DIF_STATE = 0;
uint8_t  INH_SWI_IV_OP = 0;
uint8_t  PWL_DLY_CTR = 0;          //不等0 表示有其他任务未完成 POWERLAUNCH不能结束。不能断电。
uint8_t  EFP_POUT_STATE_0 = 0;    //LV_IGA 对EFP的影响
uint8_t  EFP_POUT_STATE_1 = 0;    //VS     对EFP的影响
uint8_t  EFP_POUT_STATE_2 = 0;    //N      对EFP的影响
uint8_t  T_PU_COUNT = 0;
uint8_t  PAT_INH_IV_last = 0;
uint8_t  NR_SEL_CYL_CTR = 0;
uint16_t INH_SWI_IV_PRE = 0;
uint16_t V_IGK_MES_S = 0;
uint16_t VB_MES_S = 0;
//uint24_t SOI_BSW = 0;
//uint24_t EOI_BSW = 0;
//uint24_t TI_BSW = 0;
//uint24_t TI_ADD_BSW = 0; 		          		
//int24_t  tcr2_now = 0;
uint32_t last_match_time_OC2 = 0;
uint32_t VS_GAIN_TEMP = 0;
uint32_t VS_INT_TIME = 0;
uint32_t VS_INT_TIME_LAST = 0;
uint16_t AR_RED_AD_ADD_LAST = 0;
uint16_t AR_RED_AD_FAC_LAST = 0;
uint16_t AR_RED_DIF_I_REL_last = 0;
uint16_t TPS_FIL_MTC_last = 0;
uint16_t LAM_MV_1_old = 0;
uint8_t  LAM_P_CTR_1_AD = 0;
uint8_t  LAM_P_CTR_1_PL = 0;
uint16_t LAM_MV_1_temp = 0;
uint16_t LAM_MV_LPF_1_temp = 0;
uint16_t N_TEMP_T_N_DIF_SAMPLE = 0; 
uint16_t N_TEMP_T_N_DIF_RIS = 0;
uint16_t CTR_T_N_DIF_SAMPLE_10MS = 0;
uint16_t CTR_T_N_DIF_RIS_10MS = 0;
uint16_t CTR_T_MAX_RIS_10MS = 0;
uint8_t  IGA_ST_old = 0;
uint8_t  ADD_WF_NUM = 0;
uint8_t  VS_STATE_CFA_LAST = 0;
uint8_t  STATE_CFA_IS_old = 0;
uint32_t TQ_DIF_I_IS_32t = 0;
//uint24_t T_SEG_AV = 0;
//uint24_t T_REG_PREV = 0;   
//uint24_t T_REG_AV = 0;
uint8_t  N_GRD_OLD = 0;
uint16_t MAF_MDL_CON_11 = 0;
uint16_t MAF_LAST = 0;
uint16_t MAP_THR = 0;
uint16_t MAP_CPS = 0;
uint16_t cycnr_hys_puc = 0;
uint8_t  SOI_TCO = 0;
uint16_t TI_1_TEMP = 0;
uint16_t ti_lgrd_ast_tco = 0;
uint16_t TIB_prev = 0;

//yabo 
uint8_t   LV_temp_PSTE_old = 0;
uint8_t   LV_temp_LAMP_old = 0;


