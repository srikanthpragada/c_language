#include <stdio.h>

main()
{

    int a[5][5];
    int i,j,num;

     srand(time(0));

     for(i=0; i <5; i ++)
     {
         for (j=0; j < 5; j ++)
         {
             a[i][j] = rand() % 100;
             printf("%d\t", a[i][j]);
         }
         printf("\n");
     }

     printf("Enter number :");
     scanf("%d",&num);

     for(i=0; i <5;  i ++)
     {
         for (j=0; j < 5; j ++)
         {
            if ( a[i][j] == num)
            {
                printf("\nFound at %d x %d\n", i, j);
                goto end;
            }
         }
     }
     printf("\nSorry! Number not found!");

     end:
     printf("\n");
}
