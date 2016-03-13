/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void convert_str(int num, char *str, int len){
	int rem = 0;
	if (num < 0){//if  number is negative
		num = -(int)num;//convert to positive
		str[len + 1] = '\0';
		str[0] = '-';
		for (int i = len; i > 0; i--){
			rem = num % 10;
			str[i] = rem + 48;
			num /= 10;
		}
	}
	else{//if number positive
		str[len] = '\0';

		for (int i = len - 1; i >= 0; i--){
			rem = num % 10;
			str[i] = rem + 48;
			num /= 10;
		}
	}
}
void convert_str_dec(int num, char *str, int dec, int len, int after_dec){
	
	int rem = 0;
	int i;
	if (num < 0){//if number negative
		num = -(int)num;
		dec = -(int)dec;
		str[len + 1] = '\0';
		str[0] = '-';
		for (i = len; i > len - after_dec; i--){//integral part
			rem = dec % 10;
			str[i] = rem + 48;
			dec /= 10;
		}
		str[i] = '.';
		for (i = i - 1; i > 0; i--){//decimal part
			rem = num % 10;
			str[i] = rem + 48;
			num /= 10;
		}
	}
	else{
		str[len] = '\0';
		for (i = len - 1; i >= len - after_dec; i--){//integral part
			rem = dec % 10;
			str[i] = rem + 48;
			dec /= 10;
		}
		str[i] = '.';
		for (i = i - 1; i >= 0; i--){//decimal part
			rem = num % 10;
			str[i] = rem + 48;
			num /= 10;
		}
	}


}
int count_digits(int num){
	int count = 0;
	while (num != 0){
		num /= 10;
		count++;
	}
	return count;
}
int power(int num, int after_dec){
	for (int i = 0; i < after_dec; i++)
		num *= 10;
	return num;
}

void number_to_str(float number, char *str,int afterdecimal){
	int num = (int)number;
	int len_num = count_digits(num);
	if (afterdecimal == 0){
		convert_str(num, str, len_num);
	}
	else{
		int dec = (number - num) * power(1, afterdecimal);//decimal part
		convert_str_dec(num, str, dec, len_num + afterdecimal + 1, afterdecimal);
	}

}
