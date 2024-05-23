/* Floyd Triangle - Praneeth Pragada */
#include<stdio.h>
main()
{
    int i=1, a, b=1;

    printf("Enter number of rows of Floyd triangle to be displayed :");
    scanf("%d", &a);

    while(i<=a)
    {
        int j=i;

        while(j>0)
        {
            printf("%2d ", b);
            j--;
            b++;
        }

        printf("\n");
        i++;
    }

}
