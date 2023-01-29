#include <stdio.h>
#include <stdlib.h>
#define qh(i) queue->heap[i]
#define i2 (i-1)/2


typedef struct Elem{
	int index, value, priority;
} se;


typedef struct PriorityQueue{
	se *heap;
	int cap, count;	
} sq;


void init(sq *queue, int n){
	queue->cap = n;
	queue->count = 0;
	queue->heap = (se*)calloc(n, sizeof(se));
}


void initelem(se *elem, int index, int value, int priority){
	elem->index = index;
	elem->value = value;
	elem->priority = priority;
}


void insert(sq *queue, se elem){
	int i = queue->count++;
	queue->heap[i] = elem;
	while (i > 0 && qh(i2).value > qh(i).value){
		se temp = qh(i);
		qh(i) = qh(i2);		
		qh(i2 )= temp;
		qh(i).index = i;
		i = i2;
	}
	qh(i).index = i;
}


void heapify(int i, int n, sq *queue){
	int l, r, j;
	se temp;
	while (1){
		l = 2*i + 1;
		r = l + 1;
		j = i;
		if (l < n && qh(i).value > qh(l).value){
			i = l;
		}
		if (r < n && qh(i).value > qh(r).value){
			i = r;
		}
		if (i == j){
			break;
		}
		temp = qh(i);
		qh(i) = qh(j);
		qh(j) = temp;
		qh(i).index = i;
		qh(j).index = j;
	}
}


se extractmax(sq *queue){
	se elem = qh(0);
	queue->count--;
	if (queue->count > 0){
		qh(0) = qh(queue->count);
		qh(0).index = 0;
		heapify(0, queue->count, queue);
	}
	
	return elem;
}


int main(){
	int k;
	scanf("%d", &k);
	int n[k], *arr[k], fullsize = 0;
	
	for (int i = 0; i < k; i++){
		scanf("%d", &n[i]);
		arr[i] = (int*)calloc(n[i], sizeof(int));
		fullsize += n[i];
	}
	int *sorted = (int*)calloc(fullsize, sizeof(int)), cur = 0, curind[k];
	sq queue;
	init(&queue, fullsize);
	se elem;
	for (int i = 0; i < k; i++){
		for (int j = 0; j < n[i]; j++){
			scanf("%d", &arr[i][j]);
		}
		elem.value = arr[i][0];
		elem.priority = i;
		insert(&queue, elem);
		curind[i] = 0;
	}
	while (queue.count > 0){
		elem = extractmax(&queue);
		sorted[cur++] = elem.value;
		if (curind[elem.priority]++ < n[elem.priority] - 1){
			elem.value = arr[elem.priority][curind[elem.priority]];
			insert(&queue, elem);
		}
	}
	
	for (int i = 0; i < fullsize; i++){
		printf("%d ", sorted[i]);
	}
	
	for (int i = 0; i < k; i++){
		free(arr[i]);
	}
	free(queue.heap);
	free(sorted);
}