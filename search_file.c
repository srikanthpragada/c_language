
#include <stdio.h>

main()
{
  FILE * fp;
  char filename[30],search[30], line[100];
  int lineno;

   // take input from user
   printf("Enter filename       : ");
   gets(filename);

   printf("Enter search string  : ");
   gets(search);

   fp = fopen(filename,"r");
   if (fp == NULL)
   {
      printf("\nSorry! %s not found!\n",filename);
      exit(1);
   }
   lineno = 1;
   while(1)
   {
       if( fgets(line,100,fp) == NULL)
           break;

       if (strstr(line,search))// not null means found
           printf("%3d: %s",lineno,line);

       lineno++;
   } // while

   fclose(fp);

}
