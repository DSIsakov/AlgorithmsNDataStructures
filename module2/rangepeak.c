#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int peak(int *arr, int n, int a, int b){
	int count = 0;
	for (int i = a; i <= b; i++){
		if (i == 0 && arr[i] >= arr[i+1]){
			count++;
		}
		else if (i == n-1 && arr[i] >= arr[i-1]){
			count++;
		}
		else{
			if (i < n-1 && i > 0 && arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
				count++;
			}
		}
	}
	
	return count;
}


int query(int *t, int l, int r, int a, int b, long cur){
	if (l <= a && b <= r){
		return t[cur];
	}
	else{
		int m = (a+b) / 2;
		if (r <= m){
			return query(t, l, r, a, m, cur * 2);
		}
		else if (l > m){
			return query(t, l, r, m+1, b, cur * 2 + 1);
		}
		else{
			return query(t, l, r, a, m, cur * 2) + query(t, l, r, m+1, b, cur * 2 + 1);
		}
	}
}


void build(int *arr, int a, int b, int *t, long cur, int n){
	if (a == b){
		t[cur] = peak(arr, n, a, b);
	}
	else{
		int m = (a+b) / 2;
		build(arr, a, m, t, cur * 2, n);
		build(arr, m+1, b, t, cur * 2 + 1, n);
		t[cur] = t[cur * 2] + t[cur * 2 + 1];
	}
}


void update(int i, int *arr, int a, int b, int *t, long cur, int n){
	if (a == b && i == a){
		t[cur] = peak(arr, n, a, b);
	}
	else{
		int m = (a+b) / 2;
		if (i <= m){
			update(i, arr, a, m, t, cur * 2, n);
		}
		else{
			update(i, arr, m+1, b, t, cur * 2 + 1, n);
		}
		t[cur] = t[cur * 2] + t[cur * 2 + 1];
	}
}


int main(){
	int n, m;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int *t = (int*)calloc((n+1) * 4, sizeof(int));
	build(arr, 0, n-1, t, 1, n);
	while (1){
		char cmnd[5];
		int l, r;
		scanf("%s", cmnd);
		if (strcmp(cmnd, "END") == 0){
			break;
		}
		scanf("%d %d", &l, &r);
		if (strcmp(cmnd, "PEAK") == 0){
			int count = query(t, l, r, 0, n-1, 1);
			printf("%d\n", count);
		}
		else if (strcmp(cmnd, "UPD") == 0){
			arr[l] = r;
			if (l > 0){
				update(l-1, arr, 0, n-1, t, 1, n);
			}
			if (l < n-1){
				update(l+1, arr, 0, n-1, t, 1, n);
			}
			update(l, arr, 0, n-1, t, 1, n);
		}
	}
	free(t);
}