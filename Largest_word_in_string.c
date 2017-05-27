#include <string.h>

main()
{
   char s[100], w[20], lw[20];
   int i, j=0;


    printf("Enter a string :");
    gets(s);

    strcat(s," ");  // add a space to process last word at the end
    strcpy(lw,"");  // put empty string

    for(i=0; s[i] ; i++)
    {
        if (s[i] == 32)
        {
            w[j] = '\0';  // put null char at the end
            j = 0;
            /*
            // for largest string by length 
            if (strlen(w) > strlen(lw))
                strcpy(lw,w);
            */
            // compare strings by characters 
            if ( strcmp(w,lw) > 0)
                strcpy(lw,w);
        }
        else
        {

            w[j] = s[i];
            j++;
        }
    }
    puts(lw);

}
