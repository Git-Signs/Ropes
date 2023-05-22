#include "ropes.h"


int main() {
    Node *node1, *node2;

    createNode(&node1, "Hello, ", 7);
    createNode(&node2, "Hello, ", 7);
    Node* node3 ;
    concatR(&node3, node1, node2);
    for (int i = 0; i < 7; i++)
    {
        printf("%c", indexs(node3, i));
    }
    return 0;
}