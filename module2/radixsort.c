#include <stdio.h>


union Int32 { 
	int x; 
	unsigned char bytes[4]; 
};


void distributionSort(int m, union Int32* s, int n, int cur){
	int count[m], k, i, j;
	for (i = 0; i < m; i++){
		count[i] = 0;
	}
	for (j = 0; j < n; j++){
		k = s[j].bytes[cur];
		if(cur == 3) k ^= 128 ;
		count[k]++;
	}
	for (i = 1; i < m; i++){
		count[i] += count[i-1];
	}
	union Int32 d[n];
	for (j = n-1; j >= 0; j--){
		k = s[j].bytes[cur];
		if (cur == 3){
			k ^= 128;
		}
		i = --count[k];
		d[i] = s[j];
	}
	
	for (i = 0; i < n; i++){
		s[i] = d[i];
	}
}


void radixSort(int q, int m, union Int32 *s, int n){
	for (int i = 0; i < q; i++){
		distributionSort(m, s, n, i);
	}
}


int main(){
	int n;
	scanf("%d", &n);
	union Int32 arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i].x);
	}
	radixSort(4, 256, arr, n);
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i].x);
	}
}