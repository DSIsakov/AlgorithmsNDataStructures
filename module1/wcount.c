#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int wcount(char *s){
	char word = 0;
	int len = strlen(s);
	long count = 0;
	for (int i = 0; i < len; i++){
		if (s[i] == ' '){
			if (word){
				count++;
				word = 0;
			}
		}
		else{
			word = 1;
		}
	}
	if (word){
		count++;
	}
	
	return count;
}


int main(){
	char *str = (char*)malloc(10000*sizeof(*str));
	gets(str);
	int c = wcount(str);
	printf("%d", c);
	free(str);
	return 0;
}