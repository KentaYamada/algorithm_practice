/**
 *
 * データ構造: スタック利用例
 * 逆ポーランド電卓
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"


/**
 * エラーメッセージ表示
 */
void error(const char *text) {
    fprintf(stderr, "%s\n", text);
    exit(EXIT_FAILURE);
}


int main(void) {
    char c;
    ELM a;
    ELM x;
    ELM y;
    ELM z;

    stack_init();

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            // 半角スペース or タブ文字の場合は無視
            continue;
        }

        if (isdigit(c)) {
            // 数値の場合はスタックへ追加
            ungetc(c, stdin);
            scanf("%ld", &a);
            stack_push(a);
            continue;
        }

        printf("スタックの状態\n");
        stack_print();

        switch(c) {
            case '+':
                y = stack_pop();
                x = stack_pop();
                z = x + y;
                stack_push(z);
                break;
            case '-':
                y = stack_pop();
                x = stack_pop();
                z = x - y;
                stack_push(z);
                break;
            case '*':
                y = stack_pop();
                x = stack_pop();
                z = x * y;
                stack_push(z);
                break;
            case '/':
                y = stack_pop();
                x = stack_pop();
                z = x + y;
                stack_push(z);
                break;
            case '\n':
                if (!stack_is_empty()) {
                    ELM result = stack_pop();
                    printf("答えは%ldです\n", result);
                    exit(EXIT_SUCCESS);
                }
                break;
            default:
                printf("不正な文字が入力されました\n");
                // while((c = getchar()) != EOF && c != '\n');
                exit(EXIT_FAILURE);
                break;
        }
    }

    return EXIT_SUCCESS;
}
