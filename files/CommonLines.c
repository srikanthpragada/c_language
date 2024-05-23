// Ver. 1.0 
// Display common lines in two files
// Files are provided on command line

#include <stdio.h>
main(int argc, char * argv[])
{
  FILE * fp1, * fp2;
  char line1[100], line2[100];
  char * cp;

  if ( argc < 3)
  {
    printf("Usage : commonlines file1 file2");
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
      cp = fgets(line1,100,fp1);
      if (cp ==  NULL)
        break;

      // read and compare first file line with each line in second file
      fseek(fp2,0,0);
      while(1)
      {
          cp = fgets(line2,100,fp2);
          if (cp ==  NULL)
              break;
          if (strcmp(line1,line2) == 0)
          {
              printf(line1);
              break;
          }
      }
  }
  fclose(fp1);
  fclose(fp2);
}
