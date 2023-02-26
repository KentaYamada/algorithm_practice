/**
 * Doubly linked list data structure interfaces
 */
#ifndef __DOUBLY_LINKED_LIST_H_
#define __DOUBLY_LINKED_LIST_H_

#include <stdbool.h>

typedef struct doubly_linked_list_t {
  struct doubly_linked_list_t *prev;
  struct doubly_linked_list_t *next;
  int value;
} DoublyLinkedList;

/**
 * 双方向連結リストの新しい要素を作成
 */
DoublyLinkedList *doubly_linked_list_create_cell(const int value);

/**
 * 末尾に要素を追加
 */
void doubly_linked_list_append(DoublyLinkedList *header, const int value);

/**
 * 指定した位置に要素を追加する
 */
void doubly_linked_list_insert(DoublyLinkedList *header, const int index,
                               const int value);

/**
 * 指定した位置に要素を削除する
 */
void doubly_linked_list_remove(DoublyLinkedList *header, const int index);

/**
 * 双方向連結リストが空かどうか
 */
bool doubly_linked_list_is_empty(const DoublyLinkedList *header);

/**
 * 双方向連結リストの要素数を取得
 */
unsigned int doubly_linked_list_length(DoublyLinkedList *header);

#endif /* __DOUBLY_LINKED_LIST_H_ */
