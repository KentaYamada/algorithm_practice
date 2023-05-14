#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>

static void test_bubble_sort_asc(void) {
  puts("昇順の並べ替えテスト");

  int items[10] = {20, 6, 55, 74, 3, 45, 13, 87, 46, 30};

  // 整列前
  print_array(items, 10);

  // 昇順で整列
  sort(items, 10, SORT_ASC);
}
static void test_bubble_sort_desc(void) {
  puts("降順の並べ替えテスト");

  int items[10] = {20, 6, 55, 74, 3, 45, 13, 87, 46, 30};

  // 整列前
  print_array(items, 10);

  // 昇順で整列
  sort(items, 10, SORT_DESC);
}

int main(void) {
  test_bubble_sort_asc();
  test_bubble_sort_desc();

  return EXIT_SUCCESS;
}
