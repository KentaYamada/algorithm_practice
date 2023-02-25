#include "singly_linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

static void succeded_singly_linked_list_create_cell() {
    puts("Run succeded_singly_linked_list_create_cell");

    SinglyLinkedList *list = singly_linked_list_create_cell();
    assert(list->next == NULL);
    assert(list->value == 0);
    free(list);

    puts("succeded_singly_linked_list_create_cell succeeded");
}

static void succeeded_singly_linked_list_insert_cell() {
    puts("Run succeeded_singly_linked_list_insert_cell");

    SinglyLinkedList *cell2 = singly_linked_list_create_cell();
    cell2->value = 3;

    SinglyLinkedList *cell1 = singly_linked_list_create_cell();
    cell1->next = cell2;
    cell1->value = 2;

    SinglyLinkedList *header = singly_linked_list_create_cell();
    header->next = cell1;
    header->value = 1;

    puts("=== データ挿入前 ===");
    SinglyLinkedList* p = header;

    for (p = header; p != NULL; p = p->next) {
        printf("value is %d\n", p->value);
    }

    SinglyLinkedList *newCell = singly_linked_list_create_cell();
    newCell->value = 4;

    singly_linked_list_insert_cell(header, newCell, 1);

    puts("=== データ挿入後 ===");
    int expected[4] = {1, 2, 4, 3};
    int index = 0;

    for (p = header; p != NULL; p = p->next) {
        printf("value is %d\n", p->value);
        assert (expected[index] == p->value);
        index++;
    }

    free(cell2);
    free(newCell);
    free(cell1);
    free(header);

    puts("succeeded_singly_linked_list_insert_cell end");
}

static void succeeded_singly_linked_list_remove_cell() {
    puts("Run succeeded_singly_linked_list_remove_cell");
    SinglyLinkedList *cell3 = singly_linked_list_create_cell();
    cell3->value = 3;

    SinglyLinkedList *cell2 = singly_linked_list_create_cell();
    cell2->next = cell3;
    cell2->value = 4;

    SinglyLinkedList *cell1 = singly_linked_list_create_cell();
    cell1->next = cell2;
    cell1->value = 2;

    SinglyLinkedList *header = singly_linked_list_create_cell();
    header->next = cell1;
    header->value = 1;

    puts("=== データ削除前 ===");
    SinglyLinkedList* p = header;

    for (p = header; p != NULL; p = p->next) {
        printf("value is %d\n", p->value);
    }

    singly_linked_list_remove_cell(header, 2);

    puts("=== データ削除後 ===");
    for (p = header; p != NULL; p = p->next) {
        printf("value is %d\n", p->value);
    }

    puts("succeeded_singly_linked_list_remove_cell end");
}

static void succeeded_list_is_empty() {
    puts("Run succeeded_list_is_empty");

    SinglyLinkedList *list = singly_linked_list_create_cell();
    assert(singly_linked_list_is_empty(list));
    free(list);

    puts("succeeded_list_is_empty succeeded");
}

int main() {
    // 単方向リストの要素作成チェック
    succeded_singly_linked_list_create_cell();

    // 単方向リストの挿入処理チェック
    succeeded_singly_linked_list_insert_cell();

    // 単方向リストの削除処理チェック
    succeeded_singly_linked_list_remove_cell();

    // 単方向リストの空白チェック
    succeeded_list_is_empty();

    return EXIT_SUCCESS;
}
