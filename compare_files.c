#include <stdio.h>

main()
{
    FILE *fp1,*fp2;
    char line1[100],line2[100];
    char *cp1,*cp2;
    int res, lineno=0;
    char filename1[100] = "f:\\c\\may6\\names1.txt";
    char filename2[100] = "f:\\c\\may6\\names2.txt";

    // open files
    fp1 = fopen(filename1,"r");
    fp2 = fopen(filename2,"r");

    while(1)
    {
       lineno++;
       cp1 = fgets(line1,100,fp1);
       cp2 = fgets(line2,100,fp2);

       if (cp1 == NULL && cp2 == NULL)
       {
           printf("Equal");
           break;
       }
       if ( cp1 == NULL || cp2 == NULL)
       {
          printf("Files differ in line number [%d]\n", lineno);
          break;
       }

       res = strcmp(line1,line2);

       if ( res != 0)
       {
          printf("Files differ in line number [%d]\n", lineno);
          break;
       }
    }

    fclose(fp1);
    fclose(fp2);

}
