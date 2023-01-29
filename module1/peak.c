#include <stdio.h>


unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)){
	if (nel == 1){
		return 0;
	}
	for (unsigned long k = 0; k < nel; k++){
		if (k == 0){
			if (less(0, 1) == 0){
				return 0;
			}
		}
		else if (k == nel - 1){
			if (less(k, k-1) == 0){
				return k;
			}
		}
		else{
			if (less(k, k-1) == 0 && less(k, k+1) == 0){
				return k;
			}
		}
	}
}


int l(unsigned long i, unsigned long j){
	int array[10] = {1,2,7,9,45,45,56,67,2,4};
	if (array[i] < array[j]){
		return 1;
	}
	return 0;
}


int main(){
	int (*less)(unsigned long i, unsigned long j);
	less = l;
	int c = peak(10, l);
	printf("%d", c);
	
	
	return 0;
}