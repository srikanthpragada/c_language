// Program is to remove blank lines from a text file - names.txt
#include <stdio.h>

struct node
{
  char name[50];
  struct node * next;
};

main()
{
 struct node * root = NULL, * current, * prev;
 char line[100], *p;
 FILE * fp;

     fp = fopen("names.txt","rt");
     if ( fp == NULL)
     {
        printf("Sorry! Could not open file!");
        exit(1);
     }

     while(1)
     {
        p = fgets(line,100,fp);
        if (p == NULL) // EOF
          break;

        // ignore if found blank
        if (strlen(line) == 1) // len is 1 because of new line (\n)
           continue;

        // add line to linked list
        current = (struct node *) malloc(sizeof(struct node));
        strcpy(current->name,line);
        current->next = NULL;

        if (root == NULL) // first node
           root = current;  // root points to first node
        else
           prev->next = current; // make prev point to current

        prev = current;
     }

     fclose(fp);


     // write lines from list back to file
     fp = fopen("names.txt","wt");

     current = root;
     while(current != NULL)
     {
         printf("%s", current->name);
         fprintf(fp,"%s",current->name); // write line to file
         current = current -> next;
     }
     fclose(fp);

}

