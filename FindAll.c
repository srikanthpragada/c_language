#include <stdio.h>

main(int argc, char * argv[])
{
   FILE * fp;
   char line[100], * p;
   int i;

     if(argc < 3)
     {
         printf("Usage : find  <string> file ...\n");
         printf("\n<string> is the string that you want to search for");
         printf("\nfile... is one or more files in which you want to search for string");
         printf("\n\nExample : find  this myfile1.txt  myfile2.txt\n\n");
         exit(0);
     }

     for(i=2; i < argc; i ++)
     {
      fp = fopen(argv[i],"r");
      if (fp == NULL)
      {
        printf("\nSorry! File %s could not be opened!\n", argv[i]);
        continue;
      }

      printf("\n-------------------------");
      printf("\n%s",argv[i]);
      printf("\n-------------------------\n\n");

      while(1)
      {
        p = fgets(line,100,fp);
        if (p == NULL)
          break;

        if (strstr(line,argv[1]) != NULL)
             printf("%s",line);
      }

      fclose(fp);
     } // for

}
