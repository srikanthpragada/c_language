// STACK
#include <stdio.h>


struct node
{
  char name[30];
  struct node * prev;
} *root,*current, *prev = NULL;


main()
{
   FILE * fp;
   char  line[50];
   char * p;

     fp = fopen("names.txt","r");

     while(1)
     {
        p = fgets(line,50,fp);
        if (p == NULL)  // EOF
           break;

        // allocate memory for node
        current = (struct node *) malloc( sizeof(struct node));
        strcpy(current->name, line);

        current->prev = prev;
        prev = current;
        root = current;
     }


     current = root;
     while(current != NULL)
     {
        printf(current->name);
        current = current -> prev;
     }


}
