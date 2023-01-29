#include <stdio.h>

int main(){
	int a[8], b[8] = {0};
	for (int i = 0; i < 8; i++){
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	for (int i = 0; i < 8; i++){
		int x;
		scanf("%d", &x);
		for (int j = 0; j < 8; j++){
			if (a[j] == x && b[i] == 0){
				b[i] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < 8; i++){
		if (b[i] == 0){
			printf("%s", "no");
			return 0;
		}
	}
	printf("%s", "yes");
	
	
	return 0;
}