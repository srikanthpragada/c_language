// Products Manager
#include <stdio.h>
#define FILENAME  "products.dat"

struct product
{
  char name[20];
  int price;
};

main()
{
  int choice;

   while(1)
   {
      printf("\n\nMenu\n");
      printf("============\n");
      printf("1.Add Product\n");
      printf("2.List Products\n");
      printf("3.Change Price\n");
      printf("4.Delete Product\n");
      printf("5.Search Products\n");
      printf("6.Exit\n");

      printf("\nEnter choice [1-6] : ");
      scanf("%d",&choice);

      switch(choice)
      {
         case 1:  add_product(); break;
         case 2:  list_products(); break;
         case 5:  search_products(); break;
         case 6:  exit(0);
      }
   } // while
}

void add_product()
{
  FILE * fp;
  struct product p;

     fp = fopen(FILENAME,"ab");
     if (fp == NULL)
     {
         printf("Sorry! File could not be opened!");
         return;
     }
     fflush(stdin); // clear keyboard buffer
     printf("Enter product name  : ");
     gets(p.name);

     printf("Enter product price : ");
     scanf("%d",&p.price);

     fwrite(&p,sizeof(p),1,fp);

     fclose(fp);
}

void list_products()
{
   FILE * fp;
   struct product p;
   int count;

   fp = fopen(FILENAME,"rb");
   if (fp == NULL)
   {
     printf("Sorry! File could not be opened!");
     return;
   }

   printf("\n\nList of Products\n");
   printf("\n\n================\n");

   while(1)
   {
      count = fread(&p,sizeof(p),1,fp);
      if(count == 0)  // didn't read block successfully due to EOF
        break;

      printf("\n%-20s  %d",p.name,p.price);
   }

   printf("\n\nPress any key to continue...");
   getch();

   fclose(fp);
}

void search_products()
{
   FILE * fp;
   struct product p;
   char name[20];
   int count;

   fp = fopen(FILENAME,"rb");
   if (fp == NULL)
   {
     printf("Sorry! File could not be opened!");
     return;
   }

   fflush(stdin);
   printf("\nEnter product name : ");
   gets(name);

   printf("\n\nSearch Result\n");
   printf("================\n");

   while(1)
   {
      count = fread(&p,sizeof(p),1,fp);
      if(count == 0)  // didn't read block successfully due to EOF
        break;
      if(strstr(p.name,name) != 0)
         printf("\n%-20s  %d",p.name,p.price);
   }

   fclose(fp);
   printf("\n\nPress any key to continue...");
   getch();
}
