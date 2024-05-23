#include <stdio.h>

main()
{
 FILE * fp;
 int ch, alpha, digits, others;
 char filename[50] = "f:\\c\\feb9\\test.txt";


 fp = fopen(filename,"r");
 if ( fp == NULL)
 {
    printf("Sorry! File [%s] not found!\n",filename);
    exit(1);
 }

 alpha = digits = others = 0;
 ch = fgetc(fp);
 while ( ch != -1)  // -1 means EOF
 {
     if (isalpha(ch))
           alpha ++;
     else
        if ( isdigit(ch))
             digits ++;
        else
             others ++;
     ch = fgetc(fp);
 }

 fclose(fp);

 printf("\nNo. of alphabets   : %d", alpha);
 printf("\nNo. of digits      : %d", digits);
 printf("\nNo. of other chars : %d", others);



}
