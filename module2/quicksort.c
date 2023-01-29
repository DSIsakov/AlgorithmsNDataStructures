#include <stdio.h>


void selectsort(int* arr, int low, int high){
	int i, j, k;
	for (k = high; k > low; k--){
		j = k;
		for (i = k - 1; i >= low; i--){
			if (arr[i] > arr[j]){
				j = i;
			}
		}
		if (j != k){
			int temp = arr[k];
			arr[k] = arr[j];
			arr[j] = temp;
		}
	}
}


int partition(int* arr, int low, int high){
	int i = low, temp;
	for (int j = low; j < high; j++){
		if (arr[j] < arr[high]){
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
		}
	}
	temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;
	
	
	return i; 
}


void quicksort(int* arr, int low, int high, int m){
	if (low < high){
		if (high - low < m){
			selectsort(arr, low, high);
		}
		else{
			int q = partition(arr, low, high);
			quicksort(arr, low, q-1, m);
			quicksort(arr, q+1, high, m);
		}
	}
}


int main(){
	int n, m;
	scanf("%d", &n);
	int arr[n];
	scanf("%d", &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	quicksort(arr, 0, n-1, m);
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}