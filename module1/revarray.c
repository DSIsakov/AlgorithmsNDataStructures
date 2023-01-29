#include <stdio.h>


void swap(char* px, char* py)
{
	char temp;
	temp = *px;
	*px = *py;
	*py = temp;
}


void revarray(void *base, size_t nel, size_t width){
	for (size_t i = 0; i < nel / 2; i++){
		for (size_t j = 0; j < width; j++){
			swap((char*)base + i * width + j, (char*)base + (nel - i - 1) * width + j);
		}
	}
}