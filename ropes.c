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

void insert(Node *n, char *data, int index){
    // printf("\nHell=%s", data);
    // printf("\nIndex=%d", index);

    Node *root1=(Node *)malloc(sizeof(Node));
    root1=split(n, index);
    displaySplit(*(root1));

    // printf("\nHell=%s", data);

    printf("\n------------\n");

    Node *root2=(Node *)malloc(sizeof(Node));
    root2=appendAtStart(root1->right, data, strlen(data));

    root1->right=root2;

    displaySplit(*(root1));
    displaySplit(*(root2));

}

Node* split(Node *n, int index){
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = NULL;

    Node *left = (Node *)malloc(sizeof(Node));
    char *leftData = (char *)malloc(sizeof(char) * index);

    Node *right = (Node *)malloc(sizeof(Node));
    char *rightData = (char *)malloc(sizeof(char) * (n->weight - index));

    for (int i = 0; i < index; i++)
    {
        leftData[i] = n->data[i];
    }
    left->data = leftData;
    left->weight = index;

    for (int i = index; i < n->weight; i++)
    {
        rightData[i - index] = n->data[i];
    }
    right->data = rightData;
    right->weight = n->weight - index;

    root->weight = left->weight;
    root->left = left;
    root->right = right;

    // displaySplit(root);
    
    return root;
}

Node *appendAtStart(Node *n, char *data, int index){
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = NULL;
    root->right = n;

    Node *left = (Node *)malloc(sizeof(Node));
    char *leftData = (char *)malloc(sizeof(char) * index);

    for (int i = 0; i < index; i++)
    {
        leftData[i] = data[i];
    }
    left->data = leftData;
    left->weight = index;

    root->weight = left->weight;
    root->left = left;

    // displaySplit(root);

    return root;
}

void displaySplit(Node root){
    Node *l=root.left;
    Node *r=root.right;

    printf("\nRoot: ");
    if(root.data){
        printf("%s", root.data);
        printf("\t%d", root.weight);
    }

    printf("\nLeft: ");
    if(l){
        printf("%s", l->data);
        printf("\t%d", l->weight);
    }
    printf("\nRight: ");
    if(r){
        printf("%s", r->data);
        printf("\t%d", r->weight);
    }

}