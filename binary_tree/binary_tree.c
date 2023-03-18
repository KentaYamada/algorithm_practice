#include "binary_tree.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * nodeの実態
 */
struct node_t {
  struct node_t *left;
  struct node_t *right;
  int value;
};

Node *binary_tree_create_node(int value) {
  Node *node = (Node *)malloc(sizeof(struct node_t));
  node->left = NULL;
  node->right = NULL;
  node->value = value;
  return node;
}

void binary_tree_dispose_node(Node *node) {
  if (node != NULL) {
    free(node);
  }
}

void binary_tree_set_left_node(Node *parent, Node *node) {
  if (parent != NULL && node != NULL) {
    parent->left = node;
  }
}

void binary_tree_set_right_node(Node *parent, Node *node) {
  if (parent != NULL && node != NULL) {
    parent->right = node;
  }
}

void binary_tree_preorder(const Node *node) {
  if (node != NULL) {
    printf("%dに立ち寄りました\n", node->value);
    binary_tree_preorder(node->left);
    binary_tree_preorder(node->right);
  }
}

void binary_tree_postorder(const Node *node) {
  if (node != NULL) {
    binary_tree_postorder(node->left);
    binary_tree_postorder(node->right);
    printf("%dに立ち寄りました\n", node->value);
  }
}

void binary_tree_inorder(const Node *node) {
  if (node != NULL) {
    binary_tree_inorder(node->left);
    printf("%dに立ち寄りました\n", node->value);
    binary_tree_inorder(node->right);
  }
}

int binary_tree_get_value(const Node *node) { return node->value; }
