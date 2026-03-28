#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if(front == NULL) {
        printf("Queue Empty\n");
        return;
    }
    struct node* temp = front;
    printf("Printed: %d\n", temp->data);
    front = front->next;
    free(temp);
}

void display() {
    struct node* temp = front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);

    display();
    dequeue();
    display();
}
