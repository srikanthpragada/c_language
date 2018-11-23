// Calculate Net price
#include <stdio.h>

void main()
{
  int qty, price, amount, discount, tax,gross_amount,net_price;

    printf("Enter quantity   : ");
    scanf("%d",&qty);
    printf("Enter price      : ");
    scanf("%d",&price);

    amount = qty * price;
    discount = amount * 0.10;
    gross_amount = amount - discount;
    tax = gross_amount * 0.12;
    net_price = gross_amount + tax;

    printf("\nAmount            : %d", amount);
    printf("\n - Discount       : %d", discount);
    printf("\n                   ---------");
    printf("\nGross Amount      : %d", gross_amount);
    printf("\n + Tax            : %d", tax);
    printf("\n                   ---------");
    printf("\nNet Price         : %d", net_price);
}
