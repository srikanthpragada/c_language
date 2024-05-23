// Remove blank lines from the given file

#include <stdio.h>
#define TEMPFILE "tempfile.txt"

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
  char line[100], *p;
  FILE * sfp, *tfp;

      if(argc < 2)
      {
          printf("Usage : removeblanklines filename");
          exit(1);
      }

      sfp = fopen(argv[1],"rt");
      if (sfp == NULL)
      {
         printf("\nFile [%s] not found!\n",argv[1]);
         exit(2);
      }

      tfp = fopen(TEMPFILE,"wt");
      if (tfp == NULL)
      {
         printf("\nSorry! Could not create temporary file!\n");
         exit(2);
      }

      while(1)
      {
        p = fgets(line,100,sfp);
        if (p == NULL)   // EOF
           break;
        if (isnonblank(line))  // Non-blank line
           fputs(line,tfp);
      }

      fclose(sfp);
      fclose(tfp);

      remove(argv[1]);
      rename(TEMPFILE,argv[1]);
}
