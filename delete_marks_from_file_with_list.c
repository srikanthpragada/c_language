// Program to delete marks from marks.txt that are < 60 using linked list

#include <stdio.h>
#define FILENAME "marks.txt"

struct node {
   int marks;
   struct node * next;
};

main()
{
  FILE * fp;
  char * cp;
  struct node * root = NULL, * current, *prev;
  int marks;
  char line[10];

      fp = fopen(FILENAME,"rt");
      if(fp == NULL)
      {
        printf("Sorry! File cannot be opened!");
        exit(1);
      }
      
      // Build linked list to store all marks >= 60 

      while(1)
      {
         cp = fgets(line,10,fp);
         if (cp == NULL)
           break;

         marks = atoi(line);
         if (marks < 60)
            continue; // ignore marks

         // add line to list
         current = (struct node *)  malloc(sizeof(struct node));
         current->marks = marks;
         current->next = NULL;

         if (root == NULL) // first node
             root = current;
         else // second or after
             prev->next = current;

         prev = current;
      }

      // Write marks from list into file
      
      fp = fopen(FILENAME,"wt");
      current = root;
      while(current != NULL)
      {
         fprintf(fp,"%d\n", current->marks);
         current = current -> next;
      }

      fclose(fp);
}
