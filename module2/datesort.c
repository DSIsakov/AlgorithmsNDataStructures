#include <stdio.h>


struct Date {
	int Day, Month, Year;
};


int main(){
	int n;
	scanf("%d", &n);
	struct Date a[n+1];
	a[0].Year = 0, a[0].Month = 0, a[0].Day = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d %d %d", &a[i].Year, &a[i].Month, &a[i].Day);
		struct Date temp = a[i];
		for (int j = i-1; j >= 0; j--){
			if (temp.Year * 10000 + temp.Month * 100 + temp.Day >= a[j].Year * 10000 + a[j].Month * 100 + a[j].Day){
				a[j+1] = temp;
				break;
			}
			else{
				a[j+1] = a[j];
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		printf("%04d %02d %02d\n", a[i].Year, a[i].Month, a[i].Day);
	}
	
	
	return 0;
}