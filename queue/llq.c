#include <stdio.h>
#include <stdlib.h>

// This is a linked list implementation of a queue

typedef struct treeNode {
    unsigned int id;
    struct treeNode *next;
    struct treeNode *prev;
} treeNode;

typedef struct queue {
    struct treeNode *head;
    struct treeNode *tail;
} queue;

queue *createQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

treeNode *createNode (unsigned int id) {
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    newNode->id = id;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void enqueue(queue *q, unsigned int id) {
    treeNode *newNode = createNode(id);
    if (q->head == NULL) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode; // Add the new node to the end of the queue
        newNode->prev = q->tail; // Set the previous node of the new node to the old tail
        q->tail = newNode;
    }
    printf("Enqueued! item id: %d\n", id);
}

void dequeue(queue *q) {
    if (q->head == NULL) {
        printf("Queue is empty! \n");
    } else {
        treeNode *temp = q->head;
        printf("Dequeued! item id: %d\n", temp->id);
        q->head = q->head->next;
        free(temp);
    }
}

void printQueue(queue *q) {
    treeNode *temp = q->head;
    if (temp == NULL) {
        printf("Queue is empty! \n");
    } else {
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->id);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(char **argv, int argc) {
    queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);
    dequeue(q);
    enqueue(q, 4);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    return 0;
}