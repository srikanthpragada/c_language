/* Bubble Sort  - Praneeth Pragada*/
#include <stdio.h>
#include<time.h>
int main()
{
  int array[100], n, i, j, swap;
  srand((unsigned int)time(NULL));

  printf("Enter number of elements :\n");
  scanf("%d", &n);

  for (i=0;i<n;i++)
    array[i]=rand()%100;

  printf("Array before sorting :\n");

  for (i=0;i<n;i++)
    printf("%d ", array[i]);

  for (i=0;i<(n-1);i++)
  {
    for (j=0;j<(n-i-1);j++)
    {
      if (array[j]>array[j+1])
      {
          swap       = array[j];
          array[j]   = array[j+1];
          array[j+1] = swap;
      }
    }
  }

  printf("\nArray after sorting :\n");

  for (i=0;i<n;i++)
     printf("%d ", array[i]);
}
