/**********************************************************************
build PWM to control dc motor
函数说明：电机动作调速函数，
放在定时器或主循环中，通过调用GetCGX返回的CGX值产生软PWM来控制机器人
**********************************************************************/

void SpeedPWM(char PWMLine){
	char PWMLine_L = PWMLine;
	char PWMLine_R = PWMLine;
	static char PWMCount_L = 0;
	static char PWMCount_R = 0;
	char Temp = 0;

	if (FollowLineEnable == True){
		Temp = (char)fabs((float)CG_X);
		if (AdcValueFlag == 0){
			Temp = 0;
		}
		else{
			if (CG_X <0){
				if ((Temp<<4) <= PWMLine_R){
					PWMLine_R -= ((Temp<<5)+Temp<<2);
				}
				else{
					PWMLine_R = 0;
				}
			}
			else{
				if ((Temp<<4) <= PWMLine_L){
					PWMLine_L -= (Temp<<5);
				}
				else{
					PWMLine_L = 0;
				}
			}
		}
	}

	PWMCount_L ++;
	PWMCount_R ++;

	if (PWMCount_L > Fastest){
		PWMCount_L = Stop;
	}
	if (PWMCount_R > Fastest){
		PWMCount_R = Stop;
	}
	if (PWMCount_L < PWMLine_L){
		switch (GoDirection){
			case Front:Motor_Left_GoFront;break;
			case Back:Motor_Left_GoBack;break;
			case Left:Motor_Left_GoFront;break;
			case Right:Motor_Left_GoBack;break;
			case Stop:Motor_Left_Stop_Free;break;
		}
	}
	else{
		Motor_Left_Stop_Free;
	}
	if (PWMCount_R < PWMLine_R){
		switch (GoDirection){
			case Front:Motor_Right_GoFront;break;
			case Back:Motor_Right_GoBack;break;
			case Left:Motor_Right_GoBack;break;
			case Right:Motor_Right_GoFront;break;
			case Stop:Motor_Right_Stop_Free;break;
		}
	}
	else{
		Motor_Right_Stop_Free;
	}
}
