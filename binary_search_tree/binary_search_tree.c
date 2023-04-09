#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

bool key_equal(const unsigned int a, const unsigned int b) { return a == b; }

bool key_lt(const unsigned int a, const unsigned int b) { return a < b; }

Node *search(Node *node, const unsigned int key) {
  Node *current = node;

  while (current != NULL) {
    if (key_equal(key, current->data)) {
      return current;
    } else if (key_lt(key, current->data)) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  // notfound
  return NULL;
}

Node *insert(Node *node, const unsigned int key) {
  Node **current = &node;

  while (*current != NULL) {
    if (key_equal(key, (*current)->data)) {
      // already exist key
      return NULL;
    } else if (key_equal(key, (*current)->data)) {
      current = &(*current)->left;
    } else {
      current = &(*current)->right;
    }
  }

  Node *newNode = malloc(sizeof(Node));

  if (newNode == NULL) {
    // failed assign node
    return NULL;
  }

  newNode->data = key;
  newNode->left = NULL;
  newNode->right = NULL;
  *current = newNode;

  return newNode;
}

void cleanup(Node *node) {
  if (node == NULL) {
    return;
  }

  cleanup(node->left);
  cleanup(node->right);
  free(node);
}
