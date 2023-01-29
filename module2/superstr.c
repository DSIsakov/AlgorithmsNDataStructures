#include <stdio.h>
#include <string.h>


int glue(char* s1, char* s2, char* s){
	long len1 = strlen(s1), len2 = strlen(s2), minl = (len1 < len2) ? len1 : len2;
	int max = 0;
	for (int l = 1; l <= minl; l++){
		if (strncmp(&s1[0], &s2[len2-l], l) == 0){
			strcpy(s, s2);
			strcat(s, &s1[l]);
			max = l;
		}
		if (strncmp(&s1[len1-l], &s2[0], l) == 0){
			strcpy(s, s1);
			strcat(s, &s2[l]);
			max = l;
		}
	}
	if (max == 0){
		strcpy(s, s1);
		strcat(s, s2);
	}
	return max;
}


int main(){
	int n;
	scanf("%d", &n);
	char strs[n][100000];
	for (int i = 0; i < n; i++){
		scanf("%s", strs[i]);
	}
	long max, s1, s2;
	
	for (int k = 0; k < n - 1; k++){
		max = -1;
		char temps[1000000] = "";
		char s[1000000];
		for (int i = 0; i < n - 1 - k; i++){
			for (int j = i+1; j < n - k; j++){
				int len = glue(strs[i], strs[j], temps);
				if (len > max){
					max = len;
					s1 = i;
					s2 = j;
					strcpy(s, temps);
				}
			}
		}
		strcpy(strs[s1], s);
		if (s2 == n - k - 1){
			strcpy(strs[s2], "");
		}
		else{
			strcpy(strs[s2], strs[n - k - 1]);
			strcpy(strs[n - k - 1], "");
		}
	}
	printf("%ld", strlen(strs[0]));
}