
#ifndef _GLOBAL_FUN_H_
#define _GLOBAL_FUN_H_

/********************  Dependent Include files here **********************/
#include "typedefs.h"











//function declaration



extern void sys_init_data(void);
extern void test_cpp_fun(void);
extern void art_iga_aswtobsw(void);
extern void PIT0ISR(void);

extern void initADC(void);
extern void SendConvCmd (void);
extern void ReadResult(void);
extern void SendConvCmd_Channel(vuint8_t RFIFOchannel);


extern void ART_SYS_STATE(void);
extern void art_CylinderFuelShut_off(void);
extern void ini_ECU_work_para(void);
extern void art_temp_fun(void);
extern void  art_map_mes_a(void);

extern void  art_pv_10ms(void);
extern void  art_maf_cyc(void);
 
extern  void art_ES_ST(void);  
extern void art_eng_state_ini(void);
extern void art_eng_state_close(void);
extern void Art_eng_state_clc(void);

extern void Art_PAT_INH_IV_INI(void);  
extern void art_PAT_INH_IV_PUC_REAC(void);
extern void  Art_TI_ini(void);
extern void ini_TI_ADD_WF(void);
extern void Art_lv_rest(void);
extern void  art_TIPR(void);
extern void art_TI_ADD_WF(void); 
extern void art_TI_ADD_WF_SEP(uint8_t a); 
extern void	ART_AS_FUN(void);
extern void art_TI_WUP(void);
extern void art_TI_CAST(void);
extern void ART_is_control_ini(void);

extern void ART_TQ_INI(void);
extern void	Art_tq_loss(void);
extern void	Art_tqi_tra_control(void);
extern  void  	ART_LV_CT(void);
extern  void TQ_LOSS_INI(void);
extern  void art_iga_ini(void);
extern  void ART_IGA_cyc(void);
extern void iga_ini(void);
extern void  ini_set_TEG_DYN(void);
extern void  ini_ip_v_efc_lsh_up_ini(void);
extern void  ini_lam(void);
extern void art_ADD_TEG_COR(void) ;
extern void ini_LSHU_PWM_time(void);
extern void  ini_ip_v_efc_lsh_down_ini(void);
extern void ini_LSHD_PWM_time(void);
extern void art_LV_LAM_TCO_LSCL(void);
extern void ini_main_t_min_ls(void);
extern void art_LAM_ini(void);
extern void	art_ar_red_cyc(void);
extern void	art_ar_red_10ms(void);
extern void	art_ar_red_100ms(void);
extern void art_ar_red_ini(void);
extern void art_ch_ini(void);
extern void ART_CTR_VS(void);
extern void ART_VS_OP_INI(void);
extern void ART_VS_INT_ini(void);
extern void  ini_sys_conf(void);
extern void ART_GR_MT(void);
extern void ART_LV_DT(void);
extern  void ART_ACIN(void);
extern void ART_CFA(void);
extern  void ART_CFA_INI(void);
extern  void Art_vs_n_lim(void);
extern void Task_VVT_360CRKFUN01(void);
extern void Task_VVT_360CRKFUN02(void);
extern void Task_VVT_10MSFUN01(void);
extern void Task_VVT_10MSFUN02(void);
extern void Task_VVT_100MSFUN01(void);
extern void Task_VVT_1000MSFUN01(void);
extern void vvt_ini(void);
extern void vvt_end_postion_adaption(void);
extern void art_cam_sp_ivvt_in(void);
extern void ART_FAC_CAM_SP_PL_IVVT_IN(void);
extern void  art_SUM_CYC_CAM_DIAG_IVVT(void);
extern  void vvt_adj_pwm(void);
extern  void vvt_hold_adh_adap(void);
extern  void  vvt_hold_drift_adap(void);
extern  void vvt_hold_adap_manager(void);
extern  void vvt_hold_pwm_es(void);
extern  void vvt_hold_pwm(void);
extern  void vvt_pwmini(void);
extern  void vvt_ENA_CLE_SLV_IVVT(void);
extern  void vvt_value_clean(void);
extern  void diag_mec_vvt_fun(void);	//还没有增加
extern  void diag_cam_dif_vvt_fun(void); 
extern  void vvt_iga_cor(void);

//yabo
extern void SW_in_ini(void);
extern void art_lv_acin(void);
extern uint8_t logicInputsFromAD(uint16_t Vol, uint16_t MaxVolThreshold, uint16_t MinVolThreshold, uint8_t Lv_PosFlag);

extern void  ldp_ini(void);
extern void  ldp_vvt_ini(void);
extern void ldp_fun_ini_b(uint8_t* a,uint8_t b);
extern void ldp_fun_ini_w(uint16_t* a,uint8_t b);

//*****************MAP 查表
extern void interpolation01_w(WORD* ,WORD);  //WORD 1维表头
extern void interpolation01_b(BYTE* ,BYTE);  //BYTE 1维表头
extern WORD liner_art01_b(BYTE*);            // BYTE 1维表  
extern WORD liner_art01_w(WORD*);            //WORD 1维表 
extern void interpolation02_w(WORD*,WORD);  //WORD 2维表头
extern void interpolation02_b(BYTE*,BYTE);  //BYTE 2维表头
extern WORD liner_art02_w(WORD*);            //WORD 2维表
extern WORD liner_art02_b(BYTE*);            //BYTE 2维表
extern WORD liner_art01_ID_b(BYTE* temp_byteop01);   //BYTE 1维 id表
extern WORD liner_art01_ID_w(WORD* temp_byteop01);   //WORD 1维ID表
extern WORD liner_art02_ID_b(BYTE* temp_byteop01);  //2维BYTE ID表

