/**
 * singly_linked_list.c
 * Singly linked list data structure implementations
 */
#include "singly_linked_list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

SinglyLinkedList *singly_linked_list_create_cell() {
  SinglyLinkedList *cell =
      (SinglyLinkedList *)malloc(sizeof(struct singly_linked_list_t));
  cell->next = NULL;
  cell->value = 0;

  return cell;
}

void singly_linked_list_insert_cell(SinglyLinkedList *header,
                                    SinglyLinkedList *cell, const int index) {
  if (index == 0) {
    // 先頭への挿入は処理が異なるのでここではしない
    return;
  }

  int currentIndex = 0;
  SinglyLinkedList *current = NULL;

  for (current = header; current != NULL; current = current->next) {
    if (index == currentIndex) {
      cell->next = current->next;
      current->next = cell;
      break;
    }

    currentIndex++;
  }
}

void singly_linked_list_append(SinglyLinkedList *header, const int value) {
  SinglyLinkedList *current = NULL;

  for (current = header; current != NULL; current = current->next) {
    if (current->next == NULL) {
      SinglyLinkedList *newCell = singly_linked_list_create_cell();
      newCell->value = value;
      current->next = newCell;
      break;
    }
  }
}

void singly_linked_list_remove_cell(SinglyLinkedList *header, const int index) {
  if (index == 0) {
    return;
  }

  SinglyLinkedList *current = NULL;
  SinglyLinkedList *prev = NULL;
  int currentIndex = 0;

  for (current = header; current != NULL; current = current->next) {
    if (index == currentIndex) {
      prev->next = current->next;
      free(current);
      break;
    }

    prev = current;
    currentIndex++;
  }
}

bool singly_linked_list_is_empty(const SinglyLinkedList *list) {
  return list->next == NULL;
}
