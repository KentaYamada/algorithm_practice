#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_

typedef struct node_t Node;

/**
 * ノード作成
 */
Node *binary_tree_create_node(int value);

/**
 * ノードに割り当てられた領域を解放
 */
void binary_tree_dispose_node(Node *node);

/**
 * 対象ノードの左側にノードをセット
 */
void binary_tree_set_left_node(Node *parent, Node *node);

/**
 * 対象ノードの右側にノードをセット
 */
void binary_tree_set_right_node(Node *parent, Node *node);

/**
 * 行きがけ順でなぞる
 */
void binary_tree_preorder(const Node *node);

/**
 * 帰りがけ順でなぞる
 */
void binary_tree_postorder(const Node *node);

/**
 * 通りがけ順でなぞる
 */
void binary_tree_inorder(const Node *node);

/**
 * ノードの値取得
 */
int binary_tree_get_value(const Node *node);

#endif /** __BINARY_TREE_H_ */
