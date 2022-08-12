/**
 * @file queue.h
 * @brief キュー(待ち行列)サンプルプログラム I/F
 * @author YamaKen
 */
#ifndef _QUEUE_H__
#define _QUEUE_H__
#include <stdbool.h>

/**
 * キューの要素数
 */
#define BUF_SIZE 10

/**
 * キューの操作結果
 */
typedef enum {
    QUEUE_STATUS_OK = 0,           //!< 正常終了
    QUEUE_STATUS_UNDER_FLOW = -1,  //!< アンダーフローエラー
    QUEUE_STATUS_OVER_FLOW = -2    //!< オーバーフローエラー
} QUEUE_STATUS;

typedef struct queue_t Queue;

/**
 * キュー初期化
 *
 * @return Queue* 初期化済のキュー領域
 */
extern Queue* queue_init();

/**
 * キュー破棄
 *
 * @param [in] Queue* キュー領域
 * @return void
 */
extern void queue_destroy(Queue* queue);

/**
 * キューが空かどうか
 *
 * @param [in] queue キュー領域
 * @return bool
 */
extern bool queue_is_empty(const Queue* queue);

/**
 * キューが満杯かどうか
 *
 * @param [in] queue キュー領域
 * @return bool
 */
extern bool queue_is_full(const Queue* queue);

/**
 * キューサイズ取得
 *
 * @return bool
 */
extern unsigned int queue_get_size();

/**
 * 現時点の待ち行列数取得
 *
 * @param [in] queue キュー領域
 * @return bool
 */
extern unsigned int queue_get_item_count(const Queue* queue);

/**
 * キューから先頭のデータ取り出し
 * (取得後に消さない)
 *
 * @param [out] value 取り出された値
 * @return QUEUE_STATUS
 */
extern QUEUE_STATUS queue_peek(const Queue* queue, long* value);

/**
 * キューへデータ追加
 *
 * @param [in] value 追加する値
 * @return QUEUE_STATUS
 */
extern QUEUE_STATUS queue_enqueue(Queue* queue, const long value);

/**
 * キューからデータ取り出し
 *
 * @param [out] value 取り出された値
 * @return QUEUE_STATUS
 */
extern QUEUE_STATUS queue_dequeue(Queue* queue, long* value);

#endif // _QUEUE_H__
