/* Bubble Sort */

#include <stdio.h>
#include<time.h>

int main()
{
  int array[10], n, i, j, temp, swapped;

  // Initialize random seed
  srand(time(0));

  for (i=0;i < 10;i++)
    array[i]=rand()%100;

  printf("Array before sorting : ");

  for (i=0;i < 10;i++)
    printf("%5d", array[i]);

  for (i=0;i < 9;i++)
  {
    swapped = 0;  // False
    for (j=0;j < 9-i;j++)
    {
      if (array[j] > array[j+1])
      {
          temp = array[j];
          array[j] = array[j+1];
          array[j+1] = temp;
          swapped = 1;  // True
      }
    }

    // if no swapping was done then array is sorted and quit outer loop
    if (!swapped)
        break;
  }

  printf("\nArray after sorting  : ");

  for (i=0;i < 10;i++)
     printf("%5d", array[i]);
}
