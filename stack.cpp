#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack* s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push operation
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow. Cannot push %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
    printf("Pushed: %d\n", value);
}

// Pop operation
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow. Cannot pop.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Peek operation
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    }
    return s->items[s->top];
}

// Display stack elements
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack from top to bottom:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

// Main function to demonstrate stack operations
int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Top item is: %d\n", peek(&s));

    printf("Popped item: %d\n", pop(&s));
    display(&s);

    return 0;
}

