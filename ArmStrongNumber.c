/* Armstrong Number */
#include<stdio.h>
#include<windows.h>
int main()
{
    int i, temp, n, digit, sum=0;
    system("COLOR 06");
    printf("Please enter a number : ");
    scanf("%d", &n);

    temp=n;

    while(temp!=0)
    {
        digit=temp%10;
        sum+=digit*digit*digit;
        temp=temp/10;
    }
	
    if(sum==n)
    {
		system("COLOR 02");
        printf("%d is an Armstrong Number", n);
	}
	else
	{
		system("COLOR 04");
        printf("%d is not an Armstrong Number", n);
	}
}
