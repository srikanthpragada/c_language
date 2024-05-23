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
    int i;

    fp = fopen("contacts.dat","w+b");

    if ( fp == NULL)
    {
        printf("Sorry! File cannot be opened!");
        exit(1);
    }

    for(i=1; i <=5; i ++)
    {
        printf("Enter name, email and mobile :");
        gets(c.name);
        gets(c.email);
        gets(c.mobile);
        fwrite(&c,sizeof(c),1,fp);
    }

    fclose(fp);
}
