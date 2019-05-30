// A function returns biggest and smallest values in an array using pass by reference 
#include <stdio.h>

void big_small(int a[], int * b, int *s)
{
 int i;

   *b = *s = a[0];
   for(i=1; i < 10; i ++)
   {
       if (a[i] > *b)
           *b = a[i];
       else
          if( a[i] < *s)
             *s = a[i];
   }
}

main()
{
  int a [10],i,b,s;

    srand(time(0));
    for(i=0; i <10; i ++) {
       a[i] = rand()% 100;
       printf("%d ",a[i]);
    }

    big_small(a,&b,&s);
    printf("\nBig : %d small : %d", b,s);
}
