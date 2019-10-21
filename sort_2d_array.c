// Sorting 5x5 array using 25 elements  array

# include <stdio.h>

main()
{
 int a[5][5], sd[25];
 int i,j,p,temp;


   srand(time(0));
   printf("\nOriginal Array\n");
   for(i=0; i < 5; i ++)
   {
    for(j = 0; j < 5; j ++)
    {
       a[i][j] = rand() % 100;
       printf("%5d", a[i][j]);
    }
    printf("\n");
   }

   // copy 2d array into 1d
   p = 0;
   for(i=0; i < 5; i ++)
   {
    for(j = 0; j < 5; j ++)
    {
       sd[p] = a[i][j];
       p++;
    }
   }

   // Sort 1d array
   for(i=0; i < 24; i ++)
   {
    for(j = i+1; j < 25; j ++)
    {
      if(sd[i] > sd[j])
      {
       temp = sd[i];
       sd[i] = sd[j];
       sd[j] = temp;
      }
    } // j loop
   }// i loop

   // copy 1d array into 2d
   printf("\nSorted 2D Array\n");
   p = 0;
   for(i=0; i < 5; i ++)
   {
     for(j = 0; j < 5; j ++)
     {
       a[i][j] = sd[p];
       printf("%5d", a[i][j]);
       p++;
     }
     printf("\n");
   }
}
