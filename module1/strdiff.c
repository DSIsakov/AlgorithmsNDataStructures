#include <stdio.h>
#include <string.h>


int strdiff(char *a, char *b){
	int c;
	int index = 0;
	for (int i = 0; i < strlen(a); i++){
		c = *(a + i) ^ *(b + i);
		for (int j = 0; j < 8; j++){
			if ((c >> j) & 1){
				return index;
			}
			index++;
		}
	}
	if (strlen(a) < strlen(b)){
		for (int i = index / 8; i < strlen(b); i++){
			c = *(b + i);
			for (int j = 0; j < 8; j++){
				if ((c >> j) & 1){
					return index;
				}
				index++;
			}
		}
	}
	return -1;
}


int main(){
	printf("%d", strdiff("The quick brown fox jumps over the lazy do", "The quick brown fox jumps over the lazy dog"));
}