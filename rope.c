#include "rope.h"

void Rope_create(Rope **node, Rope *par, char *s, int l, int r, int leaf_len)
{
    
    Rope *tmp = malloc(sizeof(Rope));
    tmp->left = tmp->right = NULL;
    tmp->parent = par;

    if (par == NULL) {

        tmp->str = NULL;
        tmp->l_count = r;
        *node = tmp;
        Rope_create(&(tmp->left), tmp, s, l, r, leaf_len);

    } else if ((r - l) > leaf_len) {

        tmp->str = NULL;
        tmp->l_count = (r - l) / 2;
        *node = tmp;
        int m = (l + r) / 2;
        Rope_create(&(tmp->left), tmp, s, l, m, leaf_len);
        Rope_create(&(tmp->right), tmp, s, m, r, leaf_len);

    } else {
        *node = tmp;
        tmp->l_count = (r - l);
        int j = 0;
        tmp->str = malloc(leaf_len);
        for (int i = l; i < r; i++)
            tmp->str[j++] = s[i];
    }
}

Rope *Rope_new(char *s, int leaf_len)
{
    int len = strlen(s);
    if (len == 0)
        return NULL;
    Rope *root = NULL;
    Rope_create(&root, NULL, s, 0, len, leaf_len);
    return root;
}

Rope *Rope_subnew(char *s, int strt, int end, int leaf_len)
{
    if ((end > strlen(s) - 1) || (strt > end))
        return NULL;
    Rope *root = NULL;
    Rope_create(&root, NULL, s, strt, end, leaf_len);
    return root;
}

void Rope_delete(Rope *root)
{
    Rope *prev, *node = root;

    while(node != NULL) {
        
        if ((node->right == NULL) && (node->left == NULL)) {
            prev = node->parent;
            if (node->str != NULL)
                free(node->str);
            free(node);
            node = prev;
            continue;
        }
        
        if (node->right == NULL) {
            prev = node;
            node = node->left;
            prev->left = NULL;

        } else {
            prev = node;
            node = node->right;
            prev->right = NULL;
        }
        
    }
}

