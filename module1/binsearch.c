#include <stdio.h>


unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
	unsigned long left = -1, right = nel, mid, flag = 0;
	while (right - left > 1){
		mid = (left + right) / 2;
		if (compare(mid) == 1){
			right = mid;
		}
		else if(compare(mid) == -1){
			left = mid;
		}
		else{
			return mid;
		}
	}
	return nel;
}


int comp(unsigned long i){
	int array[8] = {1, 2, 30, 45, 50, 51, 55, 60}, k = 7;
	if (i > k){
		return 1;
	}
	else{
		if (i == k){
			return 0;
		}
		else{
			return -1;
		}
	}
}


int main(){
	int (*compare)(unsigned long i);
	compare = comp;
	int c = binsearch(8, compare);
	printf("%d", c);
	
	
	return 0;
}