#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static ELM queue[QUEUE_SIZE];

static int front;

static int rear;

void init() {
    front = 0;
    rear = 0;
    for (int i = 0; i < QUEUE_SIZE; i++) {
        queue[i] = 0;
    }
}

bool empty() {
    return front == rear;
}

int next(const int value) {
    return (value + 1) % QUEUE_SIZE;
}

QUEUE_STATUS enqueue(const ELM elm) {
    if (next(rear) == front) {
        return QUEUE_ERROR_IS_FULL;
    }

    queue[rear] = elm;
    rear = next(rear);

    return QUEUE_OK;
}

QUEUE_STATUS dequeue(ELM *elm) {
    if (front == rear) {
        return QUEUE_ERROR_IS_EMPTY;
    }

    *elm = queue[front];
    queue[front] = 0;
    front = next(front);

    return QUEUE_OK;
}

void print_queue() {
    if (empty()) {
        return;
    }

    int index = 0;
    for(int i = front; i < rear; i++) {
        printf("%d: %ld\n", index, queue[i]);
        index++;
    }
}
