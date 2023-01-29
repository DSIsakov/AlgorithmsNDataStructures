#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (a > b) ? a : b


typedef struct DoubleStack{
	int top1, top2, cap;
	int *data;
} sq;


sq InitQueue(){
	sq queue;
	queue.cap = 200000;
	queue.top1 = 0;
	queue.top2 = 199999;
	queue.data = (int*)calloc(queue.cap, sizeof(int));
	
	return queue;
}


int empty1(sq* queue){
	return queue->top1 == 0;
}


int empty2(sq* queue){
	return queue->top2 == queue->cap-1;
}


int QueueEmpty(sq* queue){
	return empty1(queue) && empty2(queue);
}


void push1(sq* queue, int x){
	queue->data[queue->top1++] = x;
}


void push2(sq* queue, int x){
	queue->data[queue->top2--] = x;
}


int pop1(sq* queue){
	return queue->data[--queue->top1];
}


int pop2(sq* queue){
	return queue->data[++queue->top2];
}


void enq(sq* queue, int x){
	push1(queue, x);
}


int deq(sq* queue){
	if (empty2(queue)){
		while (!empty1(queue)){
			push2(queue, pop1(queue));
		}
	}
	
	return pop2(queue);
}


int get_right(sq* queue){
	if (empty1(queue)){
		return queue->data[queue->cap - 1];
	}
	else{
		return queue->data[queue->top1 - 1];
	}
}


int get_left(sq* queue){
	if (empty2(queue)){
		return queue->data[0];
	}
	else{
		return queue->data[queue->top2 + 1];
	}
}


void pop_right(sq* queue){
	if (empty1(queue)){
		for (int i = queue->cap - 1; i > queue->top2; i--){
			queue->data[i] = queue->data[i-1];
		}
		pop2(queue);
	}
	else{
		pop1(queue);
	}
}


void Enqueue(sq* queue, sq* qmax, int x){
	if (QueueEmpty(queue)){
		enq(queue, x);
		enq(qmax, x);
	}
	else{
		enq(queue, x);
		while (!QueueEmpty(qmax) && get_right(qmax) < x){
			pop_right(qmax);
		}
		enq(qmax, x);
	}
}


int Dequeue(sq* queue, sq* qmax){
	if (get_left(queue) == get_left(qmax)){
		deq(qmax);
	}
	return deq(queue);
}


int Maximum(sq* queue){
	return get_left(queue);
}


int main(){
	sq queue = InitQueue();
	sq qmax = InitQueue();
	char s[6];
	while (1) {
		scanf("%s", s);
		if (!strcmp(s, "ENQ")){
			int x;
			scanf("%d", &x);
			Enqueue(&queue, &qmax, x);
		}
		else if (!strcmp(s, "DEQ")){
			int x = Dequeue(&queue, &qmax);
			printf("%d\n", x);
		}
		else if (!strcmp(s, "MAX")){
			printf("%d\n", Maximum(&qmax));
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
	free(qmax.data);
}