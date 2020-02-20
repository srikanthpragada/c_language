//  Customers manager

#include <stdio.h>
#define FILENAME  "customers.dat"

struct customer
{
   char name[30], email[50], phone[50];
};

typedef struct customer CUSTOMER;

void add_customer()
{
  FILE * fp;
  CUSTOMER c;

     // Open file in append binary mode
     fp = fopen(FILENAME,"ab");
     // check whether file is opened - to do
     fflush(stdin); // clear keyboard buffer
     printf("\nEnter name  :");
     gets(c.name);
     printf("Enter email :");
     gets(c.email);
     printf("Enter phone :");
     gets(c.phone);

     fwrite(&c,sizeof(c),1,fp);
     fclose(fp);
}

void list_customers()
{
  FILE * fp;
  CUSTOMER c;
  int count;

     fp = fopen(FILENAME,"rb");
     printf("\n\n *** Customers ***\n");
     while(1)
     {
         count = fread(&c,sizeof(c),1,fp);
         // if count is 0 then it is EOF
         if (count == 0)
             break;
         printf("\n%-30s  %-30s  %s",c.name, c.email,c.phone);
     }
     fclose(fp);
     printf("\n\n****** The End *******\n");
}

// Take customer number and new phone number to update file
void update_customer()
{
    FILE * fp;
    CUSTOMER c;
    int count,id;

     fp = fopen(FILENAME,"r+b");
     // customer id is position of customer in the file
     printf("Enter customer id : ");
     scanf("%d",&id);

     // Move to record for the given customer
     fseek(fp, sizeof(c) * (id-1),SEEK_SET);
     fread(&c,sizeof(c),1,fp);  // read customer details from file
     printf("New Phone number  : ");
     scanf("%s",c.phone);
     // Move back to record
     fseek(fp, sizeof(c) * (id-1),SEEK_SET);
     // Write block from memory to file
     fwrite(&c,sizeof(c),1,fp);
     fclose(fp);
}

main()
{
int choice;

    while(1)
    {
       printf("\n*** Menu ***\n");
       printf("\n 1. Add Customer");
       printf("\n 2. List Customers");
       printf("\n 3. Update Customer");
       printf("\n 4. Exit");
       printf("\n Choice [1-4] : ");
       scanf("%d",&choice);

       switch(choice)
       {
          case 1 : add_customer();
                   break;
          case 2 : list_customers();
                   break;
          case 3 : update_customer();
                   break;
          case 4 : exit(1);
       }
    } // while
}
