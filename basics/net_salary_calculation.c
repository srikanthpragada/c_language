// Calculate net salary based on salary 

#include <stdio.h>

void main()
{
  int salary, hra,da,gross,net,tax;

    printf("Enter salary : ");
    scanf("%d",&salary);

    if (salary > 20000)
    {
       hra = salary * 0.30;
       da = salary * 0.25;
    }
    else
    {
       hra = salary * 0.25;
       da = salary * 0.15;
    }

    gross = salary + hra + da;

    if (gross > 50000)
       tax = gross * 0.12;
    else
       tax = 0;

    net = gross - tax;

    printf("Salary      : %6d\n",salary);
    printf("+  HRA      : %6d\n",hra);
    printf("+  DA       : %6d\n",da);
    printf("Gross Salary: %6d\n",gross);
    printf("-  Tax      : %6d\n",tax);
    printf("Net Salary  : %6d\n",net);

}
