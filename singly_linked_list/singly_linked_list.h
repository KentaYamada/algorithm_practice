/**
 * singly_linked_list.h
 * Singly linked list data structure interfaces
 */
#ifndef __SINGLY_LINKED_LIST_
#define __SINGLY_LINKED_LIST_
#include <stdbool.h>

/**
 * 単方向リストの実態
 */
typedef struct singly_linked_list_t {
  struct singly_linked_list_t *next; // 次の要素へのポインタ
  int value;                         // 要素の値
} SinglyLinkedList;

/**
 * 単方向リスト初期化
 */
void init_singly_linked_list(SinglyLinkedList *header);

/**
 * 要素作成
 */
SinglyLinkedList *singly_linked_list_create_cell();

/**
 * 末尾に要素追加
 */
void singly_linked_list_append(SinglyLinkedList *header, const int value);

/**
 * 指定した要素に挿入
 */
void singly_linked_list_insert_cell(SinglyLinkedList *header,
                                    SinglyLinkedList *elm, const int index);

/**
 * 指定した要素を削除
 */
void singly_linked_list_remove_cell(SinglyLinkedList *header, const int index);

/**
 * リストが空かどうか
 */
bool singly_linked_list_is_empty(const SinglyLinkedList *list);

#endif /* __SINGLY_LINKED_LIST_ */
