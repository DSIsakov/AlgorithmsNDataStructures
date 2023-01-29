#include <stdio.h>
#include <stdlib.h>
#define qh(i) queue->heap[i]
#define i2 (i-1)/2


typedef struct Elem{
	int t1, t2, end;
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


void initelem(se *elem, int t1, int t2){
	elem->t1 = t1;
	elem->t2 = t2;
	elem->end = t1+t2;
}


void insert(sq *queue, se elem){
	int i = queue->count++;
	queue->heap[i] = elem;
	while (i > 0 && qh(i2).end > qh(i).end){
		se temp = qh(i);
		qh(i) = qh(i2);
		qh(i2) = temp;
		i = i2;
	}
}


void heapify(int i, int n, sq *queue){
	int l, r, j;
	se temp;
	while (1){
		l = 2*i + 1;
		r = l + 1;
		j = i;
		if (l < n && qh(i).end > qh(l).end){
			i = l;
		}
		if (r < n && qh(i).end > qh(r).end){
			i = r;
		}
		if (i == j){
			break;
		}
		temp = qh(i);
		qh(i) = qh(j);
		qh(j) = temp;
	}
}


se extractmax(sq *queue){
	se elem = qh(0);
	queue->count--;
	if (queue->count > 0){
		qh(0) = qh(queue->count);
		heapify(0, queue->count, queue);
	}
	
	return elem;
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	sq queue;
	se task;
	init(&queue, n);
	initelem(&task, 0, 0);
	for (int i = 0; i < n; i++){
		insert(&queue, task);
	}
	
	int t1, t2;
	for (int i = 0; i < m; i++){
		task = extractmax(&queue);
		scanf("%d %d", &t1, &t2);
		if (task.end < t1){
			task.end += t1 - task.t1;
			task.t1 = t1;
		}
		else {
			task.t1 += task.t2;
			task.end += task.t2;
		}
		task.end += t2 - task.t2;
		task.t2 = t2;
		insert(&queue, task);
	}
	
	int endtime = 0;
	for (int i = 0; i < n; i++){
		endtime = (queue.heap[i].end > endtime) ? queue.heap[i].end : endtime;
	}
	
	printf("%d\n", endtime);
	free(queue.heap);
}