#include <stdio.h>

main()
{
  FILE * sfp, *tfp;
  int ch;
  char  sfn[50], tfn[50];


    printf("Enter source filename : ");
    gets(sfn);

    sfp = fopen(sfn,"r");
    if ( sfp == NULL)
    {
      printf("Sorry! Source file not found!");
      exit(1);
    }


    printf("Enter target filename : ");
    gets(tfn);

    tfp = fopen(tfn,"w");
    if ( tfp == NULL)
    {
      printf("Sorry! Target cannot be created!");
      exit(2);
    }

    while(1)
    {
      ch = fgetc(sfp);
      if (ch == -1)  // EOF 
        break;

      if (! isdigit(ch))
         fputc(ch,tfp);
    }

    fclose(tfp);
    fclose(sfp);
}
