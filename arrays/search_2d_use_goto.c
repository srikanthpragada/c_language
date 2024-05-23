// Search in Matrix of 5 X 5 and use goto to come out of nested loops
#include <stdio.h>

void main()
{
int a[5][5];
int r,c, num, found = 0;

   srand(time(0));
   for (r = 0; r < 5 ; r++ )
   {
    for (c = 0; c < 5 ; c++ )
    {
       a[r][c] = rand() % 100;
       printf("%5d", a[r][c]);
    }
    printf("\n");
  }

  printf("\nEnter number : ");
  scanf("%d",&num);

  for (r = 0; r < 5; r++ )
  {
    for (c = 0; c < 5; c++ )
    {
       if( a[r][c] == num)
       {
           printf("Found at %d,%d\n",r,c);
           found = 1;
           goto showresult;
       }
    }
  }

  showresult:

  if(!found)
    printf("Sorry! Not found!");


}
