#include<stdio.h>

struct contact
{
    char name[30];
    char email[50];
    char mobile[25];
};

main()
{
    struct contact c;
    FILE * fp;
    int pos;

    fp = fopen("contacts.dat","r+b");

    if ( fp == NULL)
    {
        printf("Sorry! File cannot be opened!");
        exit(1);
    }

    while(1)
    {
       printf("Enter contact number [1-5 , 0 to stop]:");
       scanf("%d",&pos);
       if ( pos == 0)
          break;
       fseek(fp, (pos-1) * sizeof(struct contact),0);
       fread(&c,sizeof(c),1,fp);
       printf("\n%s %s %s\n", c.name,c.email,c.mobile);
    }

    fclose(fp);
}
