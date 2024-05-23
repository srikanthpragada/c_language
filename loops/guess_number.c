#include <stdio.h>

main()
{
  int number, input, attempts=1;

   srand(time(0));
   number = rand() % 10;
   // printf("%d\n",number);
   while(attempts <= 3)
   {
     printf("\nEnter number :");
     scanf("%d",&input);
     if (input == number)
     {
        printf("Congrats!");
        break;
     }

     if (number < input)
        printf("\nNumber is smaller!");
     else
        printf("\nNumber is bigger!");

     attempts ++;
   }

   if(attempts > 3)
      printf("\nSorry! Better luck next time!");

}
