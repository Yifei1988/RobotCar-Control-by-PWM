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
