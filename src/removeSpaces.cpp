/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
int isSpace(char s){
	if (s == ' ')
		return 1;
	else
		return 0;
}
void shiftChars(char *str, int index){
	while (str[index] != '\0'){
		if (str[index] == ' '){//if the next character is also a space
			shiftChars(str, index + 1);//skip that character using recursion
		}
		str[index - 1] = str[index];
		index++;
	}
	str[index - 1] = '\0';
	
}
char removeSpaces(char *str) {
	if (str == NULL)
	return '\0';
	int len;
	for (len = 0; str[len] != '\0'; len++);
	for (int i = 0; i < len; i++){
		if (isSpace(str[i])){//checks if the character is space
			shiftChars(str, i + 1);//shifts the characters
			len--;
		}
	}
}