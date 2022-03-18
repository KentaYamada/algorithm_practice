/**
 * singly_linked_list_main.h
 * 単方向連結リスト I/F
 */
#ifndef __SINGLY_LINKED_LIST_H_
#define __SINGLY_LINKED_LIST_H_

#include <stdbool.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int value;
} node_t;


typedef enum {
    SINGLY_LIST_OK,
    SINGLY_LIST_UNDERFLOW,
    SINGLY_LIST_OVERFLOW,
    SINGLY_LIST_NODE_ALLOCATE_FAILURE
} SINGLY_LIST_STATUS;

/**
 * リストが空かどうか
 *
 * @return bool
 */
bool empty();

/**
 * リストのサイズ
 *
 * @return int
 */
int size();

/**
 * リストの初期化
 *
 * @return void
 */
void initialize_list();

/**
 * 指定した要素へ差し込む
 *
 * @param [in] int ノードにセットする値
 * @param [in] int 差し込み位置
 * @return void
 */
void insert_node(int value, const int element);

/**
 * リストの末尾へ追加する
 *
 * @param [in] int 差し込みたいノード
 * @return void
 */
void push_node(const int value);


/**
 * リストの末尾のデータを取り出す
 *
 * @return node_t*
 */
node_t* pop_node();

/**
 * 指定した要素のnodeを削除
 *
 * @param [in] int element 要素
 */
void remove_node(const int element);

#endif /* __SINGLY_LINKED_LIST_H_ */

