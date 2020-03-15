// Search in 2d array
#include <stdio.h>

main()
{
  int a[5][5],j,i,num, found=0;

     srand(time(0));
     for(i=0; i < 5; i ++)
     {
       for(j=0; j < 5; j ++)
       {
         a[i][j] = rand() % 100;
         printf("%5d", a[i][j]);
       }
       printf("\n");
     }

     printf("\nEnter search number :");
     scanf("%d",&num);

     for(i=0; i < 5; i ++)
     {
       for(j=0; j < 5; j ++)
       {
         if(a[i][j] == num)
         {
             found = 1;
             break;
         }
       }
       // break outerloop if number is found
       if(found)
          break;
    }

    if(found)
         printf("\nFound at %d,%d\n",i,j);
    else
        printf("\nSorry! Number not found!\n");
}
