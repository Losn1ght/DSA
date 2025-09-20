#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Stack{
	Node* top;	
}Stack;

Stack* initialize(){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s == NULL){
		printf("Memory allocation failed!\n");
		return;
	}
	s->top = NULL;
	return s;
}

bool isFull(Stack* s){
	return false;
}

bool isEmpty(Stack* s){
	return (s->top == NULL);	
}

void push(Stack* s, int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("Memory allocation failed!\n");
		return;
	}
	
	newNode->data = value;
	newNode->next = s->top; // Link new node to current top
	s->top = newNode; // update top
	printf("%d pushed to stack.\n", value);
}

int pop(Stack* s){
	// check if stack is empty
	if(isEmpty(s)){
		printf("Stack is empty!\n");
		return -1;
	}
	Node *temp = s->top;
	int value = temp->data; // store the value to be popped 
	s->top = temp->next; // move top pointer to the next node
	free(temp); // free memory
	return value;
}

int peek(Stack* s){
	// check if stack is empty
	if(isEmpty(s)){
		printf("Stack is empty!\n");
		return -1;
	}
	
	return s->top->data;
}
void display(Stack* s){
	// check if stack is empty
	if(isEmpty(s)){
		printf("Stack is empty!\n");
		return;
	}
	printf("Stack elements (top to bottom): ");
	Node *trav = s->top;
	while(trav != NULL){
		printf("%d ", trav->data);
		trav = trav->next;
	}
	printf("\n");
}


int main(){
	Stack* s = initialize();

	push(s, 10);
	push(s, 20);
	push(s, 30);
	
	display(s);
	
	printf("Top element is %d\n", peek(s));
	
	printf("Popped element: %d\n", pop(s));
	display(s);
	
	
	
	return 0;
}
