#include <stdio.h>

int main(){
	long long n, x, fun, der;
	fun = 0;
	der = 0;
	
	scanf("%lld %lld", &n, &x);
	long coef[n+1];
	
	for (int i = 0; i < n; i++){
		scanf("%ld", &coef[i]);
		fun = (fun + coef[i]) * x;
		if (i == n-1){
			der = der + coef[i];
		}
		else{
			der = (der + coef[i] * (n - i)) * x;
		}
	}
	
	scanf("%ld", &coef[n]);
	fun += coef[n];
	
	printf("\n%lld %lld", fun, der);
	
	
	return 0;
}