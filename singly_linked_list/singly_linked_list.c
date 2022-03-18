#include <stdbool.h>
#include <stdlib.h>
#include "singly_linked_list.h"

static struct _node = { NULL, 0 };
static int _size = 0;

bool empty() {
    return _node.next == NULL;
}

int size() {
    return _size;
}

void initialize_list() {
}
