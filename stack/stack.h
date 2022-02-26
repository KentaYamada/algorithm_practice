/**
 * stack.h
 * Stack data structure interfaces
 */
#ifndef __STACH_H_
#define __STACH_H_
#include <stdbool.h>

/** スタックの最大領域 */
#define STACK_SIZE 100

/** スタックの型 */
typedef long ELM;

/**
 * スタック初期化
 */
void stack_init();

/**
 * スタックが空かどうか
 */
bool stack_is_empty();

/**
 * データ追加
 */
void stack_push(const ELM elm);

/**
 * データ取り出し
 */
ELM stack_pop();

/**
 * スタックデータ表示
 */
void stack_print();

#endif /* __STACH_H_ */
