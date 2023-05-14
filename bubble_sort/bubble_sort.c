#include "bubble_sort.h"
#include <stddef.h>
#include <stdio.h>

void print_array(const int items[], const size_t length) {
  for (int i = 0; i < length; i++) {
    if (i < length - 1) {
      printf("%d ", items[i]);
    } else {
      printf("%d\n", items[i]);
    }
  }
}

static void sort_asc(int items[], const size_t length) {
  int end = length - 1;

  for (int i = 0; i < end; i++) {
    for (int j = end; j > i; j--) {
      if (items[j - 1] > items[j]) {
        int temp = items[j];
        items[j] = items[j - 1];
        items[j - 1] = temp;
      }
    }
    print_array(items, length);
  }
}

static void sort_desc(int items[], const size_t length) {
  int end = length - 1;

  for (int i = 0; i < end; i++) {
    for (int j = end; j > i; j--) {
      if (items[j - 1] < items[j]) {
        int temp = items[j];
        items[j] = items[j - 1];
        items[j - 1] = temp;
      }
    }
    print_array(items, length);
  }
}

void sort(int items[], const size_t length, const SORT_KINDS sortKind) {
  if (sortKind == SORT_ASC) {
    sort_asc(items, length);
  } else {
    sort_desc(items, length);
  }
}