Rope *Rope_concat(Rope *root1, Rope *root2)
{
    char *s1 = Rope_to_str(root1);
    char *s2 = Rope_to_str(root2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = len1 + len2;

    char *s3 = strcat(s1, s2);

    Rope *tmp  = Rope_new(s3, 2);
    return tmp;
}

char *Rope_get_char(Rope *root, int i)
{
    int len = ROPE_LEN(root);

    if ((i > len - 1) || (len == 0))
        return NULL;

    i += 1;

    Rope *node = root->left;
    int pos = node->l_count;

    while(1) {
        if (pos >= i) {
            if (node->left == NULL) {
                int tmp = pos - (node->l_count - 1);
                i -= tmp;
                return &(node->str[i]);
            }
            Rope *par = node;
            node = node->left;
            pos -= (par->l_count - node->l_count);
        } else {
            node = node->right;
            pos += node->l_count;
        }
    }

}

bool Rope_set_char(Rope *root, int i, char c)
{
    int len = ROPE_LEN(root);

    if ((i > len - 1) || (len == 0))
        return false;

    i += 1;

    Rope *node = root->left;
    int pos = node->l_count;

    while(1) {
        if (pos >= i)
        {
            if (node->left == NULL)
            {
                int tmp = pos - (node->l_count - 1);
                i -= tmp;
                node->str[i] = c;
                return true;
            }
            Rope *par = node;
            node = node->left;
            pos -= (par->l_count - node->l_count);
        }
        else
        {
            node = node->right;
            pos += node->l_count;
        }
    }
}

char *Rope_to_str(Rope *root)
{
    int len = ROPE_LEN(root);
    char *s = malloc(len + 1);
    s[len] = '\0';
    char *pos = s;
    int i = 0;
    while(i < len)
        *pos++ = *(Rope_get_char(root, i++));
    return s; 
}

char *Rope_to_substr(Rope *root, int st, int e)
{
    int len = e - st + 1;
    char *s = malloc(len + 1);
    s[len] = '\0';
    char *pos = s;
    int i = st;
    int end = e + 1;
    while (i < end)
        *pos++ = *(Rope_get_char(root, i++));
    return s;
}

static void Rope_print_int(Rope *r)
{
    if (r == NULL)
        return;
    if ((r->left == NULL) && (r->right == NULL))
    {
        for (int i = 0; i < r->l_count; i++){
            putchar(r->str[i]);
        }
    }
    Rope_print_int(r->left);
    Rope_print_int(r->right);
}

void Rope_print(Rope *r){
    if(r==NULL){
        printf("Empty\n");
        return;
    }
    Rope_print_int(r);
    putchar('\n');
}

void LL_insert(Node **head, int line_num, Rope *s){
    if (*head == NULL){
        *head = malloc(sizeof(Node));
        (*head)->line_num = line_num;

        (*head)->s = malloc(sizeof(Rope *));
        (*head)->s[0] = s;

        (*head)->ref_count = 1;
        (*head)->next = NULL;
        printf("Added\n");
        return;
    }else{  
        Node *temp = *head;
        while(temp->next != NULL && temp->line_num != line_num){
            temp = temp->next;
        }
        if(temp->line_num == line_num){
            if (!strcmp(Rope_to_str(temp->s[temp->ref_count-1]), Rope_to_str(s))){
              printf("No Modification\n");
              return;
            }
            printf("Modified\n");
            temp->s = realloc(temp->s, sizeof(Rope *) * (temp->ref_count + 1));
            temp->s[temp->ref_count] = s;
            temp->ref_count++;
            return;
        }else{
            Node *nn = (Node *)malloc(sizeof(Node));
            nn->line_num = line_num;
            nn->s = malloc(sizeof(Rope *));
            nn->s[0] = s;
            nn->ref_count = 1;
            nn->next = NULL;
            temp->next = nn;
            printf("Modified\n");
            return;
        }

    }
}

void LL_complete_display(Node *head){
    Node *temp = head;
    while(temp != NULL){
            Rope_print(temp->s[temp->ref_count - 1]);
        temp = temp->next;
    }
    printf("EOF\n");
}

int *Rope_search(Node* head, char *search, int *t){
    int *output = calloc(1, sizeof(int));
    int *total = calloc(1, sizeof(int));
    int *count = calloc(1, sizeof(int));
    while (head != NULL){
        char *s = Rope_to_str(head->s[head->ref_count-1]);
        int *index = calloc(1, sizeof(int));
        int *ans = calloc(1, sizeof(int));
        int *flag = calloc(1, sizeof(int));
        Rope_check(head->s[head->ref_count-1], search, index, ans, flag, strlen(search), count, output, total);
        head=head->next;
    }

    // printf("Output: ");
    // for(int i = 0; i < total[0]; i++){
    //     printf("%d ", output[i]);
    // }
    t[0]=total[0];
    return output;
}

void Rope_check(Rope *r, char *s, int *index, int *ans, int *flag, int str_len, int *count, int *output, int *total){
    if (r == NULL)
        return;
    if ((r->left == NULL) && (r->right == NULL)){
        for (int i = 0; i < r->l_count; i++){
            count[0]++;
            // putchar(r->str[i]);
            if(r->str[i]==s[0] && flag[0]==0){
                ans[0]=count[0];
                // printf("\nYesh: %d\n", ans[0]);
                flag[0]=1;
            }
            if(r->str[i]==s[index[0]]){
                index[0]++;
            }else{
                index[0]=0;
                flag[0]=0;
            }
            if(index[0]==str_len){
                output = realloc(output, sizeof(int) * (total[0]+1));
                output[total[0]] = ans[0];
                total[0]++;
                index[0]=0;
            }
        }
    }
    Rope_check(r->left, s, index, ans, flag, str_len, count, output, total);
    Rope_check(r->right, s, index, ans, flag, str_len, count, output, total);
}

void Check_if_changed(Node *head, int line_num, Rope *s){
    printf("\nChecking!");
    Node *temp = head;
    while(temp != NULL && temp->line_num != line_num){
        temp = temp->next;
    }
    int s1=ROPE_LEN(s);
    int s2=ROPE_LEN(temp->s[temp->ref_count-1]);

    // printf("\n%d %d\n", s1, s2);

    char *str1 = Rope_to_str(s);
    char *str2 = Rope_to_str(temp->s[temp->ref_count-1]);
    int cmp = strcmp(str1, str2);
    if(cmp!=0){
        printf("Line %d has been changed\n", line_num);
        if(cmp>0){
            printf("Appended\n");
        }else{
            printf("Deleted\n");
        }
    }
    else{
        printf("\nLine %d has not been changed\n", line_num);
    }
    printf("\n");
}


void init_clip(clipNode **n){
  *n = NULL;
  return ;
}
void insert_clip(clipNode **n, Rope *r){

  clipNode *nn = (clipNode *) malloc(sizeof(clipNode));
  nn->s = r;
  if (!(*n)){
    nn->next = NULL;
    *n = nn;
    return;
  }
  nn->next = *n;
  *n = nn;
}

void print_clips(clipNode *clipboard){
  while(clipboard){
    printf("\n%s", Rope_to_str(clipboard->s));
    clipboard = clipboard->next;
  }
  printf("\nEOF\n");
  return;
}


// ======================Justafolk 
//

void insertLine(Node **n, Rope *s, int line_num){
  Node *nn = malloc(sizeof(Node));
  nn->s = malloc(sizeof(Rope *));
  nn->s[0] = s;
  nn->ref_count = 1;
  nn->line_num = line_num;
  nn->next = NULL;
  if(!(*n)){
    *n = nn;
    printf("didnt Line Added\n");
    return;
  }
  Node *temp = *n;
  Node *p;

  if (temp->line_num == line_num){
    nn->next = temp;
    *n = nn;
    nn = nn->next;
    while(nn){
      nn->line_num++;
      nn = nn->next;
    }

  }
  while(temp && temp->line_num < line_num){
    p = temp;
    temp = temp->next;
  }
  if (!temp){
    p->next = nn;
    printf("Line Added\n");
    return;
  }
  if (temp->line_num == line_num){
    nn->next = temp;
    p->next = nn;
    nn = nn->next;
    while(nn){
      nn->line_num++;
      nn = nn->next;
    }
  }
  printf("Line Added\n");

  return;

}

void rmLine(Node **n, int line_num){
  if(!(*n)){
    printf("Didnt Line Deleted\n");
    return;
  }
  Node *temp = *n;
  Node *p;

  if (temp->line_num == line_num){
    *n = (*n)->next;
    temp = *n;
    temp = temp->next;
    while(temp){
      temp->line_num--;
      temp = temp->next;
    }

  }
  while(temp && temp->line_num < line_num){
    p = temp;
    temp = temp->next;
  }
  if (!temp){
    printf("Line Deleted\n");
    return;
  }
  if (temp->line_num == line_num){
    p->next = temp->next;
    temp = temp->next;
    while(temp){
      temp->line_num--;
      temp = temp->next;
    }
  }
  printf("Line Deleted\n");

  return;

}

void LL_file_save(FLNode **FLhead, Node *head){
    if(*FLhead == NULL){
        FLNode *nn = (FLNode *)malloc(sizeof(FLNode));
        nn->version_num = 1;
        nn->lines = malloc(sizeof(Rope *));
        int index=0;
        while(head){
            int r=head->ref_count;
            char *s = Rope_to_str(head->s[r-1]);
            Rope *r1 = Rope_new(s, 2);

            nn->lines = realloc(nn->lines, sizeof(Rope*)*(index + 1));
            nn->lines[index]=r1;
            index++;

            head=head->next;
        }
        nn->line_count=index;
        nn->next = NULL;
        *FLhead = nn;
        return;
    }
    
    FLNode *temp = *FLhead;
    while(temp->next != NULL){
        temp = temp->next;
    }

    FLNode *nn = (FLNode *)malloc(sizeof(FLNode));
    nn->version_num = temp->version_num + 1;
    nn->lines = malloc(sizeof(Rope *));
    int index=0;
    while(head){
        int r=head->ref_count;
        char *s = Rope_to_str(head->s[r-1]);
        Rope *r1 = Rope_new(s, 2);

        nn->lines = realloc(nn->lines, sizeof(Rope *)*(index + 1));
        nn->lines[index]=r1;
        index++;

        head=head->next;
    }
    nn->line_count=index;
    nn->next = NULL;
    temp->next = nn;
}


void LL_retrieve_all(FLNode *fhead){
  if(!fhead )
    return;

  while(fhead){
    for(int i=0;i<fhead->line_count;i++){
        Rope_print(fhead->lines[i]);
    }
    printf("EOX\n");
    fhead = fhead->next;
  }

    printf("EOF\n");
}
void LL_retrieve_version(FLNode *fhead, int version_num){
  if(!fhead )
    return;

  while(fhead->version_num < version_num){
    fhead = fhead->next;
  }

  for(int i=0;i<fhead->line_count;i++){
      Rope_print(fhead->lines[i]);
  }

  printf("EOF\n");

}
