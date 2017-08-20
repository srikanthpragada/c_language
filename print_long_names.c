// Purpose: Print names that have more length than average length of names
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
  int count =0, total =0;
  int avg;

  root = NULL;

  while(1)
  {
     printf("Enter a name :");
     gets(name);
     if ( strcmp(name,"end") == 0)
        break;

     total +=  strlen(name);
     count ++;

     // create a node
     current = (struct node *) malloc( sizeof(struct node));
     strcpy(current->name,name); // copy name into node
     current->next = NULL;  // make next point to nothing

     if(root == NULL) // first node
        root = current;
     else
        prev->next = current; // make prev node point to this node


     prev = current; // make current prev for next round
  }

  avg = total / count;

  // print names that have length more than avg length

  current  = root;

  while(current != NULL)
  {
     if (strlen(current->name) >= avg)
          puts( current->name);

     current = current -> next;
  }


}
