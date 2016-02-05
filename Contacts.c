#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  FILENAME "f:\\c\\dec15\\contacts.txt"

struct contact
{
  char name[30];
  char mobile[30];
  struct contact * next;
};

void split_line(char *line, char * name, char * mobile)
{
    char *p;
    int pos,len;

    p = strchr(line,',');
    pos = p - line;
    // printf("%d",pos);
    strncpy(name,line,pos);
    name[pos] = '\0';
    strcpy(mobile, p+1);

    // remove newline if it is present in mobile
    len = strlen(mobile);
    if (isspace(mobile[len-1])) // if last char is newline
          mobile[len-1]= '\0';
}

// return pointer to the first node
struct contact * load()
{
  struct contact * start = NULL, * current, *prev;
  FILE * fp;
  char line[100], *p;

     fp = fopen(FILENAME,"r");
     if ( fp == NULL)
     {
         printf("Sorry! File could not be opened!");
         exit(1);
     }

     p = fgets(line,100,fp);
     while(p != NULL)
     {
       if ( strlen(line) > 0)
       {
        current = (struct contact *) malloc(sizeof(struct contact));
        split_line(line, current->name,current->mobile);
        current ->next = NULL;

        if (start == NULL)  // first node
            start = current;
        else
            prev ->next = current;

        prev = current;
       }
       p = fgets(line,100,fp);
    } // while
    fclose(fp);
    printf("\nLoaded successfully!\n");
    return start;

}

struct contact * add_contact(struct contact * start)
{
  struct contact *current, *prev, *newnode;
  char name[30],mobile[30];


   newnode = (struct contact *) malloc(sizeof(struct contact));
   printf("Enter name   : ");
   gets(newnode->name);
   printf("Enter mobile : ");
   gets(newnode->mobile);

   newnode ->next = NULL;
   // list is empty
   if (start == NULL)
       return newnode; // this becomes start
   else
   {  // add node at the end of the list
      current = start;
      while(current != NULL)
      {
        prev = current;
        current = current->next;
      }
      prev ->next = newnode;
      return start;
   }

}

struct contact * search_name(struct contact * start, char * name)
{
    while(start != NULL ) {
        if ( strcmpi(start->name,name) == 0)
            return start; // found and return address of the node
        start = start->next;
    }

    return NULL; // not found
};

// inserts a new node after the given name
void insert_contact(struct contact * start)
{
  struct contact *current, *prev, *newnode;
  char name[30],mobile[30];

   printf("Enter name   : ");
   gets(name);

   current = search_name(start,name);
   if (current == NULL)
   {
       printf("\nSorry! Name not found!");
       return;
   }

   newnode = (struct contact *) malloc(sizeof(struct contact));
   printf("Enter Name : ");
   gets(newnode->name);
   printf("Enter mobile : ");
   gets(newnode->mobile);

   newnode ->next = current->next;
   current->next = newnode;
}


struct contact * delete_contact(struct contact * start)
{
  struct contact *current, *prev, *newnode;
  char name[30];

   printf("Enter name   : ");
   gets(name);

   // if first node
   if (strcmpi(start->name, name) == 0)
   {
       current = start;
       start = start->next;
       free(current); // delete node from memory
       return start;
   }

   // delete non-start node
   prev = start;
   current = start->next;
   while(current != NULL)
   {
       if (strcmpi(current->name, name) == 0)
       {
         prev->next = current->next;
         free(current);
         break;
       }
       prev = current;
       current = current->next;
   }
   return start;
}


void  list(struct contact * start)
{
    printf("\nList of Contacts");
    printf("\n==================\n");

    while (start != NULL)
    {
        printf("\n%-30s %-30s", start->name, start->mobile);
        start = start->next;
    }
}

void  search_contacts(struct contact * start)
{
    char name[30];

    printf("Enter search name :");
    gets(name);

    printf("\nList of Contacts");
    printf("\n==================\n");

    while (start != NULL)
    {
      if (strstr(start->name,name)!= NULL)
      {
        printf("\n%-30s %-30s", start->name, start->mobile);
      }
      start = start->next;
    }

}

void  save_contacts(struct contact * start)
{
    FILE * fp;

    fp = fopen(FILENAME,"w");
    if ( fp == NULL)
    {
        printf("\nSorry! File cannot be opened.\n");
        return;
    }

    while (start != NULL)
    {
        fprintf(fp,"%s,%s\n",start->name, start->mobile);
        start = start->next;
    }
    fclose(fp);
    printf("\nSaved contacts successfully!\n");
}

main()
{
    struct contact * start = NULL;
    int ch;

      while(1)
      {

          printf("\nMenu");
          printf("\n======");
          printf("\n1.Load from file");
          printf("\n2.Display Contacts");
          printf("\n3.Add Contact");
          printf("\n4.Delete Contact");
          printf("\n5.Insert Contact");
          printf("\n6.Search Contact");
          printf("\n7.Save Contacts");
          printf("\n8.Exit");
          printf("\nEnter choice [1-8] :");
          ch = getchar();
          fflush(stdin);
          switch(ch)
          {
            case '1' : start = load(); break;
            case '2' : list(start); break;
            case '3' : start = add_contact(start); break;
            case '4' : start = delete_contact(start); break;
            case '5' : insert_contact(start); break;
            case '6' : search_contacts(start); break;
            case '7' : save_contacts(start); break;
            case '8' : exit(0);
          }
      }
}


