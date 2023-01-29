#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct CircleBufQueue{
	long count, head, tail, cap;
	int *data;
} sq;


void InitQueue(sq *queue){
	queue->count = 0;
	queue->head = 0;
	queue->tail = 0;
	queue->cap = 4;
	queue->data = (int*)calloc(4, sizeof(int));
}


int QueueEmpty(sq *queue){
	return queue->count == 0;
}


void DblBuff(sq *queue){
	int *temp = (int*)calloc(queue->cap * 2, sizeof(int));
	for (int i = queue->head; i < queue->cap; i++){
		temp[i - queue->head] = queue->data[i];
	}
	for (int i = 0; i < queue->tail; i++){
		temp[i + queue->cap - queue->head] = queue->data[i];
	}
	queue->head = 0;
	queue->tail = queue->cap;
	queue->cap *= 2;
	queue->data = (int*)realloc(queue->data, queue->cap * sizeof(int));
	for (int i = 0; i < queue->count; i++){
		queue->data[i] = temp[i];
	}
	free(temp);
}


void Enqueue(sq *queue, int x){
	if (queue->count == queue->cap){
		DblBuff(queue);
	}
	queue->data[queue->tail++] = x;
	if (queue->tail == queue->cap){
		queue->tail = 0;
	}
	queue->count++;
}


int Dequeue(sq *queue){
	queue->count--;
	int x = queue->data[queue->head++];
	if (queue->head == queue->cap){
		queue->head = 0;
	}
	
	return x;
}


int main(){
	sq queue;
	InitQueue(&queue);
	while (1) {
		char s[6];
		scanf("%s", s);
		if (!strcmp(s, "ENQ")){
			int x;
			scanf("%d", &x);
			Enqueue(&queue, x);
		}
		else if (!strcmp(s, "DEQ")){
			printf("%d\n", Dequeue(&queue));
		}
		else if (!strcmp(s, "EMPTY")){
			if (QueueEmpty(&queue)) {
				printf("true\n");
			}
			else{
				printf("false\n");
			}
		}
		else{
			break;
		}
	}
	free(queue.data);
}