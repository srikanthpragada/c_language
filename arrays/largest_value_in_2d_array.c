// Largest value and its position in 5 X 5 array
#include <stdio.h>

main()
{
  int a[5][5],j,i,lr,lc,largest;

     lr = lc = largest = 0;
     srand(time(0));
     for(i=0; i < 5; i ++)
     {
       for(j=0; j < 5; j ++)
       {
         a[i][j] = rand() % 100;
         printf("%5d", a[i][j]);
         if (a[i][j] > largest)
         {
            largest = a[i][j];
            lr = i;
            lc = j;
         }
       }
       printf("\n");
     }

     printf("\nLargest value is %d at (%d,%d)\n",largest,lr,lc);
}
