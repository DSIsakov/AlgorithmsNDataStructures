#include <stdio.h>


int main(){
	int n, l = 0, r = 0, start = 0;
	float prod = 1, maxprod = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		float a, b;
		scanf("%f/%f", &a, &b);
		// printf("%f ", a/b);
		if (prod < 1.0){
			prod = 1;
			start = i;
		}
		prod *= a / b;
		if (prod > maxprod){
			maxprod = prod;
			l = start;
			r = i;
		}
	}
	printf("%d %d", l, r);
}