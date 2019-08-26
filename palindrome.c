// Palindrome program
#include <stdio.h>

void main()
{
int num,pnum, digit, rnum = 0;

   printf("Enter a number :");
   scanf("%d",&num);
   pnum = num;

   while(num > 0)
   {
      digit = num % 10;
      rnum = digit + rnum * 10;
      num /= 10;
   }

   if(rnum == pnum)
      printf("Palindrome");
   else
      printf("Not a Palindrome");

}
