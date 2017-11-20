// STACK
// Prints lines from a file in reverse order - last line first 
#include <stdio.h>


struct node
{
  char name[30];
  struct node * prev;
} *root = NULL ,*current, *prev;


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


        if(root == NULL)  // First node?
          current->prev = NULL;
        else
          current->prev = prev;  // Make prev one point to current one

        prev = current; // make current one prev for next round
        root = current;
     }


     current = root;
     while(current != NULL)
     {
        printf(current->name);
        current = current -> prev;
     }


}
