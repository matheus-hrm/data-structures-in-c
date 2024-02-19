#include <stdio.h>
#include <stdlib.h>

int Queue[100], front = -1, rear = -1;

void enqueue(int id) {
    if (rear == 99) {
        printf("Queue is full\n");
    } else if (front == -1) {
        front = 0;
        rear = 0;
        Queue[rear] = id;
    } else {
        rear++;
        Queue[rear] = id;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Dequeued: %d\n", Queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued: %d\n", Queue[front]);
        front++;
    }
}

void printQueue() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printQueue();
    dequeue();
    enqueue(40);
    printQueue();
    dequeue();
    return 0;
}
