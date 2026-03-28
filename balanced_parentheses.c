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

void pop() {
    if(top != NULL) {
        struct node* temp = top;
        top = top->next;
        free(temp);
    }
}

int isEmpty() {
    return top == NULL;
}

int main() {
    char exp[100];
    int i = 0, flag = 1;

    printf("Enter expression: ");
    scanf("%s", exp);

    while(exp[i] != '\0') {
        if(exp[i] == '(')
            push('(');
        else if(exp[i] == ')') {
            if(isEmpty()) {
                flag = 0;
                break;
            }
            pop();
        }
        i++;
    }

    if(!isEmpty()) flag = 0;

    if(flag)
        printf("Balanced Expression");
    else
        printf("Not Balanced");
}
