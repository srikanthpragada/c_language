// Checks whether the given numbers on command line are prime numbers

// Prime number program
#include <stdio.h>


int valid_number(char * s)
{
    int i;

     for(i=0; s[i] ; i ++)
     {
        if (! (isdigit(s[i]) || s[i] == '-' || s[i] == '+') )
           return 0; // false;
     }
     return 1;
}

main(int argc, char * argv[])
{
   int num,n, i, prime;

   if (argc < 2)
   {
       printf("Usage: prime  number ... \n");
       exit(1);
   }

   for(i=1; i < argc ; i ++)
   {
     if(!valid_number(argv[i]))
     {
       printf("[%s] is not a valid number!\n", argv[i]);
       continue;
     }
      num = atoi(argv[i]);
      prime = 1;
      for(n=2; n <= num/2; n ++)
      {
         if (num % n == 0 )
         {
            printf("[%d ] Not a prime number!\n", num);
            prime = 0;
            break;
         }
      }  // inner for

      if (prime)
        printf("[%d] Prime number!\n", num);
   } // outer for
} // main


Sample output 1:
================

F:\c\nov28>prime 98 17
[98 ] Not a prime number!
[17] Prime number!

Sample output 2:
================

F:\c\nov28>prime 98 abc 87 bbc 93
[98 ] Not a prime number!
[abc] is not a valid number!
[87 ] Not a prime number!
[bbc] is not a valid number!
[93 ] Not a prime number!

