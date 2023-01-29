#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Elem{
	int k, count;
	char *v;
	struct Elem *p, *l, *r;
} bt;


bt *init(int k, char* v){
	bt *tree = (bt*)malloc(sizeof(bt));
	tree->k = k;
	tree->v = v;
	tree->count = 0;
	tree->p = NULL;
	tree->l = NULL;
	tree->r = NULL;
	
	return tree;
}


bt *minimum(bt *t){
	bt* x;
	if (!t){
		x = NULL;
	}
	else{
		for (x = t; x->l; x = x->l){}
	}
	
	return x;
}


bt *succ(bt *x){
	bt* y;
	if (x->r){
		y = minimum(x->r);
	}
	else{
		y = x->p;
		while (y && x == y->r){
			x = y;
			y = y->p;
		}
	}
	
	return y;
}


bt *descend(bt* t, int k){
	bt *x = t;
	while (x && x->k != k){
		if (k < x->k){
			x = x->l;
		}
		else{
			x = x->r;
		}
	}
	return x;
}


char* lookup(bt* t, int k){
	return descend(t, k)->v;
}


void insert(bt* t, int k, char* v){
	bt* y = init(k, v);
	if (!t){
		t = y;
	}
	else{
		bt* x = t;
		while (1){
			x->count++;
			if (k < x->k){
				if (!x->l){
					x->l = y;
					y->p = x;
					break;
				}
				x = x->l;
			}
			else{
				if (!x->r){
					x->r = y;
					y->p = x;
					break;
				}
				x = x->r;
			}
		}
	}
}


bt *replace(bt* t, bt* x, bt* y){
	if (y){
		y->count = x->count;
	}
	if (t == x){
		t = y;
		if (y){
			y->p = NULL;
		}
	}
	else{
		bt* p = x->p;
		if (y){
			y->p = p;
		}
		if (p->l == x){
			p->l = y;
		}
		else{
			p->r = y;
		}
	}
	return t;
}


bt* delete(bt* t, int k){
	bt *x = descend(t, k);
	for (bt *y = x->p; y; y = y->p){
		y->count--;
	}
	if (!x->l && !x->r){
		t = replace(t, x, NULL);
	}
	else if (!x->l){
		t = replace(t, x, x->r);
	}
	else if (!x->r){
		t = replace(t, x, x->l);
	}
	else{
		bt *y = succ(x);
		t = replace(t, y, y->r);
		x->l->p = y;
		y->l = x->l;
		if (x->r){
			x->r->p = y;
		}
		y->r = x->r;
		t = replace(t, x, y);
	}
	free(x->v);
	free(x);
	
	return t;
}


char *search(bt* t, int k){
	bt* x = minimum(t);
	for (int i = 1; i <= k; i++){
		x = succ(x);
	}
	
	return x->v;
}


void freetree(bt* tree){
	if (tree->l){
		freetree(tree->l);
	}
	if (tree->r){
		freetree(tree->r);
	}
	free(tree->v);
	free(tree);
}


int main(){
	char query[7];
	bt* tree = NULL;
	while (1){
		scanf("%s", query);
		if (strcmp(query, "INSERT") == 0){
			int k;
			char* v = (char*)malloc(10);
			scanf("%d %s", &k, v);
			if (!tree){
				tree = init(k, v);
			}
			else{
				insert(tree, k, v);
			}
		}
		else if (strcmp(query, "LOOKUP") == 0){
			int k;
			scanf("%d", &k);
			char *v = lookup(tree, k);
			printf("%s\n", v);
		}
		else if (strcmp(query, "DELETE") == 0){
			int k;
			scanf("%d", &k);
			tree = delete(tree, k);
		}
		else if (strcmp(query, "SEARCH") == 0){
			int k;
			scanf("%d", &k);
			char *v = search(tree, k);
			printf("%s\n", v);
		}
		else{
			break;
		}
	}
	if (tree){
		freetree(tree);
	}
}