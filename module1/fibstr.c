#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *fibstr(int n){
	if (n == 1){
		char *s = (char*)malloc(2 * sizeof(char));
		strcpy(s, "a");
		return s;
	}
	if (n == 2){
		char *s = (char*)malloc(2 * sizeof(char));
		strcpy(s, "b");
		return s;
	}
	if (n >= 3){
		int a1 = 1, a2 = 1, a3;
		for (int i = 3; i < n; i++){
			a3 = a1 + a2;
			a1 = a2;
			a2 = a3;
		}
		a3 = a1 + a2;
		// printf("%d %d %d", a1, a2, a3);
		// char *s0 = (char*)calloc(a2 - a1, sizeof(char))
		char *s1 = (char*)calloc(a1 + 1, sizeof(char));
		char *s2 = (char*)calloc(a2 + 1, sizeof(char));
		char *s3 = (char*)calloc(a3 + 1, sizeof(char));
		strcat(s1, "a");
		strcat(s2, "b");
		strcat(s3, "ab");
		for (int i = 4; i <= n; i++){
			strcpy(s1, s2);
			strcpy(s2, s3);
			strcpy(s3, s1);
			strcat(s3, s2);
		}
		free(s1);
		free(s2);
		return s3;
	}
}


int main(){
	int n;
	scanf("%d", &n);
	char *s = fibstr(n);
	printf("%s", s);
	free(s);
}