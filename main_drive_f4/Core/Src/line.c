#include "line.h"

extern int MotorSpeed[5];
void TIM5_Init(void)
{



  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_Encoder_InitTypeDef encoder_init = {0};


  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 0;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 4294967295;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim5) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

  encoder_init.EncoderMode	=	TIM_ENCODERMODE_TI1;
  encoder_init.IC1Filter	=	5;
  encoder_init.IC1Polarity	=	TIM_ICPOLARITY_RISING;
  encoder_init.IC1Selection	=	TIM_ICSELECTION_DIRECTTI;

  encoder_init.IC2Filter	=	0;
  encoder_init.IC2Polarity	=	TIM_ICPOLARITY_FALLING;
  encoder_init.IC2Selection	=	TIM_ICSELECTION_INDIRECTTI;

  if(HAL_TIM_Encoder_Init(&htim5, &encoder_init) != HAL_OK)
  {
	  Error_Handler();
  }


  HAL_TIM_MspPostInit(&htim5);

}

void Line_PIN_Config(void)
{
	/// led ngang
// E 7 8 9 10 11 12 13 ; B 2 ;
	GPIO_InitTypeDef pin_line_cf;

	pin_line_cf.Mode		=	GPIO_MODE_INPUT;
	pin_line_cf.Pin			=	GPIO_PIN_7  | GPIO_PIN_8  | GPIO_PIN_9  | GPIO_PIN_10  | GPIO_PIN_11 |
								GPIO_PIN_12 | GPIO_PIN_13 ;
	pin_line_cf.Pull		=	GPIO_PULLUP;
	pin_line_cf.Speed		=	GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOE, &pin_line_cf);

	pin_line_cf.Pin			=	GPIO_PIN_2;
	HAL_GPIO_Init(GPIOB, &pin_line_cf);

}

void lech_value_1(void)
{
	led[0]=	!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
	led[1]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7);
	led[2]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8);
	led[3]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9);
	led[4]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10);
	led[5]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11);
	led[6]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12);
	led[7]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13);

	if (        (led[1] == 1) && (led[2] == 0)  && (led[3] == 0) && (led[2] == 0) && (led[5] == 0)  && (led[6] == 0)   )
		lech_1 = -6;
	else if (   (led[1] == 1) &&  (led[2] == 1) && (led[3] == 0) && (led[2] == 0) && (led[5] == 0)  && (led[6] == 0)   )
		lech_1 = -5;
	else if (   (led[1] == 0) &&  (led[2] == 1) && (led[3] == 0) && (led[2] == 0) && (led[5] == 0)  && (led[6] == 0)   )
		lech_1 = -3;
	else if (  (led[1] == 0) &&   (led[2] == 1) && (led[3] == 1) && (led[4] == 0) && (led[5] == 0)  && (led[6] == 0)   )
		lech_1 = -2;
	else if (  (led[1] == 0) &&   (led[2] == 0) && (led[3] == 1) && (led[4] == 0) && (led[5] == 0)  && (led[6] == 0)   )
		lech_1 = -1;
	else if (  (led[1] == 0) &&   (led[2] == 0) && (led[3] == 1) && (led[4] == 1) && (led[5] == 0)  && (led[6] == 0)   )
		lech_1 = 0;
	else if (  (led[1] == 0) &&   (led[2] == 0) && (led[3] == 0) && (led[4] == 1) && (led[5] == 0)  && (led[6] == 0)   )
		lech_1 = 1;
	else if (  (led[1] == 0) &&   (led[2] == 0) && (led[3] == 0) && (led[4] == 1) && (led[5] == 1)  && (led[6] == 0)   )
		lech_1 = 2;
	else if (  (led[1] == 0) &&   (led[2] == 0) && (led[3] == 0) && (led[4] == 0) && (led[5] == 1)  && (led[6] == 0)   )
		lech_1 = 3;
	else if (  (led[1] == 0) &&   (led[2] == 0) && (led[3] == 0) && (led[4] == 0) && (led[5] == 1)  && (led[6] == 1)   )
		lech_1 = 5;
	else if (  (led[1] == 0) &&   (led[2] == 0) && (led[3] == 0) && (led[4] == 0) && (led[5] == 0)  && (led[6] == 1)   )
		lech_1 = 6;
}

