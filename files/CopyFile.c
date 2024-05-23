#include <stdio.h>

main(int argc, char * argv[])
{
  FILE * sfp, * tfp;
  char ch;


    if (argc < 3)
    {
        printf("Usage : CopyFile sourcefile targetfile\n");
        exit(0);
    }

    sfp = fopen(argv[1],"r");
    if ( sfp == NULL)
    {
        printf("Sorry! [%s] not found.\n", argv[1]);
        exit(1);
    }

    tfp = fopen(argv[2],"w");
    if (tfp == NULL)
    {
        printf("Sorry! [%s] was not create.\n", argv[2]);
        exit(1);
    }

    while (1)
    {
      ch = fgetc(sfp);
      if (ch == -1)
         break;

      fputc(ch,tfp);
    }

    fclose(sfp);
    fclose(tfp);

    printf("Copied [%s] to [%s] successfully!\n", argv[1],argv[2]);


}
