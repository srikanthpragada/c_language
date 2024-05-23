// Products manager - Manages products in products.dat
// Date : 26-JUNE-2018

#include <stdio.h>
#define  FILENAME "products.dat"
#define  TEMPFILE "temp.dat"

struct product
{
      char name [50];
      int price,qoh;
};

FILE * open_file(char * mode)
{
    FILE * fp;

      fp = fopen(FILENAME, mode);
      if (fp == NULL)
      {
          printf("Sorry! File %s could not be opened in %s mode. Quitting.", FILENAME,mode);
          exit(1);
      }
      return  fp;
}

void add_product()
{
   FILE * fp;
   struct product p;

      fp = open_file("ab");
      // clear keyboard buffer
      fflush(stdin);
      printf("Enter product name : ");
      gets(p.name);
      printf("Enter product price: ");
      scanf("%d",&p.price);
      printf("Enter product qty  : ");
      scanf("%d",&p.qoh);
      fwrite(&p,sizeof(struct product),1,fp);
      fclose(fp);
      printf("\nSuccessfully added a new product.\n");
}

void list_products()
{
  FILE * fp;
  struct product p;
  int count;

      fp = open_file("rb");
      printf("\nList Of Products\n");

      while(1)
      {
          count = fread(&p,sizeof(struct product),1,fp);
          if (count == 0)  // EOF
            break;
          printf("%-50s  %10d  %4d\n", p.name, p.price, p.qoh);
      }
      fclose(fp);
}

void get_product_details()
{
  FILE * fp;
  struct product p;
  int count, prodid;

      fp = open_file("rb");
      printf("Enter product id : ");
      scanf("%d",&prodid);
      fseek(fp, sizeof(struct product) * (prodid - 1), SEEK_SET);
      count = fread(&p,sizeof(struct product),1,fp);
      if (count == 1)
         printf("%-50s  %10d  %4d\n", p.name, p.price, p.qoh);
      else
         printf("\nProduct Id Not Found!\n");
      fclose(fp);

}


void  update_product_price()
{
  FILE * fp;
  struct product p;
  int count, prodid;

      fp = open_file("r+b");
      printf("Enter product id : ");
      scanf("%d",&prodid);
      fseek(fp, sizeof(struct product) * (prodid - 1), SEEK_SET);  // 1
      count = fread(&p,sizeof(struct product),1,fp);  // 2
      if (count == 1) {
           printf("Enter new price : ");
           scanf("%d",&p.price);  // 3
           // write back to file
           fseek(fp, sizeof(struct product) * (prodid - 1), SEEK_SET);  // 4
           count = fwrite(&p,sizeof(struct product),1,fp);  // 5
           if (count == 1)
              printf("\nSuccessfully updated price!\n");
           else
              printf("\nSorry! Could not update price!\n");
      }
      else
         printf("\nProduct Id Not Found!\n");
      fclose(fp);

}

void delete_product()
{
  FILE * fp,*tp;
  struct product p;
  int id, count, pos=1, found = 0;

      fp = open_file("rb");
      tp = fopen(TEMPFILE,"wb");
      if (tp == NULL)
      {
          printf("Sorry! Could not create target file!");
          return;
      }

      printf("Enter product id to delete : ");
      scanf("%d",&id);

      while(1)
      {
          count = fread(&p,sizeof(struct product),1,fp);
          if (count == 0)  // EOF
            break;

          if (id != pos)  // write except the one to delete
               fwrite(&p,sizeof(struct product),1,tp);
          else
               found = 1;

          pos ++;
      }

      fclose(fp);
      fclose(tp);

      if (found)
      {
         remove(FILENAME);
         rename(TEMPFILE,FILENAME);
         printf("Deleted Product Successfully!");
      }
      else
      {
          printf("\nSorry! Couldn't find product id!\n");
      }
}

void search_products()
{
  FILE * fp;
  char name[20], newname[50];
  struct product p;
  int count, found = 0;

      fp = open_file("rb");
      printf("\nSearch Products\n");
      printf("\n================\n");
      printf("Enter product name :");
      scanf("%s",name);

      while(1)
      {
          count = fread(&p,sizeof(struct product),1,fp);
          if (count == 0)  // EOF
            break;
          strcpy(newname,p.name);
          if(strstr(strupr(newname), strupr(name)) != NULL) {
              printf("%-50s  %10d  %4d\n", p.name, p.price, p.qoh);
              found = 1;
          }
      }
      fclose(fp);

      if (!found)
         printf("\nSorry! No product found!\n");
}


main()
{
    int choice;

    while(1)
    {
        printf("\nMenu");
        printf("\n====\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Product details\n");
        printf("4. Update product\n");
        printf("5. Delete product\n");
        printf("6. Search products\n");
        printf("7. Exit\n");
        printf("Enter your choice [1-7]:");
        scanf("%d",&choice);
        printf("\n");

        switch(choice)
        {
            case 1 : add_product(); break;
            case 2 : list_products(); break;
            case 3 : get_product_details(); break;
            case 4 : update_product_price(); break;
            case 5 : delete_product(); break;
            case 6 : search_products(); break;
            case 7 : exit(0);
        }
    }

}
