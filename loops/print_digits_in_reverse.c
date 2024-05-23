// Print digits in reverse order
#include <stdio.h>

main()
{
 int num,digit;

    printf("Enter a number :");
    scanf("%d",&num);

    while(num > 0)
    {
        digit = num % 10;  // take rightmost digit
        printf("%d", digit);
        num /= 10;        //  remove rigthmost digit
    }
}
