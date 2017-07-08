#include <stdio.h>

/*
  sytax : encdec flag  source target

  flag can be -e or -d. -e for encrypt, -d for decrypt

  source  is source file to be converted
  target  is target file where to write

*/

main(int argc, char * argv[])
{
   int opt = 1;  // encryption
   FILE * sfp, * tfp;
   int ch;

   if ( argc < 4)
   {
     printf("\nSyntax : encdec  flag source target\n\n");
     printf("flag         : is either -e for encryption or -d for decryption\n");
     printf("Source file  : is file to be encrypted or decrypted\n");
     printf("Target file  : is file where you write encrypted or decrypted contents\n");
     exit(1);
   }

   if (strcmp(argv[1],"-d") == 0)
       opt = 2; // decrypt
   else
       if (strcmp(argv[1],"-e") != 0)
       {
         printf("\nSorry! Invalid Flag. It must be -e for encrypt, -d for decrypt!\n");
         exit(2);
       }

   // open source file
   sfp = fopen(argv[2],"r");
   if ( sfp == NULL)
   {
         printf("\nSorry! Source file [%s] could not be opened!\n",argv[2]);
         exit(3);

   }

   tfp = fopen(argv[3],"w");
   if ( tfp == NULL)
   {
         printf("\nSorry! Target file [%s] could not be created!\n",argv[3]);
         exit(4);
   }


   while(1)
   {

       ch = fgetc(sfp);
       if ( ch == -1)
          break;
       if ( opt == 1)
          fputc(ch + 1, tfp);
       else
          fputc(ch - 1, tfp);
   }

   fclose(tfp);
   fclose(sfp);

}
