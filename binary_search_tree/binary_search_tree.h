#ifndef _BINARY_SEARCH_TREE_H__
#define _BINARY_SEARCH_TREE_H__

#include <stdbool.h>

typedef struct node {
  unsigned int data;
  struct node *left;
  struct node *right;
} Node;

bool key_equal(const unsigned int a, const unsigned int b);

bool key_lt(const unsigned int a, const unsigned int b);

Node *search(Node *node, const unsigned int key);

Node *insert(Node *node, const unsigned int key);

void cleanup(Node *node);

#endif /** _BINARY_SEARCH_TREE_H__ */
