#include "queue.h"

#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *back;
} Queue;

bool isEmpty(Queue *queue) {
    if (queue->front == NULL) {
        return false;
    }
    return true;
}
