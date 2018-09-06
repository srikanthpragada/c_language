// Convert file content to uppercase
#include <stdio.h>
main()
{
  FILE * sfp, * tfp;
  char sfile[30], tfile[30];
  int ch;

     printf("Enter source filename :");
     gets(sfile);

     printf("Enter target filename :");
     gets(tfile);

     sfp = fopen(sfile,"rt");  // create file
     if (sfp == NULL)
     {
        printf("Sorry! Could not open file!");
        exit(0);
     }

     tfp = fopen(tfile,"wt");  // create file
     if (tfp == NULL)
     {
        printf("Sorry! Could not create file!");
        exit(0);
     }

     while(1)
     {
       ch = fgetc(sfp);
       if(ch == EOF)
          break;

       fputc(toupper(ch),tfp);
     }

     fclose(sfp);
     fclose(tfp);
}

