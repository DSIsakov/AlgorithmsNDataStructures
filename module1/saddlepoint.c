#include <stdio.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int maxstr[a], mincol[b];
	for (int i = 0; i < b; i++){
		mincol[i] = 2000000000;
	}
	for (int i = 0; i < a; i++){
		maxstr[i] = -2000000000;
		for (int j = 0; j < b; j++){
			int x;
			scanf("%d", &x);
			maxstr[i] = (x > maxstr[i]) ? x : maxstr[i];
			mincol[j] = (x < mincol[j]) ? x : mincol[j];
		}
	}
	for (int i = 0; i < a; i++){
		for (int j = 0; j < b; j++){
			if (maxstr[i] == mincol[j]){
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("%s", "none");
	
	
	return 0;
}