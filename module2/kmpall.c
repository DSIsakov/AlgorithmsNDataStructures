#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int *prefix(char *s){
	int len = strlen(s), *p = (int*)calloc(len, sizeof(int)), t = 0;
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
	
	return p;
}


int *kmosubst(char* s, char* t){
	int *p = prefix(s), q = 0, k, lent = strlen(t), lens = strlen(s), *inds = (int*)calloc(lent, sizeof(int)), count = 0;
	
	for (k = 0; k < lent; k++){
		inds[k] = -1;
		while (q > 0 && s[q] != t[k]){
			q = p[q-1];
		}
		if (s[q] == t[k]){
			q++;
		}
		if (q == lens){
			inds[count++] = k - lens + 1;
		}
	}
	
	free(p);
	
	return inds;
}


int main(int argc, char** argv){
	char *s = argv[1];
	char *t = argv[2];
	int *inds = kmosubst(s, t);
	
	for (int i = 0; i < strlen(t) && inds[i] >= 0; i++){
		printf("%d ", inds[i]);
	}
	
	free(inds);
}