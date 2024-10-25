#include "queue.h"

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *front;
	Node *back;
} Queue;
