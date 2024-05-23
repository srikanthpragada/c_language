// Program to search for a product by product id 
struct product
{
  int id;
  char name[30];
  int price;
};

main()
{   int i, prodid, found;
    // create an array and initialize element with data
    struct product prods[5] =
      {
          {
              101, "iPhone7 plus",60000
          },
          {
              102, "iPhone X",80000
          },
          {
              106, "Google Pixel",50000
          },
          {
              108, "Dell Laptop",55000
          },
          {
              110, "Bose Headphones",25000
          }
      };

    // Print details 
    for(i=0; i < 5; i ++)
        printf("%5d %-30s %6d\n", prods[i].id, prods[i].name, prods[i].price);

    while(1)
    {
      printf("\nEnter product id [0 to stop] : ");
      scanf("%d",&prodid);
      if ( prodid == 0)
         break;

      found = 0;
      for(i=0; i < 5; i ++)
      {
        if (prods[i].id == prodid)
        {
            printf("\n%5d %-30s %6d\n", prods[i].id, prods[i].name, prods[i].price);
            found = 1;
            break;
        }
      } // for

      if(!found)
         printf("\nSorry! Product Not Found!\n");
    } // while
}
