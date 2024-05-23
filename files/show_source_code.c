// Displays source code with line numbers for file provided on command line 
#include <stdio.h>

int is_blank_line(char * s)
{
    int i;

    for (i=0; s[i] ; i++)
    {
        if (!isspace(s[i]))
             return 0; // false;
    }

    return 1;  // true
}

main(int argc, char * argv[])
{
    FILE * fp;
    char line[200];
    char * p;
    int lineno=1;

    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("Sorry! [%s] could not be opened!",argv[1]);
        exit(1);
    }
    while(1)
    {
       p = fgets(line,200,fp);
       if ( p == NULL)
         break;

       if( is_blank_line(line) )
         continue;

       printf("%03d : %s",lineno,line);
       lineno ++;
    }

    fclose(fp);
}
