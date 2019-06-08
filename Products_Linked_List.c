# include <stdio.h>

struct product
{
  char name[20];
  int price;
};

struct node
{
  struct product data;
  struct node * next;
};

main()
{
   struct node * current, * prev, * root = NULL;
   struct product prod;
   int totalprice = 0, prodcount = 0, avgprice;
   int count;
   FILE * fp;

     fp = fopen("products.dat","rb");
     while(1)
     {
        count = fread(&prod,sizeof(prod),1,fp);
        if (count == 0)
          break;

        totalprice += prod.price;
        prodcount ++;
        // create a block of memory for node
        current = (struct node *) malloc(sizeof(struct node));
        current->data = prod;
        current->next = NULL;

        if (root == NULL) // first node
            root = current;
        else
            prev->next = current;

        prev = current;
     }

     fclose(fp);

     // display list

     avgprice = totalprice / prodcount;

     current = root;
     while(current != NULL)
     {
         if(current->data.price > avgprice)
         {
           printf("%s - %d\n", current->data.name, current->data.price);
         }
         current = current ->next;
     }


}
