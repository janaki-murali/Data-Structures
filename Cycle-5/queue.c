/*To implement QUEUE using linked list*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; 
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* myQueue = createQueue();

    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);

    printf("Queue after enqueue operations:\n");
    display(myQueue); 

    int dequeuedItem = dequeue(myQueue);
    if (dequeuedItem != -1) {
        printf("Dequeued item: %d\n", dequeuedItem);
    }

    printf("Queue after dequeue operation:\n");
    display(myQueue); 

    return 0;
}