void lech_value_2(void)

{
	/// led doc
	// E 14 15   B12 13 14 15  D 8 9


led2[0]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14);
led2[1]=	!HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15);
led2[2]=	!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
led2[3]=	!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
led2[4]=	!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
led2[5]=	!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
led2[6]=	!HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8);
led2[7]=	!HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9);

	// vach tr?ng n?n t?i// ban ddaauf la - +

 if (      (led2[0] == 1) &&       (led2[1] == 0) && (led2[2] == 0)  && (led2[3] == 0) && (led2[2] == 0) && (led2[5] == 0)    && (led2[6] == 0)  && (led2[7] == 0)    )
		lech_2 = -8;
  else if(   (led2[0] == 1)  && (led2[1] == 1) && (led2[2] == 0)  && (led2[3] == 0) && (led2[2] == 0) && (led2[5] == 0)    && (led2[6] == 0)  && (led2[7] == 0)    )
		lech_2 = -7;
  else if (  (led2[0] == 0) &&     (led2[1] == 1) && (led2[2] == 0)  && (led2[3] == 0) && (led2[2] == 0) && (led2[5] == 0)    && (led2[6] == 0)   && (led2[7] == 0)   )
    lech_2 = -6;
  else if (  (led2[0] == 0) &&   (led2[1] == 1) &&  (led2[2] == 1) && (led2[3] == 0) && (led2[2] == 0) && (led2[5] == 0)    && (led2[6] == 0)    && (led2[7] == 0)  )
    lech_2 = -5;
  else if (  (led2[0] == 0) &&  (led2[1] == 0) &&  (led2[2] == 1) && (led2[3] == 0) && (led2[2] == 0) && (led2[5] == 0)    && (led2[6] == 0)   && (led2[7] == 0)   )
    lech_2 = -3;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 1) && (led2[3] == 1) && (led2[4] == 0) && (led2[5] == 0)     && (led2[6] == 0)  && (led2[7] == 0)   )
    lech_2 = -2;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 1) && (led2[4] == 0) && (led2[5] == 0)    && (led2[6] == 0)   && (led2[7] == 0)     )
    lech_2 = -1;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 1) && (led2[4] == 1) && (led2[5] == 0)    && (led2[6] == 0)   && (led2[7] == 0)  )
    lech_2 = 0;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 0) && (led2[4] == 1) && (led2[5] == 0)  && (led2[6] == 0)   && (led2[7] == 0)    )
    lech_2 = 1;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 0) && (led2[4] == 1) && (led2[5] == 1)  && (led2[6] == 0)     && (led2[7] == 0)    )
    lech_2 = 2;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 0) && (led2[4] == 0) && (led2[5] == 1)  && (led2[6] == 0)   && (led2[7] == 0)      )
    lech_2 = 3;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 0) && (led2[4] == 0) && (led2[5] == 1)  && (led2[6] == 1)   && (led2[7] == 0)    )
    lech_2 = 5;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 0) && (led2[4] == 0) && (led2[5] == 0)  && (led2[6] == 1)   && (led2[7] == 0)      )
    lech_2 = 6;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 0) && (led2[4] == 0) && (led2[5] == 0)  && (led2[6] == 1)   && (led2[7] == 1)      )
    lech_2 = 7;
  else if ( (led2[0] == 0) &&  (led2[1] == 0) &&   (led2[2] == 0) && (led2[3] == 0) && (led2[4] == 0) && (led2[5] == 0)  && (led2[6] == 0)   && (led2[7] == 1)      )
    lech_2 = 8;
}// end func

