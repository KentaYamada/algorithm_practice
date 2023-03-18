#include "binary_tree.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void test_binary_tree_create_node(void) {
  puts("Start test_binary_tree_create_node");
  Node *node = binary_tree_create_node(10);
  assert(node != NULL);
  free(node);
  node = NULL;
  puts("Completed");
}

static void test_binary_tree_get_value(void) {
  puts("Start test_binary_tree_get_value");
  int expected = 10;
  Node *node = binary_tree_create_node(expected);
  int result = binary_tree_get_value(node);
  assert(expected == result);
  free(node);
  node = NULL;
  puts("Completed");
}

/**
 * 行きがけ順のテスト
 * データ構造
 *  0
 *  |-- 1
 *  |   |-- 2
 *  |   |-- 3
 *  |       |-- 4
 *  |       |   |-- 6
 *  |       |-- 5
 *  |-- 7
 *
 *  左ノード優先で探索していく
 *  上のデータ構造を例にすると
 *  0 -> 1 -> 2 -> 3 -> 4 -> 6 -> 5 -> 7
 *  の順番で辿れていればOK
 */
static void test_binary_tree_preorder(void) {
  puts("Start test_binary_tree_preorder");

  Node *root = binary_tree_create_node(0);
  Node *node1 = binary_tree_create_node(1);
  Node *node2 = binary_tree_create_node(2);
  Node *node3 = binary_tree_create_node(3);
  Node *node4 = binary_tree_create_node(4);
  Node *node5 = binary_tree_create_node(5);
  Node *node6 = binary_tree_create_node(6);
  Node *node7 = binary_tree_create_node(7);
  binary_tree_set_left_node(root, node1);
  binary_tree_set_right_node(root, node7);
  binary_tree_set_left_node(node1, node2);
  binary_tree_set_right_node(node1, node3);
  binary_tree_set_left_node(node3, node4);
  binary_tree_set_right_node(node3, node5);
  binary_tree_set_left_node(node4, node6);

  binary_tree_preorder(root);

  Node *nodes[8] = {root, node1, node2, node3, node4, node5, node6, node7};
  for (int i = 0; i < 8; i++) {
    binary_tree_dispose_node(nodes[i]);
    nodes[i] = NULL;
  }

  puts("Completed");
}

/**
 * 帰りがけ順のテスト
 * データ構造
 *  0
 *  |-- 1
 *  |   |-- 2
 *  |   |-- 3
 *  |       |-- 4
 *  |       |   |-- 6
 *  |       |-- 5
 *  |-- 7
 *
 *  左ノード優先で探索していく
 *  上のデータ構造を例にすると
 *  2 -> 6 -> 4 -> 5 -> 3 -> 1 -> 7 -> 0
 *  の順番で辿れていればOK
 */
static void test_binary_tree_postorder(void) {
  puts("Start test_binary_tree_postorder");

  Node *root = binary_tree_create_node(0);
  Node *node1 = binary_tree_create_node(1);
  Node *node2 = binary_tree_create_node(2);
  Node *node3 = binary_tree_create_node(3);
  Node *node4 = binary_tree_create_node(4);
  Node *node5 = binary_tree_create_node(5);
  Node *node6 = binary_tree_create_node(6);
  Node *node7 = binary_tree_create_node(7);
  binary_tree_set_left_node(root, node1);
  binary_tree_set_right_node(root, node7);
  binary_tree_set_left_node(node1, node2);
  binary_tree_set_right_node(node1, node3);
  binary_tree_set_left_node(node3, node4);
  binary_tree_set_right_node(node3, node5);
  binary_tree_set_left_node(node4, node6);

  binary_tree_postorder(root);

  Node *nodes[8] = {root, node1, node2, node3, node4, node5, node6, node7};
  for (int i = 0; i < 8; i++) {
    binary_tree_dispose_node(nodes[i]);
    nodes[i] = NULL;
  }

  puts("Completed");
}

/**
 * 帰りがけ順のテスト
 * データ構造
 *  0
 *  |-- 1
 *  |   |-- 2
 *  |   |-- 3
 *  |       |-- 4
 *  |       |   |-- 6
 *  |       |-- 5
 *  |-- 7
 *
 *  左ノード優先で探索していく
 *  上のデータ構造を例にすると
 *  2 -> 6 -> 4 -> 5 -> 3 -> 1 -> 7 -> 0
 *  の順番で辿れていればOK
 */
static void test_binary_tree_inorder(void) {
  puts("Start test_binary_tree_inorder");

  Node *root = binary_tree_create_node(0);
  Node *node1 = binary_tree_create_node(1);
  Node *node2 = binary_tree_create_node(2);
  Node *node3 = binary_tree_create_node(3);
  Node *node4 = binary_tree_create_node(4);
  Node *node5 = binary_tree_create_node(5);
  Node *node6 = binary_tree_create_node(6);
  Node *node7 = binary_tree_create_node(7);
  binary_tree_set_left_node(root, node1);
  binary_tree_set_right_node(root, node7);
  binary_tree_set_left_node(node1, node2);
  binary_tree_set_right_node(node1, node3);
  binary_tree_set_left_node(node3, node4);
  binary_tree_set_right_node(node3, node5);
  binary_tree_set_left_node(node4, node6);

  binary_tree_inorder(root);

  Node *nodes[8] = {root, node1, node2, node3, node4, node5, node6, node7};
  for (int i = 0; i < 8; i++) {
    binary_tree_dispose_node(nodes[i]);
    nodes[i] = NULL;
  }

  puts("Completed");
}

int main(void) {
  test_binary_tree_create_node();
  test_binary_tree_get_value();
  test_binary_tree_preorder();
  test_binary_tree_postorder();
  test_binary_tree_inorder();
  return EXIT_SUCCESS;
}
