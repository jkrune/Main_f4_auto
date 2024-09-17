
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f4xx_hal.h"


void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);


void Error_Handler(void);

#include "motor_ctl.h"
#define Turn_speed		72	//18
#define Basic_speed		130 //30
#define Fast_speed		200 //55


#include "line.h"
int MotorSpeed[5] ;
uint8_t led[7];
uint8_t led2[7];
uint8_t goc,goc0;
uint32_t time1 ;
uint32_t lastHit;
#define Kp				0
#define Ki				0
#define Kd				0
int P_1,I_1,D_1,PID_1,lech_1,pre_lech_1;

#define KP				0
#define KI				0
#define KD				0
int P_2,I_2,D_2,PID_2,lech_2,pre_lech_2;


#define Kp_a			0
#define Ki_a			0
#define Kd_a			0
int P_a,I_a,D_a,PID_a,lech_ag,pre_lech_ag;

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "delay.h"

//ps4
#include "ps4.h"
extern uint8_t flag ;
extern uint8_t rcv_buffer,count;
extern char data[60];
extern int values[25];



//line


//keypad_lcd
#include "keypad_lcd.h"

char button[4];


//ban bong
#include "banbong.h"
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
