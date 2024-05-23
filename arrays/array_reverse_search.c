// Find position of a number from end of array

main()
{
  int a[10],n,i;

    srand(time(0));
    for (i=0; i < 10; i ++)
    {
       a[i] = rand() % 50;
       printf("%d ",a[i]);
    }

    printf("\nEnter number :");
    scanf("%d",&n);

    //Search in reverse order
    for(i = 9 ; i >= 0; i --)
    {
        if (a[i] == n)
        {
            printf("\nFound at %d",i);
            exit(0); // stop program
        }
    }
    printf("\nNumber not found!");
}
