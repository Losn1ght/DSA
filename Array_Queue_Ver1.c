#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
typedef struct{
	int items[MAX];
	int count;
}List;

typedef struct{
	List list;
	int front;
	int rear;
}Queue;

Queue* initialize(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(q== NULL){
		printf("Memory allocation failed!\n");
		return;
	}
	q->front = -1;
	q->rear = -1;
	q->list.count = 0;
	return q;
}

bool isFull(Queue* q){
	return q->list.count == MAX -1;
}

bool isEmpty(Queue* q){
	return q->list.count == 0;
}

void enqueue(Queue* q, int value){
	// check if queue is full
	if(isFull(q)){
		printf("Queue is full. Please try again.\n");
		return;
	}
	
	if(isEmpty(q)){
		q->front = 0;
		q->rear = 0;
	}else{
		q->rear = (q->rear + 1) % MAX;	
	}
	q->list.items[q->rear] = value;
	q->list.count++;
}

int dequeue(Queue* q){
	// check if queue is empty
	if(isEmpty(q)){
		printf("Queue is empty. Please try again.\n");
		return -1;
	}
	int value = q->list.items[q->front];
	
	if(q->list.count == 1){ // if this is the last element in the queue
		// reset queue to empty state
		q->front = -1;
		q->rear = -1;
	}else{ // update the front pointer circularly
		q->front = (q->front + 1) % MAX;
	}
	
	q->list.count--;
	return value;
}

// Return the value at the front of queue
int front(Queue* q){
	// check if queue is empty
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return -1;
	}
	
	return q->list.items[q->front];
}

void display(Queue* q){
	// check if queue is empty
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return;
	}
	
	// loop queue from front to rear
	int i;
	printf("Queue elements: ");
	for(i = 0; i < q->list.count; i++){
		int index  = (q->front + i) % MAX;
		printf("%d ", q->list.items[index]);
	}
	printf("\n");
}


int main() {
    Queue* q = initialize();

    // Test 1: Dequeue on empty queue
    printf("Test 1: Dequeue on empty queue\n");
    dequeue(q);

    // Test 2: Front on empty queue
    printf("Test 2: Front on empty queue\n");
    front(q);

    // Test 3: Enqueue some elements
    printf("Test 3: Enqueue elements 10, 20, 30\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);  // Expected: 10 20 30

    // Test 4: Dequeue one element
    printf("Test 4: Dequeue one element\n");
    printf("Dequeued: %d\n", dequeue(q));  // Expected: 10
    display(q);  // Expected: 20 30

    // Test 5: Enqueue more elements to test wrap-around
    printf("Test 5: Enqueue more elements to test wrap-around\n");
    int i;
	for( i = 40; i <= 100; i += 10){
        enqueue(q, i);
    }
    display(q);

    // Test 6: Attempt to enqueue when full
    printf("Test 6: Attempt to enqueue when full\n");
    enqueue(q, 110);  // Should show full message

    // Test 7: Dequeue all elements
    printf("Test 7: Dequeue all elements\n");
    while (!isEmpty(q)) {
        printf("Dequeued: %d\n", dequeue(q));
    }
    display(q);  // Expected: Queue is empty

    // Test 8: Enqueue after clearing
    printf("Test 8: Enqueue after clearing queue\n");
    enqueue(q, 999);
    display(q);  // Expected: 999

    // Clean up
    free(q);
    return 0;
}

