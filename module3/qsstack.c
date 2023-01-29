#include <stdio.h>
#include <stdlib.h>


struct Task{ 
	int low, high; 
};


struct TaskStack{
	int cap, top;
	struct Task *tasks;
};


void init(int n, struct TaskStack *stack){
	stack->cap = n+1;
	stack->top = 0;
	stack->tasks = (struct Task*)calloc(stack->cap, sizeof(struct Task));
}


int isempty(struct TaskStack *stack){
	return stack->top == 0;
}


void push(struct TaskStack *stack, struct Task task){
	stack->tasks[stack->top++] = task;
}


struct Task pop(struct TaskStack *stack){
	return stack->tasks[--stack->top];
}


int partition(int low, int high, int *p){
	int i = low;
	for (int j = low; j < high; j++){
		if (p[j] < p[high]){
			int temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			i++;
		}
	}
	int temp = p[i];
	p[i] = p[high];
	p[high] = temp;
	
	
	return i;
}


void quicksort(int low, int high, int *p){
	struct TaskStack stack;
	init(high - low + 1, &stack);
	struct Task task;
	task.low = low;
	task.high = high;
	push(&stack, task);
	while (!isempty(&stack)) {
		task = pop(&stack);
		int low = task.low;
		int high = task.high;
		if (low < high){
			int q = partition(low, high, p);
			task.low = low;
			task.high = q - 1;
			push(&stack, task);
			task.low = q + 1;
			task.high = high;
			push(&stack, task);
		}
	}
	free(stack.tasks);
}


int main(){
	int n;
	scanf("%d", &n);
	int p[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	quicksort(0, n-1, p);
	for (int i = 0; i < n; i++){
		printf("%d ", p[i]);
	}
}