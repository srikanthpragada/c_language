// Remove blank lines

#include <stdio.h>

main(int argc, char * argv[])
{
  char line[100], *p;
  FILE * sfp, *tfp;

   // check whether required arguments are provided
   if (argc < 3)
   {
       printf("Usage : rbl <sourcefile> <targetfile>\n");
       exit(1);
   }

   sfp = fopen(argv[1],"r");
   if ( sfp == NULL)
   {
      printf("Source File [%s] Could Not Be Opened!\n",argv[1]);
      exit(1);
   }

   tfp = fopen(argv[2],"w");
   if ( tfp == NULL)
   {
      printf("Target File [%s] Could Not Be Created!\n", argv[2]);
      exit(1);
   }


   while(1)
   {
      p = fgets(line,100,sfp);
      if (p == NULL)
         break;
      // length includes newline. So ignore lines with only 1 char
      if (strlen(line) > 1)
         fputs(line,tfp);
   }

   fclose(sfp);
   fclose(tfp);

} // main()
