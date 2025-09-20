#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
	int elem[MAX];
	int count;
}List;

List initialize(List L){
	L.count = 0;
	return L;	
}

void display(List L){
	int i;
	printf("List of elements: ");
	for( i = 0; i < L.count; i++){
		printf("%d ", L.elem[i]);
	}
	printf("\nCount: %d\n", L.count);
}

List insertPos(List L, int data, int position){
	// array must not be full
	if(L.count == MAX){
		printf("Error! List is full!\n");
		return;
	}
	
	// position must be valid
	if(position < 0 || position > L.count){
		printf("Error! Invalid Position!\n");
		return;
	}
	
	int i;
	// shift elements to the right
	for(i = L.count; i > position; i--){
		L.elem[i] = L.elem[i-1];
	}
	
	L.elem[position] = data;
	L.count++;
	return L;
}

List deletePos(List L, int position){
	// position must be valid
	if(position < 0 || position > L.count){
		printf("Error! Invalid Position!\n");
		return L;
	}
	int i;
	// shift elements to the left
	for( i = position; i < L.count - 1;i++){
		L.elem[i] = L.elem[i+1];
	}
	L.count--;
	return L;
}

List insertSorted(List L, int data){
	if(L.count == MAX){
		printf("Error! List is full!\n");
		return L;
	}
	
	int pos = 0;
	while(pos < L.count && L.elem[pos] < data){
		pos++;
	}
	
	L =	insertPos(L, data, pos);
	return L;
}

int locate(List L, int data){
	int i;
	for( i = 0; i < L.count; i++){
		if(L.elem[i] == data){
			return i;	
		}	
	 }
	 
	return -1;
}

int main() {
    List L;
    L = initialize(L);

    // Insert manually
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);

    display(L);

    // Insert at position example
    L = insertPos(L, 4, 2);
    printf("\nAfter insertPos(L, 4, 2):\n");
    display(L);

    // Delete at position example
    L = deletePos(L, 1);
    printf("\nAfter deletePos(L, 1):\n");
    display(L);

    // Locate example
    int pos = locate(L, 5);
    printf("\nLocate 5: position = %d\n", pos);

    // Insert sorted example
    List S;
    S = initialize(S);
    S = insertSorted(S, 1);
    S = insertSorted(S, 3);
    S = insertSorted(S, 5);
    S = insertSorted(S, 10);
	
    printf("\nSorted List before insert:\n");
    display(S);
    printf("\n");

    S = insertSorted(S, 8);
    printf("After insertSorted(S, 8):\n");
    display(S);

    return 0;
}
