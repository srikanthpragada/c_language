#include <stdio.h>

main()
{
  int amount,discount, tax, net_amount,taxable_amount;

    printf("Enter amount :");
    scanf("%d",&amount);
    // calculate discount
    if (amount > 10000)
       discount = amount * 0.10;
    else
       discount = amount * 0.05;

    taxable_amount = amount - discount;

    // calculate tax
    if (taxable_amount > 5000)
         tax = taxable_amount * 0.12;
    else
         tax = 0;

    net_amount = taxable_amount + tax;

    // print details
    printf("Amount     : %10d\n",amount);
    printf("Discount   : %10d\n",discount);
    printf("Taxable    : %10d\n",taxable_amount);
    printf("Tax        : %10d\n",tax);
    printf("Net amount : %10d", net_amount);
}