extern uint16_t art32div32to16(uint32_t a,uint32_t b);
extern uint32_t UMAX(uint32_t a,uint32_t b);
extern uint32_t UMIN(uint32_t a,uint32_t b);
extern int16_t MAX16(int16_t a,int16_t b);        //16t 有符号  MAX
extern int16_t MIN16(int16_t a,int16_t b);         //16t 有符号  MIN
extern int32_t LIM32(int32_t a,int32_t b,int32_t c);
extern int16_t LIM16(int16_t a,int16_t b,int16_t c); 
extern uint32_t ULIM(uint32_t a,uint32_t b,uint32_t c);
extern int16_t  ADD16_t(int16_t a,int16_t b);
extern int8_t  ADD8_t(int8_t a,int8_t b);
extern uint16_t  ADDu16_t(uint16_t a,uint16_t b);
extern uint8_t   ADDu8_t(uint8_t a,uint8_t b);
extern uint16_t  ADDu16_t2(uint16_t a,int16_t b);  //a 为无符号 b有符号 输出无符号
extern uint8_t  ADDu8_t2(uint8_t a,int8_t b);  //a 为无符号 b有符号
extern uint16_t  SUBu16_t(uint16_t a,uint16_t b); //a .b位 无符号  输出结果为 无符号。
extern uint8_t  SUBu8_t(uint8_t a,uint8_t b);
extern int16_t  SUB16_t(uint16_t a,uint16_t b);   //a .b位 无符号  输出结果为 有符号。
extern int8_t  SUB8_t(uint8_t a,uint8_t b);  //a .b位 无符号  输出结果为 有符号。

extern uint16_t mathfun01(uint16_t a,uint16_t b,uint8_t c);// (a*b)>>c  a为 有符号
extern uint16_t mathfun02(uint16_t a,uint16_t b,uint8_t c); // (a*b)>>c  a为 无符号
extern int16_t  mathfun03(uint16_t a,uint16_t b,uint16_t c); //  =(a-b)/c;  a,b 为 无符号 结果有符号


extern void task_bas00(void);
extern void task_bas01(void);
extern void task_bas02(void);
extern void task_bas03(void);
extern void task_bas04(void);
extern void task_bas05(void);
extern void task_bas06(void);
extern void task_bas07(void);
extern void task_bas08(void);
extern void task_bas09(void);
extern void task_bas0A(void);
extern void task_bas0B(void);
extern void task_bas0C(void);
extern void task_bas0D(void);
extern void task_bas0E(void);
extern void task_bas0F(void);
extern void task_bas10(void);
extern void task_bas11(void);
extern void task_bas12(void);
extern void task_bas13(void);
extern void task_bas14(void);
extern void task_bas15(void);
extern void task_bas16(void);
extern void task_bas17(void);
extern void task_bas18(void);
extern void task_bas19(void);
extern void task_bas1A(void);
extern void task_bas1B(void);
extern void task_bas1C(void);
extern void task_bas1D(void);
extern void task_bas1E(void);
extern void task_bas1F(void);
extern void task_bas20(void);
extern void task_bas21(void);
extern void task_bas22(void);
extern void task_bas23(void);
extern void task_bas24(void);
extern void task_bas25(void);
extern void task_bas26(void);
extern void task_bas27(void);
extern void task_bas28(void);
extern void task_bas29(void);
extern void task_bas2A(void);
extern void task_bas2B(void);
extern void task_bas2C(void);
extern void task_bas2D(void);
extern void task_bas2E(void);
extern void task_bas2F(void);


extern void task_event_0(void);
extern void task_event_1(void);
extern void task_event_2(void);
extern void task_event_3(void);
extern void task_event_4(void);
extern void task_event_5(void);

extern void task_5ms_timer_0(void);
extern void task_5ms_timer_1(void);
extern void task_5ms_timer_2(void);
extern void task_5ms_timer_3(void);
extern void task_5ms_timer_4(void);

extern void task_10ms_timer_0(void);
extern void task_10ms_timer_1(void);
extern void task_10ms_timer_2(void);
extern void task_10ms_timer_3(void);
extern void task_10ms_timer_4(void);
extern void task_10ms_timer_5(void);
extern void task_10ms_timer_6(void);
extern void task_10ms_timer_7(void);
extern void task_10ms_timer_8(void);
extern void task_10ms_timer_9(void);

extern void task_100ms_timer_0(void);
extern void task_100ms_timer_1(void);
extern void task_100ms_timer_2(void);
extern void task_100ms_timer_3(void);
extern void task_100ms_timer_4(void);
extern void task_100ms_timer_5(void);
extern void task_100ms_timer_6(void);
extern void task_100ms_timer_7(void);
extern void task_100ms_timer_8(void);
extern void task_100ms_timer_9(void);

extern void task_1000ms_timer_0(void);
extern void task_1000ms_timer_1(void);
extern void task_1000ms_timer_2(void);
extern void task_1000ms_timer_3(void);
extern void task_1000ms_timer_4(void);
extern void task_1000ms_timer_5(void);
extern void task_1000ms_timer_6(void);
extern void task_1000ms_timer_7(void);
extern void task_1000ms_timer_8(void);
extern void task_1000ms_timer_9(void);

#endif  /* _GLOBAL_VAR_H_ */
