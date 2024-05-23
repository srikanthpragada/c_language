#include <stdio.h>

main(int argc, char * argv[])
{
  FILE * fp;
  char filename[30],line[100];
  int lineno;
  int i;

   if ( argc == 1)
   {
      printf("\nSyntax : printfile  <filename> ... \n");
      exit(0);
   }

   for(i = 1; i < argc ; i ++)
   {
     fp = fopen(argv[i],"r");
     if (fp == NULL)
     {
      printf("\n\n*********** Sorry! %s not found! **************\n\n",argv[i]);
      continue;
     }
     printf("\n\n*********%s*************\n\n", argv[i]);

     lineno = 1;
     while(1)
     {
       if( fgets(line,100,fp) == NULL)
           break;

       printf("%3d: %s",lineno,line);

       lineno++;
     } // while

     fclose(fp);
   } // for

} // main
