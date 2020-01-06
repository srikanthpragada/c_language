// Remove blank lines from a file using linked list
#include <stdio.h>

struct node
{
  char line[100];
  struct node * next;
};

int isnonblank(char * s)
{
  int i;
      for(i=0; s[i] != 0; i ++)
      {
        if (!isspace(s[i]))
           return 1;   // non-blank line
      }
      return 0;
}


main(int argc, char * argv[])
{
  struct node * root, * current, * prev;
  char line[100], *p;
  FILE * fp;

      if(argc < 2)
      {
          printf("Usage : removeblanklines filename");
          exit(1);
      }

      fp = fopen(argv[1],"rt");
      if (fp == NULL)
      {
         printf("\nFile [%s] not found!\n",argv[1]);
         exit(2);
      }

      root = current = prev = NULL;
      while(1)
      {
        p = fgets(line,100,fp);
        if (p == NULL)   // EOF
           break;

        if (isnonblank(line))  // Non-blank line
        {
           // add a new node with this line
           current = (struct node *) malloc(sizeof(struct node));
           if (current == NULL) {
              printf("Sorry! Memory allocation error. Quitting!");
              exit(3);
           }
           strcpy(current->line,line);
           current->next = NULL;

           if(root == NULL)  // first node?
              root = current;
           else
              prev->next = current; // make previous node point to current

           prev = current;
        }

      } // while

      fclose(fp);

      // write lines from linked list to file
      fp = fopen(argv[1],"wt");
      if (fp == NULL)
      {
         printf("\nFile [%s] could not be created!\n",argv[1]);
         exit(4);
      }


      current = root;
      while(current != NULL)
      {
         fputs(current->line,fp);
         current = current -> next;
      }

      fclose(fp);

}
