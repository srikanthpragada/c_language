// Validate PIN entered by user
#include <stdio.h>

main()
{
   char ch;
   int i, dcount;

     dcount = 0;
     printf("Enter Pin :");
     for(i=1; i <= 4; i ++)
     {
       ch = getch();
       putch('.');

       if (isdigit(ch) )
           dcount ++;
    }

    if (dcount == 4)
        printf("\nValid PIN");
    else
        printf("\nInvalid PIN");
}
