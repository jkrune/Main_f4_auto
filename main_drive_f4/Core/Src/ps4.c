#include "ps4.h"
#include "motor_ctl.h"
uint8_t rcv_buffer,count;
extern int RobotSpeed_y,RobotSpeed_x;
char data[60];
int values[25];	/*	0: Left Stick_X | 1: Left Stick Y	| 2: Right Stick X 	| 3: Left_Stick Y 	| 4: Left 	| 5: Down 		| 6: Right 		| 7: Up
					8: Vuong 		| 9: X 				| 10: Tron 			| 11: Tam giac 		| 12: Left_1| 13: Right_1 	| 14: Left_2	| 15: Right_2
					16: Share		| 17: Option 		| 18: PS_Button 	| 19: Tounch_pad 	| 20:Battery 												*/
uint16_t sspeed;
uint8_t flag =0;

void MX_USART5_UART_Init(void)
{


  huart5.Instance = UART5;
  huart5.Init.BaudRate = 19200;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

void split_array(void)
{



     // Mảng để lưu các giá trị
    char *token;
    char delim[] = ","; // Ký tự phân tách giữa các giá trị
    int i = 0;

    // Sử dụng strtok để tách chuỗi
    token = strtok(data, delim);

    // Duyệt qua các phần tử đã được tách
    while (token != NULL) {
        sscanf(token, "%d", &values[i]); // Chuyển đổi chuỗi thành số nguyên và lưu vào mảng
        i++;
        token = strtok(NULL, delim); // Tiếp tục tách chuỗi
    }

}




void Control_Move(void)
{
	int tempy,tempx,xoay;
	xoay =	values[2];
	tempy = values[1];
	tempx = values[0];
	//gioi han gia tri
	if(abs(tempx) < 63)
	{
		tempx = 0;
	}

	if(abs(tempy) < 63)
	{
		tempy = 0;
	}

	if(abs(xoay) < 63)
	{
		xoay = 0;
	}

	if(abs(tempx) > abs(tempy))
	{
		tempy = 0;
	}
	else if(abs(tempx) < abs(tempy))
	{
		tempx = 0;
	}


		if(  (values[12] == 1  ||  values[14] == 1)   &&  (abs(tempy)>0 || abs(tempx)>0 || abs(xoay)> 0) )
		{// neu EABLE
			if( values[12]  && abs(tempy)>0)
				{
					sspeed = Basic_speed;
					RobotSpeed_y = sspeed * sign(tempy);
					chay_thang(	RobotSpeed_y);
				}else if( values[14]  &&  abs(tempy)>0)
				{
					sspeed=Fast_speed;
					RobotSpeed_y=  sspeed * sign(tempy);
					chay_thang(	RobotSpeed_y);
				}		else RobotSpeed_y=0;

			if( values[12]  && abs(tempx)>0 )
				{
					sspeed = Basic_speed;
					RobotSpeed_x = sspeed * sign(tempx) ;
					chay_phai(RobotSpeed_x);
				}else if( values[12]  &&  abs(tempx)>0)
				{
					sspeed = Fast_speed;
					RobotSpeed_x =  sspeed * sign(tempx) ;
					chay_phai(RobotSpeed_x);
				}		else RobotSpeed_x = 0;
			//xoay
			 if(    values[12]  &&   xoay > 0 )    	xoay_phai(Turn_speed);
			 if(    values[12]  &&   xoay < 0 )    	xoay_trai(Turn_speed);


		}else
		{

			stop();// neu nut 9 and 11  = 0 thi stop het
			RobotSpeed_x=0;
			RobotSpeed_y=0;
		}

//		 if(values[16] == 1)
//		 {
//			 tha_long();
//		 }
		tempx=0;
		tempy=0;
		xoay=0;
		flag = 0;
}

void Hand_Control(void)
{
	split_array();
	angle_adjust();
	Control_Move();
	HAL_UART_Receive_IT(&huart5,&rcv_buffer,1);
	//HAL_Delay(10);
}


int  sign(int number)
{
	int dau;
	if(number > 0)
	{
		dau = 1;
	}
	else if(number < 0)
	{
		dau = -1;
	}else dau = 0;
	return dau;
}


