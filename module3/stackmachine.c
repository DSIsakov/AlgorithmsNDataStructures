#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack{
	int cap, top;
	long *nums;
} ss;


void init(ss *stack){
	stack->top = 0;
	stack->cap = 1000000;
	stack->nums = (long*)calloc(stack->cap, sizeof(long));
}


int isempty(ss *stack){
	return stack->top == 0;
}


void push(ss *stack, long num){
	stack->nums[stack->top++] = num;
}


long pop(ss *stack){
	return stack->nums[--stack->top];
}


void add(ss *stack){
	long a = pop(stack);
	long b = pop(stack);
	push(stack, a + b);
}


void sub(ss *stack){
	long a = pop(stack);
	long b = pop(stack);
	push(stack, a - b);
}


void mul(ss *stack){
	long a = pop(stack);
	long b = pop(stack);
	push(stack, a * b);
}


void divv(ss *stack){
	long a = pop(stack);
	long b = pop(stack);
	push(stack, a / b);
}


void max(ss *stack){
	long a = pop(stack);
	long b = pop(stack);
	push(stack, (a > b) ? a : b);
}


void min(ss *stack){
	long a = pop(stack);
	long b = pop(stack);
	push(stack, (a < b) ? a : b);
}


void neg(ss *stack){
	long a = pop(stack);
	push(stack, a * -1);
}


void dup(ss *stack){
	long a = pop(stack);
	push(stack, a);
	push(stack, a);
}


void swap(ss *stack){
	long a = pop(stack);
	long b = pop(stack);
	push(stack, a);
	push(stack, b);
}


int main(){
	ss stack;
	init(&stack);
	while (1) {
		char s[6];
		scanf("%s", s);
		if (!strcmp(s, "CONST")){
			long x;
			scanf("%ld", &x);
			push(&stack, x);
		}
		else if (!strcmp(s, "ADD")){
			add(&stack);
		}
		else if (!strcmp(s, "SUB")){
			sub(&stack);
		}
		else if (!strcmp(s, "MUL")){
			mul(&stack);
		}
		else if (!strcmp(s, "DIV")){
			divv(&stack);
		}
		else if (!strcmp(s, "MAX")){
			max(&stack);
		}
		else if (!strcmp(s, "MIN")){
			min(&stack);
		}
		else if (!strcmp(s, "NEG")){
			neg(&stack);
		}
		else if (!strcmp(s, "DUP")){
			dup(&stack);
		}
		else if (!strcmp(s, "SWAP")){
			swap(&stack);
		}
		else {
			printf("%ld", pop(&stack));
			break;
		}
	}
	free(stack.nums);
}