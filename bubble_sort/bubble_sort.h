#ifndef __BUBBLE_SORT_H_
#define __BUBBLE_SORT_H_

#include <stddef.h>

// ソート種別
typedef enum {
  SORT_ASC = 0, // 昇順
  SORT_DESC     // 降順
} SORT_KINDS;

/**
 * 配列の値表示
 */
void print_array(const int items[], const size_t length);

/**
 * バブルソートで並び替え
 */
void sort(int items[], const size_t length, const SORT_KINDS sortKind);

#endif /* __BUBBLE_SORT_H_ */
