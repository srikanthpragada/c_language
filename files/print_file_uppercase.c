#include <stdio.h>
main()
{
    char  name[50];
    int ch;
    FILE * fp;

    printf("Enter filename :");
    gets(name);
    fp = fopen(name,"r");
    if (fp == NULL)
    {
        printf("Sorry! File not found!\n");
        exit(1);
    }
    ch = fgetc(fp);
    while ( ch!= -1) {
        putchar( toupper(ch));
        ch = fgetc(fp);
    }
    fclose(fp);
}
