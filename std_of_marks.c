// Build linked list to show STD  of marks taken from user
#include <stdio.h>

struct node
{
   int marks;
   struct node * next;
};

main()
{
  struct node * root = NULL, *current, *previous;
  int marks, total = 0, count = 0, avg;

    while(1)
    {
      printf("Enter marks :");
      scanf("%d",&marks);
      if (marks < 0)
         break;

      // allocate memory for a node
      current = (struct node *) malloc(sizeof(struct node));
      current->next = NULL;
      current->marks = marks;
      total += marks;
      count ++;

      if(root == NULL) // first node of the list
          root = current;
      else
          previous -> next = current;

      previous = current;
    }

    avg = total / count;
    // print marks
    current = root;
    while(current != NULL)
    {
       printf("%3d - %3d\n", current->marks, current->marks - avg);
       current = current -> next;
    }
}

