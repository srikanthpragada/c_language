// Encrypt source file and write to target file
#include <stdio.h>
main(int argc, char * argv[])
{
  FILE * sfp, * tfp;
  int ch;

     if (argc < 3)
     {
         printf("\nUsage : encrypt <sourcefile> <targetfile>\n");
         printf("\nEncrypts given sourcefile and writes encrypted contents to target file\n");
         printf("\n<sourcefile> : is source file to be encrypted");
         printf("\n<targetfile> : is file into which encrypted content to be written\n");
         exit(1);
     }

     sfp = fopen(argv[1],"rt");  // create file
     if (sfp == NULL)
     {
        printf("Sorry! Could not open file -> %s\n",argv[1]);
        exit(2);
     }

     tfp = fopen(argv[2],"wt");  // create file
     if (tfp == NULL)
     {
        printf("Sorry! Could not create file  -> %s",argv[2]);
        exit(3);
     }

     while(1)
     {
       ch = fgetc(sfp);
       if(ch == EOF)
          break;
       fputc(ch+1,tfp);
     }

     fclose(sfp);
     fclose(tfp);
}

