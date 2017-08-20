// Purpose: Print names in reverse order - STACK
// Date   : 20-Aug-2017
// Author : Srikanth Pragada
// Place  : Vizag

#include <stdio.h>

struct node
{
   char name[20];
   struct node * next;
};


main()
{
  struct node * root, * current, * prev;
  char name[20];

  prev = root = NULL;

  while(1)
  {
     printf("Enter a name :");
     gets(name);
     if ( strcmp(name,"end") == 0)
        break;

     // create a node
     current = (struct node *) malloc( sizeof(struct node));
     strcpy(current->name,name); // copy name into node

     root = current;
     current -> next = prev;

     prev = current; // make current prev for next round
  }


  // print list

  current  = root;

  while(current != NULL)
  {
     puts( current->name);
     current = current -> next;
  }


}
