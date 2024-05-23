#include <stdio.h>

void main()
{
  int n,sum;

    printf("Enter a number :");
    scanf("%d",&n);
    while(1)
    {
      sum=0;
      while(n)
      {
        sum += n % 10;
        n/=10;
      }
      if (sum < 10)
          break;
      n = sum;
    }
    
    printf("Single digit sum = %d",sum);

}
