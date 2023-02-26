/**
 * Doubly linked list data structure inmplementations
 */
#include "doubly_linked_list.h"
#include <stddef.h>
#include <stdlib.h>

DoublyLinkedList *doubly_linked_list_create_cell(const int value) {
  DoublyLinkedList *cell =
      (DoublyLinkedList *)malloc(sizeof(struct doubly_linked_list_t));
  cell->next = NULL;
  cell->prev = NULL;
  cell->value = value;

  return cell;
}

void doubly_linked_list_append(DoublyLinkedList *header, const int value) {
  DoublyLinkedList *p = NULL;

  for (p = header; p != NULL; p = p->next) {
    if (p->next == NULL) {
      DoublyLinkedList *cell = doubly_linked_list_create_cell(value);
      cell->prev = p;
      p->next = cell;
      break;
    }
  }
}

void doubly_linked_list_insert(DoublyLinkedList *header, const int index,
                               const int value) {
  int currentIndex = 0;
  DoublyLinkedList *p = NULL;

  if (index == 0) {
    DoublyLinkedList *cell = doubly_linked_list_create_cell(value);
    cell->prev = NULL;
    cell->next = header;
    cell->value = value;
    header->prev = cell;
    header = cell;
    return;
  }

  for (p = header; p != NULL; p = p->next) {
    if (currentIndex == index) {
      DoublyLinkedList *cell = doubly_linked_list_create_cell(value);
      cell->next = p->next;
      cell->prev = p;
      cell->value = value;
      p->next = cell;
    }

    currentIndex++;
  }
}

void doubly_linked_list_remove(DoublyLinkedList *header, const int index) {
  int currentIndex = 0;
  DoublyLinkedList *p = NULL;

  for (p = header; p != NULL; p = p->next) {
    if (currentIndex == index) {
      p->prev->next = p->next;
      p->next->prev = p->prev;
      free(p);
      break;
    }

    currentIndex++;
  }
}

bool doubly_linked_list_is_empty(const DoublyLinkedList *header) {
  return header->next == NULL;
}

unsigned int doubly_linked_list_length(DoublyLinkedList *header) {
  DoublyLinkedList *p = NULL;
  unsigned int length = 0;

  for (p = header; p != NULL; p = p->next) {
    length++;
  }

  return length;
}
