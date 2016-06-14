
#include <stdio.h>

main(int argc, char * argv[])
{
  int i;
  int end=20;
  int num;

    if (argc == 1)  // check whether no command line arguments are given 
    {
        printf("Enter a number :");
        scanf("%d",&num);
    }
    else
        num = atoi(argv[1]);  // string to int


    if (argc > 2)
        end = atoi(argv[2]);  // string to int


    for(i=1; i <= end ; i ++)
    {
        printf("%5d * %5d = %5d\n", i, num, i * num);
    }

    printf("\nPress a key to continue...");
    getch();



}
