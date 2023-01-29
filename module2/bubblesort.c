void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)){
	unsigned long start, i;
	for (start = 0; start < nel / 2; start++){
		for (i = start; i < nel - start - 1; i++){
			if (compare(i, i + 1) > 0){
				swap(i, i+1);
			}
		}
		for (i; i > 0; i--){
			if (compare(i, i-1) < 0){
				swap(i, i-1);
			}
		}
	}
}