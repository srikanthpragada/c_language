
#include <stdio.h>

main()
{
 int choice;

    while(1)
    {
        printf("\nMenu\n");
        printf("=========\n");
        printf("1.Encrypt File\n");
        printf("2.Decrypt File\n");
        printf("3.File stats \n");
        printf("4.Exit\n");
        printf("Your Choice [1-4] :");
        scanf("%d",&choice);

        switch(choice)
        {
         case 1  : encrypt(); break;
         case 2  : decrypt(); break;
         case 3  : file_stats(); break;
         case 4  : exit(0);
        }
    }

}

void encrypt()
{
 char sfilename[50], tfilename[50];
 FILE *sfp,*tfp;
 int ch;

     // clear keyboard buffer
     fflush(stdin);
     printf("\nSource Filename : ");
     gets(sfilename);

     printf("\nTarget Filename : ");
     gets(tfilename);

     sfp = fopen(sfilename,"r");
     if( sfp == NULL)
     {
         printf("\nSorry! Source file not found.\n");
         return;
     }

     tfp = fopen(tfilename,"w");
     if( tfp == NULL)
     {
         printf("\nSorry! Target file could not be opened.\n");
         return;
     }

     ch = fgetc(sfp);
     while ( ch!= -1)
     {
         fputc(ch+1,tfp);
         ch = fgetc(sfp);
     }

     fclose(tfp);
     fclose(sfp);

     printf("\nSuccessfully encrypted %s and copied to %s\n",sfilename, tfilename);

}


void decrypt()
{
 char sfilename[50], tfilename[50];
 FILE *sfp,*tfp;
 int ch;

     // clear keyboard buffer
     fflush(stdin);
     printf("\nSource Filename : ");
     gets(sfilename);

     printf("\nTarget Filename : ");
     gets(tfilename);

     sfp = fopen(sfilename,"r");
     if( sfp == NULL)
     {
         printf("\nSorry! Source file not found.\n");
         return;
     }

     tfp = fopen(tfilename,"w");
     if( tfp == NULL)
     {
         printf("\nSorry! Target file could not be opened.\n");
         return;
     }

     ch = fgetc(sfp);
     while ( ch!= -1)
     {
         fputc(ch-1,tfp);
         ch = fgetc(sfp);
     }

     fclose(tfp);
     fclose(sfp);

     printf("\nSuccessfully decrypted %s and copied to %s\n",sfilename, tfilename);
}

void file_stats()
{
 char filename[50];
 FILE *fp;
 int ch, nolines =0, nowords =0, nochars=0;

     // clear keyboard buffer
     fflush(stdin);
     printf("\nFilename : ");
     gets(filename);

     fp = fopen(filename,"r");
     if(fp == NULL)
     {
         printf("\nSorry! File not found.\n");
         return;
     }


     ch = fgetc(fp);
     while ( ch!= -1)
     {
         nochars++;
         if ( ch == 32){
            nowords ++;
         }
         else
            if ( ch == 10)
            {
               nolines++;
               nowords++;
            }

         ch = fgetc(fp);
     }

     fclose(fp);

     printf("\nNo. of characters : %d\n", nochars);
     printf("\nNo. of words      : %d\n", nowords);
     printf("\nNo. of Lines      : %d\n", nolines);
}
