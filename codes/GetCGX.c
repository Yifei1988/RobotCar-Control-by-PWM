/*******************************************
build PWM to control dc motor     
函数说明：获取偏离轨迹的数值，
输入：表明巡线状态的字节
通过质心算法获取当前机器人偏离轨迹线的量
“-”表示偏左，“+”表示偏右
*******************************************/

signed char GetCG_X(unsigned char AdcValues){
	signed char a = 0;
	signed char Temp = 0;
	signed char Totals = 0;
	for (a = 0;a<8;a++){
		if ((AdcValues <<a)>>7){
			Temp += ((-7)+ (a<<1));
			Totals++;
		}
	}
	
	if (Totals ==0){
		return 0;
	}
	
	return (Temp / Totals);
}
