// Program to print largest word in the given string

#include <stdio.h>

main()
{
  char st[100],w[20],lw[20];
  int i,j;

     printf("Enter a string : ");
     gets(st);
     j=0;
     strcpy(lw,"");
     for(i=0; ;i ++)
     {
       if (isspace(st[i]) || st[i] == 0)   // end of word
       {
            w[j]='\0';
            if ( strcmp(w,lw) > 0)
                 strcpy(lw,w);
            j = 0;
            if(st[i] == 0)
                break;
       }
       else
       {
            w[j] = st[i];
            j++;
       }
     }

     printf("Largest Word : %s",lw);
}
