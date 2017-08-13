// Sort a linked list by re-arranging links (Pointers) and not by swapping data
#include <stdio.h>
#include <stdlib.h>

struct node  {
    int data;
    struct node * next;
}*root, *current, *prev;


void sort(struct node ** head);
void print(struct node * start);

int  main()
{
    int data,i;
    root = NULL;
    int a[] = {1,1,2,0,0};

    // Build a linked list with values from Array
    for(i=0; i < 5 ; i ++)
    {
        // allocate a block
        current = (struct node *) malloc(sizeof(struct node));
        current->next = NULL;
        current->data = a[i];

        if (root == NULL)
            root = current; // set root to first node
        else
            prev->next = current;

        prev = current;
    } // for

    // print list

    print(root);
    sort(&root);
    printf("\nFinal List \n");
    print(root);

}

void sort(struct node ** head) {

  struct node * start, * current, * prev, * nextnext;
  int in_order;

  start = * head;
  in_order = 0;

  while(!in_order)
  {

      current = prev = start;
      in_order = 1;  // indicates list is sorted. But it will be set to 0 when we swap nodes

      while ( current -> next != NULL)
      {
           // current is first node and curent->next is second node
           if ( current -> data > current-> next -> data)
           {
               // Make first node point to next of second and second point to first node
               if ( current == start)
               {
                     start = current ->next;  // change start to point to second node
               }
               else
               {
                    prev->next = current -> next;   // make prev node, which pointed to first, now point to second node
               }

               nextnext = current->next -> next;    // remember what second node points to
               current -> next  -> next  = current; // make second node point to first node
               prev = current->next;                // set prev to second node
               current -> next  = nextnext;         // make first point to what second node used to point

               in_order = 0;  // turn off to indicate list is not fully sorted
           }
           else
           {
              // when nodes are in orders then move to next node
              prev = current;
              current = current ->next;
           }
      } // inner while

  } //outer while

  *head = start;  // change head so that it points to new start

}

// print the given list from the given starting address
void print(struct node * start)
{

 struct node * current;

    current = start;
    while(current != NULL)
    {
        printf("%d\n", current->data);
        current = current ->next;
    }
}
