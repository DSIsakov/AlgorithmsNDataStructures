#include <stdio.h>
#include <stdlib.h>


void insertsort(int *p, int start, int end){
	for (int i = start + 1; i <= end; i++){
		int elem = p[i];
		int loc;
		for (loc = i - 1; loc >= 0 && abs(p[loc]) > abs(elem); loc--){
			p[loc + 1] = p[loc];
		}
		p[loc + 1] = elem;
	}
}


void merge(int start, int m, int end, int *p){
	int t[end - start + 1], i = start, j = m + 1, h;
	for (h = 0; h < end - start + 1; h++){
		if (j <= end && (i == m + 1 || abs(p[j]) < abs(p[i]))){
			t[h] = p[j];
			j++;
		}
		else{
			t[h] = p[i];
			i++;
		}
	}
	for (i = start; i <= end; i++){
		p[i] = t[i - start];
	}
}


void mergesort_rec(int start, int end, int *p, int n){
	if (end - start > 5){
		int m = (start + end) / 2;
		mergesort_rec(start, m, p, n);
		mergesort_rec(m, end, p, n);
		merge(start, m, end, p);
	}
	else{
		insertsort(p, start, end);
	}
}


int main(){
	int n;
	scanf("%d", &n);
	int p[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	mergesort_rec(0, n-1, p, n);
	
	for (int i = 0; i < n; i++){
		printf("%d ", p[i]);
	}
}