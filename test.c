#define CTEST_MAIN
#define CTEST_SEGFAULT
#include "ctest/ctest.h"

#include <stdio.h>

#include "queue.h"

int main(int argc, const char *argv[]) {
    return ctest_main(argc, argv);
}

Queue *createQueue(void) {
    Queue *queue;
    ASSERT_TRUE(queueCreate(&queue));
    ASSERT_NOT_NULL(queue);
    return queue;
}

void assertEnqueue(Queue *queue, int value) {
    ASSERT_TRUE(enqueue(queue, value));
}

void assertDequeue(Queue *queue, int expected) {
    int value = 0;
    ASSERT_TRUE(dequeue(queue, &value));
    ASSERT_EQUAL(value, expected);
}

CTEST(queueTests, queueCreate) {
    Queue *queue = createQueue();
    queueDispose(queue);
}

CTEST(queueTests, enqueueSingle) {
    Queue *queue = createQueue();
    
    assertEnqueue(queue, 35);
    assertDequeue(queue, 35);

    queueDispose(queue);
}

CTEST(queueTests, enqueueSomeA) {
    Queue *queue = createQueue();
    
    assertEnqueue(queue, 35);
    assertEnqueue(queue, 56);

    assertDequeue(queue, 35);
    assertDequeue(queue, 56);

    queueDispose(queue);
}

CTEST(queueTests, enqueueSomeB) {
    Queue *queue = createQueue();
    
    assertEnqueue(queue, 35);
    assertEnqueue(queue, -455);
    assertEnqueue(queue, 56);
    
    assertDequeue(queue, 35);
    assertDequeue(queue, -455);
    assertDequeue(queue, 56);

    queueDispose(queue);
}

CTEST(queueTests, emptyTest) {
    Queue *queue = createQueue();

    ASSERT_TRUE(isEmpty(queue));

    assertEnqueue(queue, 35);
    ASSERT_FALSE(isEmpty(queue));

    assertEnqueue(queue, -455);
    ASSERT_FALSE(isEmpty(queue));

    assertEnqueue(queue, 56);
    ASSERT_FALSE(isEmpty(queue));
    
    assertDequeue(queue, 35);
    ASSERT_FALSE(isEmpty(queue));

    assertDequeue(queue, -455);
    ASSERT_FALSE(isEmpty(queue));
    
    assertDequeue(queue, 56);
    
    ASSERT_TRUE(isEmpty(queue));

    queueDispose(queue);
}
