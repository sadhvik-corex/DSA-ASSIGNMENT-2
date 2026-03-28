#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node* next;
};

struct node* top = NULL;

void push(char x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

char pop() {
    struct node* temp = top;
    char x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main() {
    char str[100];
    int i = 0;

    printf("Enter string: ");
    scanf("%s", str);

    while(str[i] != '\0') {
        push(str[i]);
        i++;
    }

    i = 0;
    while(str[i] != '\0') {
        str[i] = pop();
        i++;
    }

    printf("Reversed: %s", str);
}
