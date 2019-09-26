// Removing blank lines from names.txt using linked list 
#include <stdio.h>

struct node {
  char name[30];
  struct node * next;
};

main()
{
   FILE * fp;
   char * p, name[30];
   struct node * current, *prev, * root = NULL;

      fp = fopen("names.txt","rt");
      while(1)
      {
          p = fgets(name, 30, fp);
          if(p == NULL)
            break;
          // Ignore blank line
          if( strlen(name) <= 1)
               continue;

          // Allocate memory for a node
          current = (struct node *) malloc(sizeof(struct node));
          current->next = NULL;
          strcpy(current->name, name);

          if (root == NULL)
               root = current;
          else
               prev -> next = current;

          prev = current;
      }

      fclose(fp);

      fp = fopen("names.txt","wt");
      current = root;
      while (current != NULL)
      {
          fputs(current->name,fp);
          current = current -> next;
      }

      fclose(fp);

}
