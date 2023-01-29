#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void csort(char *src, char *dest){
	int n = 0;
	int *count = (int*)calloc(n+1, sizeof(int));
	int *sizes = (int*)calloc(n+1, sizeof(int));
	char *source = (char*)calloc(strlen(src)+1, sizeof(char));
	char **words = (char**)calloc(n+1, sizeof(char*));
	strcpy(source, src);
	char *word = strtok(source, " ");
	
	while (word){
		count[n] = 0;
		sizes[n] = strlen(word);
		words[n] = (char*)calloc(sizes[n]+1, sizeof(char));
		strcpy(words[n], word);
		for (int i = n-1; i >= 0; i--){
			if (sizes[n] >= sizes[i]){
				count[n]++;
			}
			else{
				count[i]++;	
			}
		}
		n++;
		count = (int*)realloc(count, (n+1) * sizeof(int));
		sizes = (int*)realloc(sizes, (n+1) * sizeof(int));
		words = (char**)realloc(words, (n+1) * sizeof(char*));
		word = strtok(NULL, " ");
	}
	
	char **sorted_words = (char**)calloc(n, sizeof(char*));

	for (int i = 0; i < n; i++){
		sorted_words[count[i]] = (char*)calloc(sizes[i]+1, sizeof(char));
		strcpy(sorted_words[count[i]], words[i]);
		free(words[i]);
	}
	
	free(words);
	
	if (n){
		strcpy(dest, sorted_words[0]);
		free(sorted_words[0]);
		for (int i = 1; i < n; i++){
			strcat(dest, " ");
			strcat(dest, sorted_words[i]);
			free(sorted_words[i]);
		}
	}
	
	free(sizes);
	free(count);
	free(sorted_words);
	free(source);
}


int main(){
	char* src = (char*)calloc(10001, sizeof(char));
	gets(src);
	char *dest = (char*)calloc(strlen(src)+1, sizeof(char));
	
	csort(src, dest);
	
	printf("%s", dest);
	free(src);
	free(dest);
}