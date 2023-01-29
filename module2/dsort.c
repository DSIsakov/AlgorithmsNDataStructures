#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char *a = (char*)calloc(1000010, 1);
	scanf("%s", a);
	int n = strlen(a);
	char *b = (char*)calloc(n+1, 1);
	int count[26] = {0};
	int ind[26] = {0};
	for (int i = 0; i < n; i++){
		count[(int)a[i] - 97]++;
	}
	for (int i = 0; i < 26; i++){
		if (i == 0){
			ind[i] = count[i];
		}
		else{
			ind[i] = count[i] + ind[i-1];
		}
	}
	for (int i = n - 1; i>=0; i--){
		int j = --ind[(int)a[i] - 97];
		b[j] = a[i];
	}
	for (int i = 0; i< n; i++){
		printf("%c", b[i]);
	}
	free(a);
	free(b);
}