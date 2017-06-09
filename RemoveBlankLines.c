// Remove blank lines

#include <stdio.h>

main()
{
  char sfile[100], tfile[100], line[100], *p;
  FILE * sfp, *tfp;


   printf("Enter source file : ");
   gets(sfile);

   printf("Enter target file : ");
   gets(tfile);

   sfp = fopen(sfile,"r");
   if ( sfp == NULL)
   {
      printf("Source File [%s] Could Not Be Opened!\n", sfile);
      exit(1);
   }

   tfp = fopen(tfile,"w");
   if ( tfp == NULL)
   {
      printf("Target File [%s] Could Not Be Created!\n", tfile);
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
