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

    if(front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void dequeue() {
    if(front == NULL) {
        printf("Queue Empty\n");
        return;
    }

    struct node* temp = front;
    printf("Removed: %d\n", temp->data);

    if(front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    free(temp);
}

void display() {
    if(front == NULL) return;

    struct node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);

    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    display();
    dequeue();
    display();
}
