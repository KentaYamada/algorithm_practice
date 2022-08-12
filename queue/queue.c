/**
 * @file queue.c
 * @brief キュー(待ち行列)サンプルプログラム
 * @author YamaKen
 */
#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * キューの実態
 */
struct queue_t {
    unsigned int front;      //!< キューの先頭要素
    unsigned int rear;       //!< キューの末尾要素
    unsigned int item_count; //!< キューの現在の要素数
    long data[BUF_SIZE];     //!< キューの実データ
};

/**
 * キューの先頭位置(初期値)
 */
static const unsigned int QUEUE_DEFAULT_FRONT_POSITION = 0;

/**
 * キューの末尾位置(初期値)
 */
static const unsigned int QUEUE_DEFAULT_REAR_POSITION = -1;

Queue* queue_init() {
    Queue* queue = (Queue*)malloc(sizeof(struct queue_t));
    queue->front = QUEUE_DEFAULT_FRONT_POSITION;
    queue->rear = QUEUE_DEFAULT_REAR_POSITION;
    queue->item_count = 0;

    for (int i = 0; i < BUF_SIZE; i++) {
        queue->data[i] = 0;
    }

    return queue;
}

void queue_destroy(Queue* queue) {
    free(queue);
}

bool queue_is_empty(const Queue* queue) {
    return queue->item_count == 0;
}

bool queue_is_full(const Queue *queue) {
    return queue->item_count == BUF_SIZE;
}

unsigned int queue_get_size() {
    return BUF_SIZE;
}

unsigned int queue_get_item_count(const Queue *queue) {
    return queue->item_count;
}

QUEUE_STATUS queue_peek(const Queue* queue, long *value) {
    if (queue_is_empty(queue)) {
        return QUEUE_STATUS_UNDER_FLOW;
    }

    *value = queue->data[queue->front];
    return QUEUE_STATUS_OK;
}

QUEUE_STATUS queue_enqueue(Queue* queue, const long value) {
    if (queue_is_full(queue)) {
        return QUEUE_STATUS_OVER_FLOW;
    }

    if ((queue->rear + 1) == BUF_SIZE) {
        // 末尾の位置が要素数を越えたら、最初の要素にセット (リングバッファ)
        queue->rear = QUEUE_DEFAULT_REAR_POSITION;
    }

    queue->rear++;
    queue->item_count++;
    queue->data[queue->rear] = value;

    return QUEUE_STATUS_OK;
}

QUEUE_STATUS queue_dequeue(Queue* queue, long *value) {
    if (queue_is_empty(queue)) {
        return QUEUE_STATUS_UNDER_FLOW;
    }
    if (queue->front == BUF_SIZE && queue->front > queue->rear) {
        // キューの先頭要素が末尾よりも大きい場合は巡回させる
        queue->front = QUEUE_DEFAULT_FRONT_POSITION;
    }

    *value = queue->data[queue->front];
    queue->front++;
    queue->item_count--;

    return QUEUE_STATUS_OK;
}
