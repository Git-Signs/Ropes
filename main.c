#include "ropes.h"


int main() {
    Node* node1 = create_node("Hello, ", 7);
    Node* node2 = create_node("world!", 6);
    Node* node3 = concat(node1, node2);
    for (int i = 0; i < 7; i++)
    {
        printf("%c", indexs(node3, i));
    }
    return 0;
}