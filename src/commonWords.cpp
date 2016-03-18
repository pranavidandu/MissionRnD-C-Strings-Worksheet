/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int check_word(char *str1, char *str2, int i, int j){
	int len = i - 1;
	while (1){
		if (str1[i] == '\0' || str1[i] == ' ')
			break;
		if (str1[i] == str2[j]){
			i++;
			j++;
		}
		else return 0;
	}
	return i - len;
}
void assign_word(char *str1, int i, char **arr, int index, int len){
	//dynamically allocating memory for each row in the 2d array
	arr[index] = (char *)malloc(sizeof(int) * (index + 1) * len);
	int j = 0;
	while (1) {
		if (str1[i] == '\0' || str1[i] == ' ')
			break;
		arr[index][j] = str1[i];
		j++;
		i++;
	}
	arr[index][j] = '\0';
}
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	char **arr;
	arr = (char **)malloc(sizeof(int *) * 1);
	int i = 0, j = 0;
	int index = 0;
	int len = 0;
	int len_str1 = 0;
	for (len_str1 = 0; str1[len_str1] != '\0'; len_str1++);
	int len_str2 = 0;
	for (len_str2 = 0; str2[len_str2] != '\0'; len_str2++);
	while (i < len_str1){
		if (str1[i] == ' '){//if the input of str1 contains spaces
			i++;
			continue;
		}
		if (j >= len_str2)//if str2 is checked completely once the index j is set to 0
			j = 0;
	    len = check_word(str1, str2, i, j);
		//if len > 0 the words are alike
		if (len > 0){
			//assigning the word to the array arr
			assign_word(str1, i, arr, index, len);
			//incrementing the index of arr
			index++;
			//index i position is shifted to the next word position in str1
			i += len + 1;
			j = 0;
			continue;
		}
		else{
			//index j position is shifted to the next word in str2
			while (str2[j] != ' ')
				j++;
			//if all the words in str2 are checked then no match, index i position is shifted to the next word in str1
			if (j > len_str2){
				j = 0;
				i += len + 1;
			}
			else
				j++;
		}
	}

	if (index == 0){//if no common words
		return NULL;
	}
	return arr;

}