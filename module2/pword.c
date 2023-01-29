#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){
	char *s1 = argv[1], *s2 = argv[2];
	int len1 = strlen(s1), len2 = strlen(s2);
	int t = 0, p[len1];
	p[0] = 0;
	for (int i = 1; i < len1; i++){
		while (t > 0 && s1[t] != s1[i]){
			t = p[t-1];
		}
		if (s1[t] == s1[i]){
			t++;
		}
		p[i] = t;
	}
	
	t = 0;
	for (int i = 0; i < len2; i++){
		while (t > 0 && s1[t] != s2[i]){
			t = p[t-1];
		}
		if (s1[t] == s2[i]){
			t++;
		}
		if (t == 0){
			printf("no");
			return 0;
		}
		if (t == len1){
			t = p[t-1];
		}
	}
	printf("yes");


	return 0;
}