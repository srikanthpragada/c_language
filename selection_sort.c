// Selection sort

#include <stdio.h>

main()
{
  int a[10];
  int i,temp,min_pos,j;

     srand(time(0));
     printf("Original Array\n\n");
     for(i=0; i < 10; i ++)
     {
        a[i] = rand() %100;
        printf("%4d",a[i]);
     }

     // sort array
     for(i=0; i < 9; i ++)
     {
         min_pos = i;
         for(j=i + 1; j < 10; j ++)
         {
             if (a[min_pos] > a[j])
                  min_pos = j;
         }

         // Interchange ith element with min_pos element
         if(i != min_pos)
         {
           temp = a[i];
           a[i] = a[min_pos];
           a[min_pos] = temp;
         }

     }

     printf("\n\nAfter Sorting\n\n");
     for(i=0; i < 10; i ++)
     {
        printf("%4d",a[i]);
     }
}
