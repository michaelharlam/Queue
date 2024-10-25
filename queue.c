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


bool queueCreate(Queue **queue) {
    *queue = calloc(2, sizeof(Queue) * 2);
    if (*queue == NULL) {
      return false;
    }
    return true;
}
