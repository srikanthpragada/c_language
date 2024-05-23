#include <stdio.h>

struct book
{
  char title[50], author[30];
};

struct node
{
  struct book book;
  struct node * next;
};


main()
{
  struct node * root = NULL, * current, * prev;
  struct book book;
  FILE * fp;
  int bookno,pos, count;


  printf("\nEnter book number to delete :");
  scanf("%d",&bookno);

  fp = fopen("books.dat", "rb");
  pos= 0;
  while(1)
  {
     count =  fread(&book,sizeof(book),1,fp); // read a book
     pos++;
     if(count == 0)
        break;

     if(bookno == pos)
          continue;  // ignore book to be deleted

     current = (struct node *) malloc( sizeof(struct node));
     current->next = NULL;
     current->book = book;

     if (root == NULL)
        root  = current;
     else
        prev->next = current;

     prev  = current;
  }
  fclose(fp);

  // reopen file for writing

  fp = fopen("books.dat", "wb");

  current  = root;
  while(current != NULL)
  {
      printf("%-30s %-20s\n", current->book.title, current->book.author);
      fwrite(&(current->book),sizeof(struct book),1,fp);
      current = current->next;
  }
  fclose(fp);
}
