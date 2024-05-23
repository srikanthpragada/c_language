// Build linked list to show STD  of marks taken from marks.txt
#include <stdio.h>

struct node
{
   int marks;
   struct node * next;
};

int isnumber(char st[])
{
    int i;

    for(i=0; st[i]; i ++)
    {
      if (! (isdigit(st[i]) || st[i] == '\n'))
         return 0; // false
    }
    return 1; // true
}

main()
{
  struct node * root = NULL, *current, *previous;
  int marks, total = 0, count = 0, avg;
  FILE * fp;
  char line[10];

    // open file
    fp = fopen("marks.txt","rt");
    if ( fp == NULL)
    {
        printf("\nSorry! File cannot be opened!\n");
        exit(1);
    }


    while(1)
    {
      if (fgets(line,10,fp) == NULL)  // stop if EOF reached
          break;

      if (strlen(line) == 1) // blank line, so ignore
          continue;

      if (!isnumber(line))  //  non-number, so ignore
          continue;

      marks = atoi(line);

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

    fclose(fp);
    avg = total / count;

    // print marks
    current = root;
    while(current != NULL)
    {
       printf("%3d - %3d\n", current->marks, current->marks - avg);
       current = current -> next;
    }
}

