#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define FILENAME  "contacts.dat"

struct contact {
   char name[30];
   char email[50];
   char mobile[11];
};

void add_contact();
void get_contact();
void list_contacts();
void search_contacts();

void main()
{
int opt;

    while(1)
    {
        printf("\n***** MENU ******\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Get Contact\n");
        printf("4. Search Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice [1-5] :");\
        scanf("%d",&opt);

        switch(opt)
        {
           case 1: add_contact(); break;
           case 2: list_contacts(); break;
           case 3: get_contact(); break;
           case 4: search_contacts(); break;
           case 5: exit(0);
        } // switch
    } // while
} // main()


void add_contact()
{
    FILE * fp;
    struct contact c;

       fp = fopen(FILENAME,"ab");
       if (fp==NULL)
       {
           printf("Sorry! File could not be opened!");
           exit(0);
       }

       fflush(stdin); // clear keyboard buffer
       printf("Enter name   : ");
       gets(c.name);
       printf("Enter email  : ");
       gets(c.email);
       printf("Enter mobile : ");
       gets(c.mobile);
       fwrite(&c,sizeof(c),1,fp);
       printf("\nContact Saved Successfully!\n");
       fclose(fp);

       printf("\nPress a key to continue...\n");
       getch();
}

void list_contacts()
{
    FILE * fp;
    struct contact c;
    int count;

       fp = fopen(FILENAME,"rb");
       if (fp==NULL)
       {
           printf("Sorry! File could not be opened!");
           exit(0);
       }
       printf("\nList of Contacts\n");
       printf("\n================\n");

       while(1)
       {
         count = fread(&c,sizeof(c),1,fp);
         if (count == 0)
            break;
         printf("%-20s %-30s %s\n", c.name,c.email,c.mobile);
       }

       fclose(fp);
       printf("\nPress a key to continue...\n");
       getch();

}

void get_contact()
{
    FILE * fp;
    struct contact c;
    int id,count;

       fp = fopen(FILENAME,"rb");
       if (fp==NULL)
       {
           printf("Sorry! File could not be opened!");
           exit(0);
       }

       printf("Enter contact id : ");\
       scanf("%d",&id);
       fseek(fp, (id-1) * sizeof(c), SEEK_SET);
       count = fread(&c,sizeof(c),1,fp);
       if (count == 0)
            printf("Sorry! Could not read contact details!");
       else
            printf("%-20s %-30s %s\n", c.name,c.email,c.mobile);

       fclose(fp);
       printf("\nPress a key to continue...\n");
       getch();
}


void search_contacts()
{
    FILE * fp;
    struct contact c;
    char name[30];
    int count;

       fp = fopen(FILENAME,"rb");
       if (fp==NULL)
       {
           printf("Sorry! File could not be opened!");
           exit(0);
       }

       fflush(stdin);
       printf("Enter contact name to search : ");
       gets(name);

       while(1)
       {
         count = fread(&c,sizeof(c),1,fp);
         if (count == 0)
            break;

         if(strstr(c.name, name) != NULL)
            printf("%-20s %-30s %s\n", c.name,c.email,c.mobile);
       }

       fclose(fp);
       printf("\nPress a key to continue...\n");
       getch();
}
