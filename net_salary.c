// Net salary calculation 
#include <stdio.h>
main()
{
int salary, hra, da, pf, gross, net;

    // Take salary from user
    printf("Enter basic salary : ");
    scanf("%d",&salary);

    // Calculate HRA,DA and PF
    hra = salary * 40 / 100;
    da = salary * 25 / 100;
    gross = salary + hra + da;
    pf = gross * 3 / 100;
    net  = gross - pf;

    // Print all details
    printf("Basic Salary    : %d\n", salary);
    printf("HRA             : %d\n", hra);
    printf("DA              : %d\n", da);
    printf("Gross Salary    : %d\n", gross);
    printf("PF              : %d\n", pf);
    printf("Net Salary      : %d\n", net);
}