void nga4_count(void)
{
	int i = 0;
		if (led[0] == 1)    i++;
		if (led[1] == 1)    i++;
		if (led[2] == 1)    i++;
		if (led[3] == 1)    i++;
		if (led[4] == 1)    i++;
		if (led[5] == 1)    i++;
		if (led[6] == 1)    i++;
		if (led[7] == 1)    i++;

	  if ((  i >= 4||  ((led[3] == 1 ||  led[4] == 1 )&& (led[1] == 1 || led[6] == 1 )) ) &&  millies() - time1 >= 300  )
	    // ng� 4
	  {

	    so_ngatu ++; // tang so ng� tu l�n
	    time1 = millies();
	  }
}
/******************************************************PID_CALCULATE***********************************/
void pid_lech_1(void)
{
	P_1	= Kp*lech_1;

	I_1	= Kp*lech_1 + I_1;

	D_1	= Kd*(lech_1 - pre_lech_1);

	PID_1 = P_1 + I_1 + D_1;
	pre_lech_1 = lech_1;
}

void pid_goc(void)
{
	lech_ag = goc - goc0;

	if( abs(lech_ag) <=  1 ) lech_ag=0;

	P_a = lech_ag*Kp_a;

	I_a = Kp_a*lech_ag + I_a;

	D_a = (lech_ag - pre_lech_ag)*Kd_a;

	PID_a = P_a+I_a+D_a;

	pre_lech_ag = lech_ag;

	if(PID_a >40)   PID_a =40;
	if(PID_a <-40)   PID_a =-40;
}

void pid_lech_2()
{


	P_2 = lech_2*KP;

	I_2 = KI*lech_2 + I_2;

	D_2 = (lech_2 - pre_lech_2)*KD;

	PID_2 = P_2+I_2+D_2;

	pre_lech_2 = lech_2;

	if( PID_2 >100)   PID_2 =100;

	if( PID_2 <-100)   PID_2 =-100;

}

//   ^1
//   |
//2     4
//          -->2
//
//1     3
/********************************************************PID_VALUE_TO_MOTOR****************************************************/

void motor_foward_pid(int speed)
{
	int x = speed;
	/*--line + angle--*/
	// khi goc lech duong , pid + vao 1 2 ??
	MotorSpeed[1] = x - PID_1 - PID_a;
	MotorSpeed[2] = x + PID_1 - PID_a;
	MotorSpeed[3] = x + PID_1 + PID_a;
	MotorSpeed[4] = x - PID_1 + PID_a;

	st_motor1( MotorSpeed[1]);
	st_motor2(-MotorSpeed[2]);
	st_motor3(-MotorSpeed[3]);
	st_motor4( MotorSpeed[4]);

}

void motor_backward_pid(int speed)
{
	int x = speed;
	MotorSpeed[1] = x + PID_1 - PID_a;
	MotorSpeed[2] = x - PID_1 - PID_a;
	MotorSpeed[3] = x - PID_1 + PID_a;
	MotorSpeed[4] = x + PID_1 + PID_a;

	st_motor1(-MotorSpeed[1]);
	st_motor2( MotorSpeed[2]);
	st_motor3( MotorSpeed[3]);
	st_motor4(-MotorSpeed[4]);

}

void motor_rightside_pid(int speed)
{
	int x = speed;
	MotorSpeed[1] = x + PID_2 - PID_a;
	MotorSpeed[2] = x - PID_2 - PID_a;
	MotorSpeed[3] = x - PID_2 + PID_a;
	MotorSpeed[4] = x + PID_2 + PID_a;

	st_motor1(-MotorSpeed[1]);
	st_motor2( MotorSpeed[2]);
	st_motor3( MotorSpeed[3]);
	st_motor4(-MotorSpeed[4]);

}

void motor_leftside_pid(int speed)
{
	int x = speed;
	MotorSpeed[1] = x - PID_2 + PID_a;
	MotorSpeed[2] = x + PID_2 + PID_a;
	MotorSpeed[3] = x + PID_2 - PID_a;
	MotorSpeed[4] = x - PID_2 - PID_a;

	st_motor1(MotorSpeed[1]);
	st_motor2(-MotorSpeed[2]);
	st_motor3(-MotorSpeed[3]);
	st_motor4(MotorSpeed[4]);

}


/**********************************-Line Follow-**************************************/

