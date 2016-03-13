/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void swap_string_letters(char *input, int len){
	int i = 0;
	int j = len - 1;
	while (i < j){//"i like code" -> "edoc ekil i"
		input[i] = input[i] + input[j];
		input[j] = input[i] - input[j];
		input[i] = input[i] - input[j];
		i++;
		j--;
	}
}
void swap_word_letters(char *input, int i, int j){
	while (i < j){//"edoc ekil i" -> "code like i"
		input[i] = input[i] + input[j];
		input[j] = input[i] - input[j];
		input[i] = input[i] - input[j];
		i++;
		j--;
	}
}
int count_spaces(char *input){
	int count_space = 0;
	for (int i = 0; input[i] != '\0'; i++){
		if (input[i] == ' ')
			count_space++;
	}
	return count_space;
}
void str_words_in_rev(char *input, int len){
	int spaces = count_spaces(input);
	if (count_spaces > 0){
		swap_string_letters(input, len);
		int i = 0, j = 1;
		while (j < len)
		{
			if (input[j] == ' '){//end of word
				if (i != j - 1){//condition to check if the word has more than one character
					swap_word_letters(input, i, j - 1);
					i = j + 1;
					j = j + 2;
				}
				else{
					i = j + 1;
					j = j + 2;
					continue;
				}
				
			}
			j++;
		}
		//swapping letters of the last word in the string
		//check if the word has more than on character
		if (i != j - 1){
			swap_word_letters(input, i, j - 1);
		}
	}
}
