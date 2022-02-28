/**
 * queue.h
 * 配列を使った待ち行列 I/F
 */
#ifndef __QUEUE_H_
#define __QUEUE_H_
#include <stdbool.h>

/** キューサイズ */
#define QUEUE_SIZE 100

/** キューのデータ型 */
typedef long ELM;

/** キューのエラーコード */
typedef enum {
    QUEUE_OK,
    QUEUE_ERROR_IS_EMPTY,
    QUEUE_ERROR_IS_FULL
} QUEUE_STATUS;

/**
 * キュー初期化
 */
void init();

/**
 * キューが空かどうか
 */
bool empty();

int next(const int value);

/**
 * キューへ追加
 */
QUEUE_STATUS enqueue(const ELM elm);

/**
 * キューから取り出し
 */
QUEUE_STATUS dequeue(ELM *elm);

/**
 * キューの状態を表示
 */
void print_queue();

#endif /* __QUEUE_H_ */
