#include "rope.h"


void For_calls(Node ***heads, clipNode **clipboard){


  FLNode *fhead=NULL;
  int code;
  int choice;

  int buf_id;
  Node **head = *heads;

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
      // 5 = Save version 
      // 6 = Retreive version 


      scanf("%d", &buf_id);
      int line_num;
      int ver;
      switch (choice){
        case 1:
          scanf("%d", &line_num);
          char *s = malloc(sizeof(char) * 150);
          scanf(" %[^\n]s", s);
          Rope *r = Rope_new(s, 2);
          LL_insert(&head[buf_id], line_num, r);
          break;
        case 2:
          LL_complete_display(head[buf_id]);

          break;
        case 3:
          scanf("%d", &line_num);
          char *s2 = " ";
          Rope *r2 = Rope_new(s2, 2);
          insertLine(&head[buf_id], r2, line_num);
          break;
        case 4:
          scanf("%d", &line_num);
          rmLine(&head[buf_id], line_num);
          break;
        case 5:
          LL_file_save(&fhead, head[buf_id]);
          printf("File saved successfully\n");
          break;
        case 6:
          scanf("%d", &ver);
          LL_retrieve_version(fhead, ver);

        case 7:
          LL_retrieve_all(fhead);
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

