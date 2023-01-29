#include <stdio.h>

int main(){
	unsigned long long x, i;
	scanf("%llu", &x);
	unsigned long long fib[160];
	fib[0] = 1;
	fib[1] = 1;
	for (i = 2; i < 160; i++){
		fib[i] = fib[i-1] + fib[i-2];
		if (fib[i] > x){
			break;
		}
	}
	for (i = i - 1; i > 0; i--){
		if (fib[i] <= x){
			printf("%d", 1);
			x -= fib[i];
		}
		else{
			printf("%d", 0);
		}
	}
	
	
	return 0;
}