#include "doubly_linked_list.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void test_doubly_linked_list_create_cell() {
  puts("Start test_doubly_linked_list_create_cell");

  const int expected = 10;
  DoublyLinkedList *cell = doubly_linked_list_create_cell(expected);
  assert(cell->value == expected);

  free(cell);
  cell = NULL;

  puts("End test_doubly_linked_list_create_cell");
}

static void test_doubly_linked_list_append() {
  puts("Start test_doubly_linked_list_append");

  DoublyLinkedList *header = doubly_linked_list_create_cell(10);
  doubly_linked_list_append(header, 20);

  int i = 1;
  DoublyLinkedList *p = NULL;

  for (p = header; p != NULL; p = p->next) {
    assert(p->value == (i * 10));
    i++;
  }

  puts("End test_doubly_linked_list_append");
}

static void test_doubly_linked_list_insert() {
  puts("Start test_doubly_linked_list_insert");

  DoublyLinkedList *header = doubly_linked_list_create_cell(10);
  doubly_linked_list_insert(header, 1, 20);

  int i = 1;
  DoublyLinkedList *p = NULL;

  for (p = header; p != NULL; p = p->next) {
    assert(p->value == (i * 10));
    i++;
  }

  // 10と20の間に30差し込み
  doubly_linked_list_insert(header, 1, 30);
  p = NULL;
  int expected[3] = {10, 30, 20};
  i = 0;

  for (p = header; p != NULL; p = p->next) {
    assert(p->value == expected[i]);
    i++;
  }

  free(header);
  header = NULL;
  puts("End test_doubly_linked_list_insert");
}

static void test_doubly_linked_list_insert_when_insert_front() {
  puts("Start test_doubly_linked_list_insert_when_insert_front");

  DoublyLinkedList *header = doubly_linked_list_create_cell(10);
  doubly_linked_list_insert(header, 0, 20);

  DoublyLinkedList *p = NULL;
  int expected[2] = {20, 10};
  int i = 0;
  for (p = header; p != NULL; p = p->next) {
    printf("value is %d\n", p->value);
    assert(p->value == expected[i]);
    i++;
  }

  puts("End test_doubly_linked_list_insert_when_insert_front");
}

static void test_doubly_linked_list_remove() {
  puts("Start test_doubly_linked_list_remove");

  DoublyLinkedList *header = doubly_linked_list_create_cell(10);
  doubly_linked_list_append(header, 20);
  doubly_linked_list_append(header, 30);

  DoublyLinkedList *p = NULL;
  int i = 1;
  for (p = header; p != NULL; p = p->next) {
    assert(p->value == (i * 10));
    i++;
  }

  // 1番目の要素の20を削除
  doubly_linked_list_remove(header, 1);

  int length = doubly_linked_list_length(header);
  assert(length == 2);

  int expected[2] = {10, 30};
  i = 0;
  p = NULL;
  for (p = header; p != NULL; p = p->next) {
    assert(p->value == expected[i]);
    i++;
  }

  puts("End test_doubly_linked_list_remove");
}

static void test_doubly_linked_list_length() {
  puts("Start test_doubly_linked_list_length");

  DoublyLinkedList *header = doubly_linked_list_create_cell(10);
  unsigned int length = doubly_linked_list_length(header);
  assert(length == 1);

  DoublyLinkedList *cell = doubly_linked_list_create_cell(20);
  header->next = cell;
  length = doubly_linked_list_length(header);
  assert(length == 2);

  free(cell);
  free(header);
  cell = NULL;
  header = NULL;

  puts("End test_doubly_linked_list_length");
}

int main() {
  test_doubly_linked_list_create_cell();
  test_doubly_linked_list_append();
  test_doubly_linked_list_length();
  test_doubly_linked_list_insert();
  test_doubly_linked_list_insert_when_insert_front();
  test_doubly_linked_list_remove();
  test_doubly_linked_list_insert_when_insert_front();
  return EXIT_SUCCESS;
}
