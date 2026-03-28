#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    struct node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int isEmpty() {
    return top == NULL;
}

int main() {
    int arr[] = {4,5,2,10,8};
    int n = 5, i;

    push(arr[0]);

    for(i = 1; i < n; i++) {
        while(!isEmpty() && top->data < arr[i]) {
            printf("%d -> %d\n", pop(), arr[i]);
        }
        push(arr[i]);
    }

    while(!isEmpty()) {
        printf("%d -> -1\n", pop());
    }
}
