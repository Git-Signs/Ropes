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


    Node *root = (Node *)malloc(sizeof(Node));
    root->data = NULL;
    root->weight = 0;
    root->left = NULL;
    root->right = NULL;

    // char s1[7] = "Sarvesh";
    // node1 = (Node *)malloc(sizeof(Node));
    // node1->data = s1;
    // node1->weight = 7;
    // node1->left = NULL;
    // node1->right = NULL;

    // displaySplit(*(node1));
    printf("\n------------\n");
    char s1[8] = "Sarvesh";
    insert(&root, s1, 0);
    displaySplit(*(root));

    printf("\n------------\n");
    char s2[3] = "am";
    insert(&root, s2, 0);
    printf("\n\nInsert at Start: \n");
    displaySplit(*(root));
    // printf("%s",root->right->data);

    printf("\n------------\n");
    char s3[2] = "i";
    insert(&root, s3, 6);
    printf("\n\nInsert in Between: \n");
    displaySplit(*(root));

    printf("\n------Child------\n");
    displaySplit(*(root->right));

    printf("\n------Last------\n");
    displaySplit(*root);


    // char s2[4]="xyz";

    // insert(root, s2, 4);
    return 0;
}