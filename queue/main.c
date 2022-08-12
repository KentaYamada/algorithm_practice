#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void test_queue_init() {
    puts("Run test_queue_init");

    Queue* queue = queue_init();
    assert(queue != NULL);
    assert(queue_is_empty(queue));
    assert(!queue_is_full(queue));
    assert(queue_get_item_count(queue) == 0);

    queue_destroy(queue);

    puts("test_queue_init succeeded");
}

static void test_queue_enqueue() {
    puts("Run test_queue_enqueue");

    Queue* queue = queue_init();
    assert(queue_is_empty(queue));

    long data = 13;
    queue_enqueue(queue, data);
    assert(!queue_is_empty(queue));
    assert(queue_get_item_count(queue) == 1);

    long peek_data;
    QUEUE_STATUS status = queue_peek(queue, &peek_data);
    assert(status == QUEUE_STATUS_OK);
    assert(peek_data == data);

    queue_destroy(queue);

    puts("test_queue_enqueue succeeded");
}

static void test_queue_dequeue() {
    puts("Run test_queue_dequeue");
    Queue* queue = queue_init();
    assert(queue_is_empty(queue));

    long data = 13;
    queue_enqueue(queue, data);
    assert(!queue_is_empty(queue));
    assert(queue_get_item_count(queue) == 1);

    long dequeue_data;
    QUEUE_STATUS status = queue_dequeue(queue, &dequeue_data);
    assert(status == QUEUE_STATUS_OK);
    assert(dequeue_data == data);
    assert(queue_get_item_count(queue) == 0);

    queue_destroy(queue);

    puts("test_queue_dequeue succeeded");
}

static void test_queue_overflow() {
    puts("Run test_queue_overflow");
    Queue* queue = queue_init();
    assert(queue_is_empty(queue));

    for (int i = 1; i <= BUF_SIZE; i++) {
        queue_enqueue(queue, i);
    }
    assert(queue_is_full(queue));

    QUEUE_STATUS status = queue_enqueue(queue, 11);
    assert(status == QUEUE_STATUS_OVER_FLOW);

    queue_destroy(queue);

    puts("test_queue_overflow succeeded");
}

static void test_queue_underflow() {
    puts("Run test_queue_underflow");

    Queue* queue = queue_init();
    assert(queue_is_empty(queue));

    long data = 15;
    queue_enqueue(queue, data);
    assert(queue_get_item_count(queue) == 1);

    long dequeue_data;
    QUEUE_STATUS status = queue_dequeue(queue, &dequeue_data);
    assert(status == QUEUE_STATUS_OK);

    long expected_underflow_data;
    QUEUE_STATUS underflow_status = queue_dequeue(queue, &expected_underflow_data);
    assert(underflow_status == QUEUE_STATUS_UNDER_FLOW);
    assert(queue_is_empty(queue));
    assert(queue_get_item_count(queue) == 0);

    queue_destroy(queue);

    puts("test_queue_underflow succeeded");
}

static void test_queue_ring_buffer() {
    puts("Run test_queue_ring_buffer");

    Queue* queue = queue_init();
    assert(queue_is_empty(queue));

    for (int i = 1; i <= BUF_SIZE; i++) {
        queue_enqueue(queue, i);
    }

    assert(queue_is_full(queue));

    long dequeue_data;
    queue_dequeue(queue, &dequeue_data);
    assert(!queue_is_full(queue));

    long data = 120;
    queue_enqueue(queue, data);
    assert(queue_is_full(queue));

    long arr[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 120 };
    for (int i = 0; i < 10; i++) {
        long value;
        queue_dequeue(queue, &value);
        assert(arr[i] == value);
    }
    assert(queue_is_empty(queue));

    queue_destroy(queue);

    puts("test_queue_ring_buffer succeeded");
}

int main(void) {
    puts("Queue tests start");

    // キューの初期化テスト
    test_queue_init();

    // キューの挿入テスト
    test_queue_enqueue();

    // キューの取り出しテスト
    test_queue_dequeue();

    // キューのオーバーフローテスト
    test_queue_overflow();

    // キューのアンダーフローテスト
    test_queue_underflow();

    // キューのリングバッファテスト
    test_queue_ring_buffer();

    puts("Queue tests completed");

    return EXIT_SUCCESS;
}
