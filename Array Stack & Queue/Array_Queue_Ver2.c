#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
typedef struct{
	int items[MAX];
	int rear;
	int front;
}Queue;

Queue* initialize(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	q->front = 1;
	q->rear = 0;
	return q;
}
bool isEmpty(Queue* q){
	return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q){
	return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q, int value){
	// check queue if full
	if(isFull(q)){
		printf("Queue is full!\n");
		return;
	}
	
	q->rear = (q->rear + 1) % MAX;
	q->items[q->rear] = value;
}

int dequeue(Queue* q){
	// check queue if empty
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return -1;
	}
	int value = q->items[q->front];
	q->front = (q->front + 1) % MAX;
	return value;
}

int front(Queue* q){
	// check if queue is empty
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return -1;
	}
	return q->items[q->front];
}

void display(Queue* q){
	// check if queue is empty
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return;
	}
	int i = q->front;
	printf("Queue elements: ");
	while(i != (q->rear + 1) % MAX){
		printf("%d ", q->items[i]);
		i = (i + 1) % MAX;
	}

	printf("\n");
}



int main(){
	Queue* Q = initialize();

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    display(Q); // Expected: 10 20 30 40

    printf("Front: %d\n", front(Q)); // Expected: 10

    printf("Dequeued: %d\n", dequeue(Q)); // Expected: 10
    display(Q); // Expected: 20 30 40

    enqueue(Q, 50);
    enqueue(Q, 60);
    display(Q);

	
	return 0;
}
