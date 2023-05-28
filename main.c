#include "rope.h"


void For_calls(Node ***heads, clipNode **clipboard){

  int code;
  int choice;


  while (1){
    //for buffer
    //first code = 0
    //filename
    //operation code
    //rest of the inputs
    //printf("Enter 1 to insert, 2 to delete, 3 to display, 4 to search, 5 to concat, 6 to get substring, 7 to set char, 8 to get char, 9 to exit: \n");
    scanf("%d", &code);

    scanf("%d", &choice);
    if (code == 1){
      switch(choice){
        case 1:
          char *s = malloc(sizeof(char) * 100);
          scanf(" %[^\n]s", s);
          Rope *r = Rope_new(s, 2);
          insert_clip(clipboard, r);
          printf("%s\n", Rope_to_str((*clipboard)->s));
          break;
        case 2:
          printf("%s\n", Rope_to_str((*clipboard)->s));
          break;
        case 3:
          if ((*clipboard)->next){
            (*clipboard)->s = Rope_concat((*clipboard)->next->s, (*clipboard)->s);
            (*clipboard)->next = (*clipboard)->next->next;
          } else {
            (*clipboard)->s = Rope_concat(Rope_new(" ", 2), (*clipboard)->s);
          }
          printf("%s\n", Rope_to_str((*clipboard)->s));
          break;
        case 4:
          print_clips(*clipboard);

          break;
      }

    } else{
      // if mode 0
      // first enter buffer id 
      // then operation code 
      // then do your thing op

      // 1 = Insert
      // 2 = Display
      // 3 = line add                                                                                                                 
      // 4 = line del 
      // 6 = Get Substring
      // 7 = Get Substring Position


      switch (choice){
        case 1:
          int buf_id;
          scanf("%d", &buf_id);
          int line_num;
          scanf("%d", &line_num);
          printf("Enter string: ");
          char *s = malloc(sizeof(char) * 150);
          scanf(" %[^\n]s", s);
          Rope *r = Rope_new(s, 2);
          LL_insert(heads, line_num, r);

          fflush(stdout);
          break;
        case 2:
          printf("Enter line number: ");
          int line_num2;
          scanf("%d", &line_num2);
          Node *temp = *heads;
          while(temp->next != NULL && temp->line_num != line_num2){
            temp = temp->next;
          }
          if(temp->line_num == line_num2){
            // temp->ref_count--;
            // if(temp->ref_count == 0){
            //     free(temp->s);
            //     temp->s = NULL;
            // }
            Rope_delete(temp->s[temp->ref_count]);
          }
          break;
        case 3:
          LL_complete_display(*heads);
          break;
        case 4:
          printf("Enter String to search: ");
          char *s2 = malloc(sizeof(char) * 100);
          scanf("%s", s2);
          // Call Search Function
          break;
        case 5:
          printf("Enter line number 1: ");
          int line_num3;
          scanf("%d", &line_num3);
          printf("Enter line number 2: ");
          int line_num4;
          scanf("%d", &line_num4);

          Node *temp1 = *heads;
          Node *temp2 = *heads;
          while(temp1->next != NULL && temp1->line_num != line_num3){
            temp1 = temp1->next;
          }
          while(temp2->next != NULL && temp2->line_num != line_num4){
            temp2 = temp2->next;
          }

          if(temp1->line_num == line_num3 && temp2->line_num == line_num4){
            Rope *r1 = temp1->s[temp1->ref_count-1];
            Rope *r2 = temp2->s[temp2->ref_count-1];
            Rope *r3 = Rope_concat(r1, r2);
            // printf("R3: \n");
            // Rope_print(r3);
            LL_insert(heads, line_num3, r3);
          }
          break;
        default:
          break;
      }
    }

    fflush(stdout);
  }

}



int main(void) {

  Node **head= malloc(sizeof(Node *) * 5);
  clipNode *clipboard=NULL;
  For_calls(&head, &clipboard);
  return 0;
}

