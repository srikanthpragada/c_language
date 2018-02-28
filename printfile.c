/*
 Program to print files given on command line along with line numbers 
*/

#include <stdio.h>

main(int argc, char * argv[])
{
   FILE *fp;
   char * p;
   char name[100];
   int lineno,i;


       if(argc == 1)   // no parameters passed
       {
           printf("Usage : printfile  filename1  [filename2] ...");
           printf("\n\nPrints given files with line numbers.");
           printf("\n\nExample: printfile hello.c names.txt\n");
           printf("Will print hello.c and names.txt with line numbers one after another.\n");


           exit(0);
       }

       for(i = 1; i < argc ; i ++)
       {
         fp = fopen(argv[i],"r");  // Open in write mode
         if (fp == NULL)
         {
             printf("\n***********************************************");
             printf("\nSorry! File [%s] cannot be opened!!\n", argv[i]);
             printf("***********************************************\n\n");
             continue;
         }

         printf("\n\n*********** %s **************\n\n", argv[i]);
         lineno = 1;
         while(1)
         {
           p = fgets(name,100,fp);
           if (p == NULL) // EOF
            break;

           printf("%3d: %s",lineno,name);
           lineno ++;
         }

         fclose(fp);

       } // for loop
}

