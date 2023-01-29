#include <stdio.h>
#include <stdlib.h>


int gcd(int a, int b){
	while (a > 0 && b > 0){
		if (a > b){
			a %= b;
		}
		else{
			b %= a;
		}
	}
	return (a > b) ? a : b;
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
			return gcd(query(t, l, r, a, m, cur * 2), query(t, l, r, m+1, b, cur * 2 + 1));
		}
	}
}


void build(int *arr, int a, int b, int *t, long cur){
	if (a==b){
		t[cur] = arr[a];
	}
	else{
		int m = (a+b) / 2;
		build(arr, a, m, t, cur * 2);
		build(arr, m+1, b, t, cur * 2 + 1);
		t[cur] = gcd(t[cur * 2], t[cur * 2 + 1]);
	}
}


// void update(int i, int v, int a, int b, int *t, int cur){
// 	if (a==b){
// 		t[cur] = v;
// 	}
// 	else{
// 		int m = (a+b) / 2;
// 		if (i <= m){
// 			update(i, v, a, m, t, cur * 2);
// 		}
// 		else{
// 			update(i, v, m+1, b, t, cur * 2 + 1);
// 		}
// 		t[cur] = gcd(t[cur * 2], t[cur * 2 + 1]);
// 	}
// }
// 
// 
// void segmentTree_Update(int i, int v, int n, int *t){
// 	update(i, v, 0, n-1, t, 1);
// }


int main(){
	int n, m;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		arr[i] = abs(arr[i]);
	}
	int *t = (int*)calloc((n+1) * 4, sizeof(int));
	build(arr, 0, n-1, t, 1);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		int v = query(t, l, r, 0, n-1, 1);
		printf("%d\n", v);
	}
	free(t);
}