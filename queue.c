#include "queue.h"

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *front;
	Node *back;
} Queue;


bool queueCreate(Queue **queue) {
    *queue = calloc(2, sizeof(Queue) * 2);
    if (*queue == NULL) {
      return false;
    }
    return true;
}

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
