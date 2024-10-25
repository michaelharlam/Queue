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

bool enqueue(Queue *queue, int value) {
    Node *node = malloc(sizeof(Queue));
    if (node == NULL) {
        return false;
    }

    if (!isEmpty(queue)) {
        queue->front->next = node;
    } else {
        queue->back = node;
    }
    queue->front = node;
    return true;
}
