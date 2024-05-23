#include <stdio.h>

main(int argc, char * argv[])
{
  FILE * sfp, * tfp;
  char ch;


    if (argc < 3)
    {
        printf("Usage : Merge targetfile sourcefile1 [sourcefile2] ...\n");
        exit(0);
    }


    tfp = fopen(argv[1],"w");
    if (tfp == NULL)
    {
        printf("Sorry! [%s] was not create.\n", argv[2]);
        exit(1);
    }

    int i;
    for(i=2; i < argc; i ++)
    {
     // open source file
     sfp = fopen(argv[i],"r");
     if (sfp == NULL)
     {
        printf("\nSorry! [%s] not found.\n", argv[i]);
        continue;
     }
     fprintf(tfp,"\n=======================");
     fprintf(tfp,"\nFile : %s", argv[i]);
     fprintf(tfp,"\n=======================\n");
     while (1)
     {
      ch = fgetc(sfp);
      if (ch == -1)
         break;

      fputc(ch,tfp);
     } // while

     fclose(sfp);

     fputs("\n",tfp); // write blank lines between files
    }

    fclose(tfp);

}
