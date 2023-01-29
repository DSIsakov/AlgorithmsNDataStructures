#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
	if (argc != 4){
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	int h = atoi(argv[1]), w = atoi(argv[2]);
	char *text = argv[3];
	if (strlen(text) > w - 2 || h < 3){
		printf("Error");
		return 0;
	}
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			if (i == 0 || i == h-1){
				printf("*");
				continue;
			}
			if (j == 0 || j == w - 1){
				printf("*");
				continue;
			}
			if (i == (h-1) / 2 && j >= (w - 1) / 2 - strlen(text) / 2 && j <= (w - 1) / 2 + (strlen(text) - 1) / 2){
				printf("%c", text[j - (w - 1) / 2 + strlen(text) / 2]);
				continue;
			}
			printf(" ");
		}
		printf("\n");
	}
	
	
	return 0;
}