// Search for a number in 5X5 array and use goto to break out of two loops

# include <stdio.h>

main()
{
  int a[5][5];
  int i,j,num;

    srand(time(0));
    for(i=0; i < 5; i ++)
    {
       for(j=0; j < 5; j++)
       {
         a[i][j] = rand()%50;
         printf("%5d", a[i][j]);
       }
       printf("\n");
    }

    printf("\nEnter a number :");
    scanf("%d", &num);

    for(i=0; i < 5; i ++)
    {
       for(j=0; j < 5; j++)
       {
         if (a[i][j] == num) {
            printf("\nFound at : %d,%d",i,j);
            goto over;
         }
       }
    }

    printf("\nNot found");
    over:
        printf("\n");
}
