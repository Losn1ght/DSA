#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int items[MAX];
	int top;
}Stack;

Stack* initialize(){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s == NULL){
		printf("Memory allocation failed!\n");
	}
	s->top = -1;
	return s;
}

bool isFull(Stack* s){
	return s->top == MAX - 1;
}

bool isEmpty(Stack* s){
	return s->top == -1;	
}

void push(Stack* s, int value){
	// check if the stack is full
	if(isFull(s)){
		printf("Stack is full!\n");
		return;
	}
	s->top++;
	s->items[s->top] = value;
}


int pop(Stack* s){
	// check if stack is empty
	if(isEmpty(s)){
		printf("Stack is empty!\n");
		return -1;
	}
	// need to return the value of removed element
	int value = s->items[s->top];
	s->top--;
	return value;
}

// Peek/Return the top value
int peek(Stack* s){
	// check if stack empty
	if(isEmpty(s)){
		printf("Stack is empty!\n");
		return -1;
	}
	return s->items[s->top];	
}

// Return the index of top
int top(Stack *s){
	return s->top;
}

void display(Stack* s){
	//check if Stack is empty
	if(isEmpty(s)){
		printf("Stack is empty!\n");
		return;
	}
	
	// start from the top
	int i = s->top;
	while(i >= 0){
		printf("%d ", s->items[i]);
		i--;
	}
	printf("\n");
	
}



int main(){
	 Stack* S = initialize();

    push(S, 10);
    push(S, 20);
    push(S, 30);
    display(S); // 30 20 10

    printf("Top element: %d\n", peek(S));

    int popped = pop(S);
    printf("Popped: %d\n", popped);
    display(S); // 20 10

    printf("Current top index: %d\n", top(S));

    free(S);
	
	return 0;
}


