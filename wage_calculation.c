// Calculate wage
#include <stdio.h>
void main()
{
  int hours, rate, wage, bonus, gross_wage,net_wage,tax;

    printf("Enter hours and rate :");
    scanf("%d%d",&hours,&rate);

    wage = hours * rate;
    bonus = wage * 0.5;
    gross_wage = wage + bonus;
    tax = gross_wage * 0.05;
    net_wage = gross_wage - tax;

    printf("No. of hours    : %6d\n",hours);
    printf("Rate per hour   : %6d\n",rate);
    printf("Wage            : %6d\n",wage);
    printf(" + Bonus        : %6d\n",bonus);
    printf("Gross Wage      : %6d\n",gross_wage);
    printf("- Tax           : %6d\n",tax);
    printf("Net Wage        : %6d\n",net_wage);

}
