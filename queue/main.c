#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queue.h"

/**
 * エラーメッセージ表示
 */
void error(const char *text) {
    fprintf(stderr, "%s\n", text);
    exit(EXIT_FAILURE);
}

int main(void) {
    QUEUE_STATUS status;
    init();

    status = enqueue(10);
    if (status != QUEUE_OK) {
        error("キューの追加に失敗しました\n");
    }

    printf("キューの状態\n");
    print_queue();

    status = enqueue(20);
    if (status != QUEUE_OK) {
        error("キューの追加に失敗しました\n");
    }

    printf("キューの状態\n");
    print_queue();

    ELM elm;
    status = dequeue(&elm);
    if (status != QUEUE_OK) {
        error("キューからデータの取り出しに失敗しました\n");
    }

    printf("キューから%ldを取り出しました\n", elm);
    printf("キューの状態\n");
    print_queue();

    exit(EXIT_SUCCESS);
}
