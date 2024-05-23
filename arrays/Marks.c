#include <stdio.h>

main()
{
   int marks[10];
   int i;

    srand( time(NULL));
    for(i=0; i < 10; i ++)
    {
        marks[i] = rand() % 100;
    }


    printf("\nPassed List\n");

    for(i=0; i < 10; i ++)
    {
       if( marks[i] >= 50)
         printf("%2d %2d\n", i + 1, marks[i]);
    }

    printf("\nFailed List\n");

    for(i=0; i < 10; i ++)
    {
       if( marks[i] < 50)
         printf("%2d %2d\n", i + 1, marks[i]);
    }
}