void linefollow_foward(int speed)
{
	lech_value_1();
	lech_value_2();
	pid_lech_1();
	pid_goc();
//	if(Run_ENABLE==1)// kiem tra nut
//	{
//	motor_foward_pid( speed  );
//
//	}
//	else
//		Robot_stop();
//	LCD_speed_plot();
}

void linefollow_backward(int speed)
{
	lech_value_1();
	lech_value_2();
	pid_lech_1();
	pid_goc();
//	if(Run_ENABLE==1)// kiem tra nut
//	{
//	motor_backward_pid( speed  );
//
//	}
//	else
//		Robot_stop();
//	LCD_speed_plot();
}

void linefollow_rightside(int speed)
{
	lech_value_1();
	lech_value_2();
	pid_lech_2();
	pid_goc();
	//	if(Run_ENABLE==1)// kiem tra nut
	//	{
	//	motor_rightside_pid( speed  );
	//
	//	}
	//	else
	//		Robot_stop();
	//	LCD_speed_plot();
}
void linefollow_leftside(int speed)
{
	lech_value_1();
	lech_value_2();
	pid_lech_2();
	pid_goc();
	//	if(Run_ENABLE==1)// kiem tra nut
	//	{
	//	motor_leftside_pid( speed  );
	//
	//	}
	//	else
	//		Robot_stop();
	//	LCD_speed_plot();
}

void linefollow_foward_time(int speed, uint16_t time)
{
	uint16_t current = millies();
	while(millies() - current < time)
	{
		linefollow_foward(speed);
	}
	stop();

}

void linefollow_backward_time(int speed, uint16_t time)
{
	uint16_t current = millies();
	while(millies() - current < time)
	{
		linefollow_backward(speed);
	}
	stop();

}

void linefollow_leftside_time(int speed, uint16_t time)
{
	uint16_t current = millies();
	while(millies() - current < time)
	{
		linefollow_leftside(speed);
	}
	stop();

}

void linefollow_rightside_time(int speed, uint16_t time)
{
	uint16_t current = millies();
	while(millies() - current < time)
	{
		linefollow_rightside(speed);
	}
	stop();

}

void run_angle(uint16_t v_robot, uint16_t angle)
{
	MotorSpeed[1] = v_robot*sin((45 - angle + 180   )*3.141592/180) + PID_a;
	MotorSpeed[2] = v_robot*sin((45 - angle + 90	)*3.141592/180) + PID_a;
	MotorSpeed[3] = v_robot*sin((45 - angle	+ 270	)*3.141592/180) + PID_a;
	MotorSpeed[4] = v_robot*sin((45 - angle			)*3.141592/180) + PID_a;

	st_motor1(MotorSpeed[1]);
	st_motor2(MotorSpeed[2]);
	st_motor3(MotorSpeed[3]);
	st_motor4(MotorSpeed[4]);
}

void run_angle_time(uint16_t v_robot,uint16_t angle,uint16_t time)
{
	uint16_t current_time = millies();
	while(millies()- current_time < time )
	{
		run_angle(v_robot, angle);
		//delay_ms();
	}

	stop();

}


/***********************-Run with encoder-*************************/

void run_foward_steps(int speed, uint16_t step)
{
	__HAL_TIM_SET_COUNTER(&htim5,200);
	while (__HAL_TIM_GET_COUNTER(&htim5) - 200 <= step)
	{
		chay_thang(speed);
	}
}

void run_backward_steps(uint16_t speed, uint16_t step)
{
	__HAL_TIM_SET_COUNTER(&htim5,200);
	while (__HAL_TIM_GET_COUNTER(&htim5) -200 <= step)
	{
		chay_lui(speed);
	}
}

void run_right_steps(uint16_t speed, uint16_t step)
{
	__HAL_TIM_SET_COUNTER(&htim5,200);
	while (__HAL_TIM_GET_COUNTER(&htim5) - 200 <= step)
	{
		chay_phai(speed);
	}
}

void run_left_steps(uint16_t speed, uint16_t step)
{
	__HAL_TIM_SET_COUNTER(&htim5,200);
	while (__HAL_TIM_GET_COUNTER(&htim5) - 200 <= step)
	{
		chay_trai(speed);
	}
}

