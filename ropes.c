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

void insert(Node **n, char *data, int index){
    if (index==0){
        if(!(*n)->data){
            Node *n1 = (Node *)malloc(sizeof(Node));
            n1->data = data;
            n1->weight = strlen(data);
            n1->left = NULL;
            n1->right = NULL;
            *n = n1;
            printf("\nStart-> %s\n",(*n)->data);
            return;
        }

        Node *n1 = (Node *)malloc(sizeof(Node));
        n1->data = data;
        n1->weight = strlen(data);
        n1->left = NULL;
        n1->right = NULL;

        Node *root = (Node *)malloc(sizeof(Node));
        root->data = NULL;
        root->right = *n;
        root->left = n1;
        root->weight = n1->weight;

        printf("\nLeft-> %s\n",n1->data);

        *n = root;
    }else{
        int i=0;
        Node *temp = *n;
        while (temp->weight < index)
        {
            index = index - temp->weight;
            temp = temp->right;
            i++;
        }

        temp=split(&temp, index);
        
        printf("\n\nTemp in Insert: ");
        displaySplit(*temp);

        // (*n)->right = temp;
        

        
    }
}

Node *split(Node **n, int index){
    Node *left = (Node *)malloc(sizeof(Node));
    char *leftData = (char *)malloc(sizeof(char) * index);    
    for (int i = 0; i < index; i++)
    {
        leftData[i] = (*n)->data[i];
    }
    left->data = leftData;
    left->weight = index;


    Node *right = (Node *)malloc(sizeof(Node));
    char *rightData = (char *)malloc(sizeof(char) * ((*n)->weight - index));
    for (int i = index; i < (*n)->weight; i++)
    {
        rightData[i - index] = (*n)->data[i];
    }
    right->data = rightData;
    right->weight = (*n)->weight - index;


    Node *root = (Node *)malloc(sizeof(Node));
    root->data = NULL;
    root->weight = left->weight;
    root->left = left;
    root->right = right;

    *n=root;

    printf("\n------Split------\n");
    displaySplit(**n);

    return root;
}

void appendAtStart(Node **n, char *data, int index){
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = NULL;
    root->right = *n;

    printf("\nRight of Append-> %s\n",root->right->data);

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

    printf("\n------Append------\n");
    displaySplit(*root);

    *n=root;

    // return root;
}

void displaySplit(Node root){
    Node *l=root.left;
    Node *r=root.right;

    printf("\nRoot: ");
    if(root.data){
        printf("%s", root.data);
        printf("\t%d", root.weight);
    }else{
        printf("Weight: %d", root.weight);
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


        // Node *temp = *n;
        // Node *t = *n;
        // printf("\nTemp-> %s\n",temp->data);
        // int i=0;
        // while (temp->weight < index)
        // {
        //     index = index - temp->weight;
        //     temp = temp->right;
        //     i++;
        // }

        // printf("\nTemp-> %s\n",temp->data);

        // Node *root1=(Node *)malloc(sizeof(Node));
        // split(&temp, index);
        // root1=temp;

        // printf("\n------Split in Insert------\n");
        // displaySplit(*root1);

        // Node *root2=(Node *)malloc(sizeof(Node));
        // appendAtStart(&root1->right, data, strlen(data));
        // // root1->right=root2;

        // printf("\n------Append in Insert------\n");
        // displaySplit(*root1->right);

        // printf("\n------Insert------\n");
        // displaySplit(*(temp));
        // printf("\n------Insert End------\n");

        // *n=t;