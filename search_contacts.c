// Search for contacts by take name on command line
// Uses file contacts.dat in current directory

# include <stdio.h>

struct contact
{
   char name[30];
   char email[50];
   char mobile[15];
};

main(int argc, char * argv[])
{
   FILE * fp;
   struct contact c;
   int count;

      if(argc < 2)
      {
          printf("Usage: search_contacts  <name>\n");
          return;
      }

      fp = fopen("contacts.dat","rb");
      if (fp == NULL)
      {
          printf("Sorry! File cannot be opened!");
          return;
      }

      while(1)
      {
        count = fread(&c,sizeof(c),1,fp);
        if (count == 0)
            break;

        if (strstr(c.name, argv[1]) != NULL)
           printf("%-20s %-30s  %s\n",c.name,c.email,c.mobile);
      }

      fclose(fp);
}
