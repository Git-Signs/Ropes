#include "ropes.h"

void createNode(Rope *r, char *data, int weight)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
    *r = node;
}

void concatR(Rope *r, Rope left, Rope right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = NULL;
    node->weight = left->weight + right->weight;
    node->left = left;
    node->right = right;
    *r = node;
}

char indexs(Node* node, int i) {
    if (node->left == NULL) {
        return node->data[i];
    } else if (i < node->left->weight) {
        return indexs(node->left, i);
    } else {
        return indexs(node->right, i - node->left->weight);
    }
}