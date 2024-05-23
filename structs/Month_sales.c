#include <stdio.h>

struct sale
{
 char month[4];
 int  amount;
};

int is_month_present(char * month, struct sale sales[12])
{
  int i;

     for (i=0; i < 12; i ++)
       if (stricmp(sales[i].month, month) == 0)
          return 1;

     return 0;
}
main()
{
  struct sale sales[12];
  int  i, pos = 0;
  char month[4];
  int  amount, status;


     while(1)
     {
       fflush(stdin); // clear keyboard buffer
       printf("Enter month name : ");
       gets(month);
       if (stricmp(month,"end") == 0)
         break;
       status = is_month_present(month,sales);
       if(status == 1) // month found
           continue;

       printf("Enter sales  : ");
       scanf("%d",&amount);
       strcpy(sales[pos].month, month);
       sales[pos].amount = amount;
       pos++;
       if (pos == 12)  // Array is filled
          break;
     }

     // Print sales

     for (i=0; i < pos; i ++)
     {
        printf("%s  %d\n", sales[i].month, sales[i].amount);
     }

}
