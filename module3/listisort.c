#include <stdio.h>
#include <stdlib.h>
#define p printf("hahaha\n")


typedef struct Elem { 
	struct Elem *prev, *next; 
	int v; 
} se;


se *init(){
	se *list;
	list = (se*)malloc(sizeof(se));
	list->prev = list;
	list->next = list;
	
	return list;
}


int isempty(se *list){
	return list->next == list;
}


int len(se *list){
	int len = 0;
	se *x = list;
	while (x->next != list){
		len++;
		x = x->next;
	}
	
	return len;
}


se search(se *list, int v){
	se *x = list->next;
	while (x != list && x->v != v){
		x = x->next;
	}
	
	return *x;
}


void insertafter(se *exist, se *y){
	se *z = exist->next;
	exist->next = y;
	y->prev = exist;
	y->next = z;
	z->prev = y;
}


void delete(se *x){
	se *y = x->prev;
	se *z = x->next;
	y->next = z;
	z->prev = y;
	x->prev = NULL;
	x->next = NULL;
}


void insertsort(se *list){
	for (se *i = list->next; i != list; i = i->next){
		int elem = i->v;
		se *loc = i->prev;
		while (loc != list && loc->v > elem){
			loc = loc->prev;
		}
		delete(i);
		insertafter(loc, i);
	}
}


int main(){
	int n;
	scanf("%d", &n);
	se *list = init();
	for (int i = 0; i < n; i++){
		se *elem = init();
		scanf("%d", &elem->v);
		insertafter(list, elem);
	}
	insertsort(list);
	for (int i = 0; i < n; i++){
		se *elem = list->next;
		printf("%d ", elem->v);
		delete(elem);
		free(elem);
	}
	free(list);
}
