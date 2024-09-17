

#ifndef INC_LINE_H_
#define INC_LINE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define on		1
#define off		0

#define nang	1
#define ha		0

#define tien 	1
#define lui		2
#define trai 	3
#define phai	4
#define len_doc_speed	150
#define xuong_doc_speed	70
extern volatile uint8_t led[8];
extern volatile uint8_t led2[8];
extern uint8_t so_nga3 ;
extern uint8_t so_nga4 ;
extern uint32_t time1;
extern uint32_t time2;
extern uint32_t lastHit;

extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart1;
extern volatile int goc,goc0;

extern char data[60];
extern int values[25];
extern uint8_t flag;
extern volatile int P_1,I_1,D_1,PID_1,lech_1,pre_lech_1;
//
//#define Kp				0
//#define Ki				0
//#define Kd				0
extern int P_2,I_2,D_2,PID_2,lech_2,pre_lech_2;

//#define KP				0
//#define KI				0
//#define KD				0

extern int P_a,I_a,D_a,PID_a,lech_ag,pre_lech_ag;

//#define Kp_a			0
//#define Ki_a			0
//#define Kd_a			0

void TIM5_Init(void);

void MX_USART1_UART_Init(void);

void split_array(void);

void Line_PIN_Config(void);

void lech_value_1(void);

void lech_value_2(void);

void goc_lech_value(void);

void nga4_count(void);

void pid_lech_1(void);

void pid_lech_2(void);

void pid_lech_1(void);

void pid_lech_2(void);

void pid_goc(void);

/********************************************************PID_VALUE_TO_MOTOR****************************************************/
void motor_foward_pid(int speed);
void motor_backward_pid(int speed);
void motor_rightside_pid(int speed);
void motor_leftside_pid(int speed);
void motor_turn_angle(int speed);
void run_turn_angle(int speed, int angle);
/**********************************-Line Follow-**************************************/
void linefollow_foward(int speed);
void linefollow_backward(int speed);
void linefollow_rightside(int speed);
void linefollow_leftside(int speed);

void linefollow_foward_time(int speed, uint16_t time);
void linefollow_backward_time(int speed, uint16_t time);
void linefollow_leftside_time(int speed, uint16_t time);
void linefollow_rightside_time(int speed, uint16_t time);

void run_angle(uint16_t v_robot, uint16_t angle);
void run_angle_time(uint16_t v_robot,uint16_t angle,uint16_t time);

/***********************-Run with encoder-*************************/

void run_foward_steps(int speed, uint16_t step);
void run_backward_steps(uint16_t speed, uint16_t step);
void run_right_steps(uint16_t speed, uint16_t step);
void run_left_steps(uint16_t speed, uint16_t step);

/*******************chay dem so vach***************************/
void run_foward_count(int speed, uint8_t nga3 , uint8_t nga4);
void run_backward_count(int speed, uint8_t nga3 , uint8_t nga4);
void run_leftside_count(int speed, uint8_t nga3 , uint8_t nga4);
void run_rightside_count(int speed, uint8_t nga3 , uint8_t nga4);
/*******************chay mu`***********************************/
void chay_doc(int speed,uint8_t mode,uint16_t time);
void run_foward_noline(int speed,uint16_t time);
void run_backward_noline(int speed,uint16_t time);
void run_leftside_noline(int speed,uint16_t time);
void run_rightside_noline(int speed,uint16_t time);



void nang_ha_led(uint8_t nang_ha);
void cho_lenh(uint8_t lenh);

void bat_den(uint8_t state);
#ifdef __cplusplus
}
#endif
#endif /* INC_LINE_H_ */
