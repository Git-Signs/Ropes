#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* data;
    int weight;
    struct node* left;
    struct node* right;
} Node;

typedef Node* Rope;

void createNode(Rope *r, char *data, int weight);

void concatR(Rope *r, Rope left, Rope right);

char indexs(Node* node, int i);
