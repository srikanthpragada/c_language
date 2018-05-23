// Program to concatenate names by separating them with , (comma)
#include <stdio.h>

main()
{
  char names[1000];
  char name[50];

    names[0] = '\0';  // start with empty string
    while(1)
    {
      printf("Enter a name [end to stop] : ");
      gets(name);

      if (strcmp(name,"end") == 0)  // stop if name is "end"
          break;

      if (strlen(names) > 0)
          strcat(names,",");   // add , only for second string onwards

      strcat(names,name);  // add name at the end of names 
    }

    puts(names);
}
