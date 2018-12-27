// Search for string in file using command line arguments
#include <stdio.h>

main(int argc, char * argv[])
{
 char line[100], orgline[100];
 FILE * fp;
 char * cp;
 int lineno;

   if (argc < 3)
   {
       printf("Usage : searchstring filename string");
       return;
   }


   strupr(argv[2]);  // convert search string to upper
   fp = fopen(argv[1],"rt");
   lineno = 1;
   while(1)
   {
       if (fgets(line,100,fp) == NULL)
          break;

       strcpy(orgline,line);  // keep copy of original line

       cp = strstr(strupr(line),argv[2]);
       if(cp != NULL)
            printf("%5d:%s",lineno, orgline);

       lineno ++;
   }

   fclose(fp);
}
