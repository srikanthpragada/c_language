/* Armstrong Number */
#include<stdio.h>

int main()
{
    int i, temp, n, digit, sum=0;

    printf("Enter a number :");
    scanf("%d", &n);

    temp=n;

    while(temp!=0)
    {
        digit=temp%10;
        sum+=digit*digit*digit;
        temp=temp/10;
    }

    if(sum==n)
        printf("%d is an Armstrong Number", n);
    else
        printf("%d is not an Armstrong Number", n);
}
