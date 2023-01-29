#include <stdio.h>

int main(){
	int n, k;
	long long sum = 0, maxsum, prevsum;
	scanf("%d", &n);
	long arr[n];
	for (int i = 0; i < n; i++){
		scanf("%ld", &arr[i]);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		sum += arr[i];
	}
	maxsum = sum;
	for (int i = k; i < n; i++){
		sum -= arr[i-k];
		sum += arr[i];
		maxsum = (maxsum > sum) ? maxsum : sum;
	}
	printf("%lld", maxsum);
	
	
	return 0;
}