#include <stdio.h>
#include <math.h>

int main(){
	long na, nb;
	long p, c = 0;
	unsigned int a = 0, b = 0;
	const unsigned long cons = pow(2, 31);
	scanf("%ld", &na);
	for (int i = 0; i < na; i++){
		int x;
		scanf("%d", &x);
		a += pow(2, x);
	}
	scanf("%ld", &nb);
	for (int i = 0; i < nb; i++){
		int x;
		scanf("%d", &x);
		b += pow(2, x);
	}
	for (int i = 31; i >= 0; i--){
		p = pow(2, i);
		if (p <= a){
			a -= p;
			if (p <= b){
				c += (cons / p);
			}
		}
		if (p <= b){
			b -= p;
		}
	}
	for (int i = 31; i >= 0; i--){
		p = pow(2, i);
		if (p <= c){
			c -= p;
			printf("%d ", 31 - i);
		}
	}
	
	
	return 0;
}