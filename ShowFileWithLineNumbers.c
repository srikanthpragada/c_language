#include <stdio.h>

main()
{
   FILE * fp;
   char fn[100] = "f:\\c\\jan20\\colsum.c";
   char line[100];
   char * p;
   int lineno=1;


   fp = fopen(fn,"r");
   if ( fp == NULL)
   {
       printf("\nSorry! File not found!\n");
       exit(1);
   }

   while(1)
   {
       p = fgets(line,100,fp);  // read a line
       if ( p == NULL)
         break;
       printf("%3d: %s",lineno,line);  // print line with line number
       lineno++;
   }
   fclose(fp);
}
