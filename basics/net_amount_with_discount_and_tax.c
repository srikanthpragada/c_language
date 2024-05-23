// Program to calculate net amount based on price and qty
// Date : 22-Mar-2019
// Author : Srikanth

#include <stdio.h>

void main()
{
  int price, qty, amount, discount = 0;
  int tax, grossamount, netamount;

    /* Take input from user  */
    printf("Enter price     : ");
    scanf("%d",&price);
    printf("Enter quantity  : ");
    scanf("%d",&qty);

    // Calculate net amount
    amount = qty * price;
    if (qty > 2)
      discount = amount * 0.10;

    grossamount = amount - discount;
    tax = grossamount * 0.12;
    netamount = grossamount + tax;

    // Display bill
    printf("\nBill\n");
    printf("Amount         :  %6d\n",amount);
    printf(" - discount    :  %6d\n",discount);
    printf("                  ------\n");
    printf("Gross Amount   :  %6d\n",grossamount);
    printf(" + Tax         :  %6d\n",tax);
    printf("                  ------\n");
    printf("Net Amount     :  %6d\n",netamount);
}
