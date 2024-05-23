// Ver 2.0   - uses linked list 
// Display common lines in two files
// Files are provided on command line

#include <stdio.h>

struct node
{
    char line[100];
    int found;
    struct node * next;
};

int is_present(struct node * start, char line[])
{
  while(start != NULL)
  {
      if (strcmp(start->line, line) == 0 )  // found common line
      {
           if (start->found == 1)  // Already line was found so return false 
               return 0;
           else
           {
               start->found = 1;  // Turn flag on
               return 1;          // Return true as we encountered first time 
           }
      }
      start  = start -> next;
  }
  return 0;  // Not found
}

main(int argc, char * argv[])
{
  FILE * fp1, * fp2;
  char line[100];
  char * cp;
  struct node * root = NULL, * prev, * current;


  if ( argc < 3)
  {
    printf("Usage : commonlines2 file1 file2");
    exit(0);
  }

  fp1 = fopen(argv[1],"rt");
  if ( fp1 == NULL)
  {
      printf("Sorry! Could not open file %s. Quitting.", argv[1]);
      exit(1);
  }

  fp2 = fopen(argv[2],"rt");
  if ( fp2 == NULL)
  {
      printf("Sorry! Could not open file %s. Quitting.", argv[2]);
      exit(2);
  }

  while(1)
  {
      cp = fgets(line,100,fp1);
      if (cp ==  NULL)
        break;
      // add to list
      current = (struct node *) malloc(sizeof(struct node));
      current->next = NULL;
      current->found = 0;
      strcpy(current->line, line);

      if (root == NULL)  // first node
         root = current;
      else
         prev -> next = current;

      prev = current;
  }

  // Read second file and print common lines  
  while(1)
  {
      cp = fgets(line,100,fp2);
      if (cp ==  NULL)
        break;

      if (is_present(root,line))
        printf(line); // found in first file(list) so common line
  }


  fclose(fp1);
  fclose(fp2);



}
