#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
	char *s = argv[1];
	int len = strlen(s), t = 0;
	int p[len];
	p[0] = 0;
	for (int i = 1; i < len; i++){
		while (t > 0 && s[t] != s[i]){
			t = p[t-1];
		}
		if (s[t] == s[i]){
			t++;
		}
		p[i] = t;
	}
	for (int i = 0; i < len; i++){
		if ((i+1) % (i+1 - p[i]) == 0 && (i+1) / (i+1 - p[i]) != 1){
			printf("%d %d\n", i+1, (i+1) / (i+1 - p[i]));
		}
	}
}