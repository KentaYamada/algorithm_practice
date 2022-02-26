#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

/** 現在のスタックポインタ */
static int _current;

/** スタックとして利用する配列 */
static ELM _stack[STACK_SIZE];

void stack_init() {
    _current = 0;
    for(int i = 0; i < STACK_SIZE; i++) {
        _stack[i] = 0;
    }
}

bool stack_is_empty() {
    return _current == 0;
}

void stack_push(const ELM elm) {
     if (_current < STACK_SIZE) {
        _stack[_current++] = elm;
     }
}

ELM stack_pop() {
    if (_current >= 0) {
        return _stack[--_current];
    }

    // underflow error
    return -1;
}

void stack_print() {
    if (_current <= 0) {
        return;
    }

    int index = 0;
    for(int i = _current - 1; i >= 0; i--) {
        printf("%d: %ld\n", index, _stack[i]);
        index++;
    }
}
