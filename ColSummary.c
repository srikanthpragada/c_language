
main()
{
 int a[6][5];
 int i,j;

    // initialize last row
    for(i = 0; i < 5; i ++)
        a[5][i] = 0;

    // init random seed
    srand(time(0));

    // fill array with random numbers and also get totals to last row
    for(i=0; i < 5; i ++)
    {

        for(j=0; j < 5; j++)
        {

            a[i][j] = rand() % 100;
            a[5][i] += a[i][j];
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }


    // print last row, which contains totals
    for(i = 0; i < 5; i ++)
        printf("%d\t", a[5][i]);

}
