#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL){
		printf("Memory allocation failed!\n");
		return;
	}
	q->front = NULL;
	q->rear = NULL;
	return q;
}

bool isFull(Queue* q){
	return false;
}
bool isEmpty(Queue* q){
	return (q->front == NULL);
}
void enqueue(Queue* q, int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->next = NULL;
	// check if queue is empty
	if(isEmpty(q)){
		// reset the front and rear
		q->front = newNode;
		q->rear = newNode;
	}else{
		q->rear->next = newNode; 
		q->rear = newNode;
	}
	printf("%d enqueue to queue.\n", value);
}
int dequeue(Queue* q){
	//check if queue is empty
	if(isEmpty(q)){
		printf("Queue is empty.\n");
		return -1;
	}	
	Node *temp = q->front;
	int value = temp->data;
	
	q->front = q->front->next;
	if(q->front == NULL){
		q->rear = NULL;
	}
	
	free(temp);
	return value;
}

int front(Queue* q){
	// check if queue is empty
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return -1;
	}
	return q->front->data;
}

void display(Queue* q){
	// check if queue is empty
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return;
	}
	
	Node *trav = q->front;
	while(trav != NULL){
		printf("%d ", trav->data);
		trav = trav->next;
	}
	printf("\n");
}



int main(){
	Queue* Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);

    display(Q);

    printf("Front element is %d\n", front(Q));

    printf("Dequeued element: %d\n", dequeue(Q));
    display(Q);

    enqueue(Q, 4);
    display(Q);
	
	return 0;
}
