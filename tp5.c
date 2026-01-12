#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    struct stack *next;
    char data;
}SNode;

typedef struct qnode{
    struct qnode *next;
    char data;
}QNode;

typedef struct queue{
    QNode *front;
    QNode *rear;
}Queue;


/* ===== Stack Functions ===== */

SNode* push(SNode* top, char ch) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = ch;
    newNode->next = top;
    return newNode;   // new top
}

SNode* pop(SNode* top, char *value) {
    if (top == NULL)
        return NULL;

    SNode* temp = top;
    *value = temp->data;
    top = temp->next;
    free(temp);
    return top;   // new top
}

/* ===== Queue Functions ===== */

void enqueue(Queue *q, char ch) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = ch;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue *q, char *value) {
    if (q->front == NULL)
        return;

    QNode* temp = q->front;
    *value = temp->data;
    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}



/* ===== Main Program ===== */

int main() {
    char text[100];
    SNode* top = NULL;
    Queue q;
    q.front = q.rear = NULL;

    char sChar, qChar;
    int isPalindrome = 1;

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);

    // Fill stack and queue
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            top = push(top, ch);
            enqueue(&q, ch);
        }
    }

    // Compare stack and queue
    while (top != NULL && q.front != NULL) {
        top = pop(top, &sChar);
        dequeue(&q, &qChar);

        if (sChar != qChar) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
