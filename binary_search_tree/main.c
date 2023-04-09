#include "binary_search_tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void test_binary_search_tree_insert(void) {
  Node *root = malloc(sizeof(Node));
  ;
  root->data = 0;
  root->left = NULL;
  root->right = NULL;
  insert(root, 1);
  // assert(root->data == 1);
  assert(root->right->data == 1);
  cleanup(root);
}

int main(void) {
  test_binary_search_tree_insert();
  return EXIT_SUCCESS;
}
