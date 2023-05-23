#include "ropes.h"


int main() {
    Node *node1, *node2;

    // createNode(&node1, "Hello, ", 7);
    // createNode(&node2, "Hello, ", 7);
    // Node* node3 ;
    // concatR(&node3, node1, node2);
    // for (int i = 0; i < 7; i++)
    // {
    //     printf("%c", indexs(node3, i));
    // }

    char s1[7] = "Sarvesh";
    node1 = (Node *)malloc(sizeof(Node));
    node1->data = s1;
    node1->weight = 7;
    node1->left = NULL;
    node1->right = NULL;

    displaySplit(*(node1));
    printf("\n------------\n");


    char s2[4]="xyz";

    insert(node1, s2, 4);
    return 0;
}