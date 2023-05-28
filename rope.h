#ifndef ROPE_H
#define ROPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct Rope
{
    struct Rope *left, *right, *parent;
    char *str;
    int l_count;
} Rope;

#define ROPE_LEN(r) ((r)->l_count)

void Rope_create(Rope **node, Rope *par, char *s, int l, int r, int leaf_len);
Rope *Rope_new(char *s, int leaf_len);
Rope *Rope_subnew(char *s, int strt, int end, int leaf_len);
void Rope_delete(Rope *root);
Rope *Rope_concat(Rope *root1, Rope *root2);
char *Rope_get_char(Rope *root, int i);
bool Rope_set_char(Rope *root, int i, char c);
char *Rope_to_str(Rope *root);
char *Rope_to_substr(Rope *root, int s, int e);
void Rope_print(Rope *r);

typedef struct Node{
    int line_num;
    Rope **s;
    int ref_count;
    struct Node *next;
} Node;


typedef struct clipNode{
    Rope *s;
    struct clipNode *next;
} clipNode;

// Clioboard functions
void init_clip(clipNode **n);
void insert_clip(clipNode **n, Rope *r);
void print_clips(clipNode *clipboard);


int *Rope_search(Node* head, char *s, int *t);
void Rope_check(Rope *r, char *s, int *index, int *ans, int *flag, int str_len, int *count, int *output, int *total);

void Check_if_changed(Node *head, int line_num, Rope *s);

void LL_insert(Node **head, int line_num, Rope *s);
void LL_complete_display(Node *head);

void For_calls(Node **heads, clipNode **clipboard);

#endif
