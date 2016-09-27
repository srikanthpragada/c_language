/* Matrix Multiplication -  Praneeth Pragada*/
#include<stdio.h>
#include<time.h>
int main()
{
    int a[3][3], b[3][3], c[3][3], i, j, k, sum=0;
    srand((unsigned int)time(NULL));

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            a[i][j]=rand()%10;
        }
    }

    printf("Matrix A is :\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            b[i][j]=rand()%10;
        }
    }

    printf("Matrix B is :\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            sum=0;

            for(k=0;k<3;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }

    printf("\nMatrix[A*B]\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%3d ", c[i][j]);
        }
        printf("\n");
    }


}
