#include <stdio.h>

int main()
{
	unsigned long long a, b, m, fun = 0;
	int c = 0;
	scanf("%llu %llu %llu", &a, &b, &m);
	
	for (unsigned long long i = 1; i < b; i = 2 * i){
		c++;
	}
	
	int coef[c];
	
	for (int i = 1; i <= c; i++){
		coef[c-i] = b % 2;
		b /= 2;
	}
	
	for (int i = 0; i < c - 1; i++){
		fun = ((fun % m + (a * coef[i]) % m) % m * 2) % m;
	}
	
	fun = (fun + a * coef[c-1]) % m;
	
	printf("%llu", fun);
	
	
	return 0;
}