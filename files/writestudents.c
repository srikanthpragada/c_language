#include <stdio.h>

struct student
{
    char name[30];
    char mobile[11];
};

main()
{
  struct student s;
  FILE *fp;


  fp = fopen("students.dat","wb");
  if (fp == NULL)
  {
      printf("\nSorry! Could not create file!");
      return;
  }

  while(1)
  {
      printf("Enter name[end to stop]:");
      gets(s.name);
      if (stricmp(s.name,"end") == 0)
          break;

      printf("Enter mobile number    :");
      gets(s.mobile);

      fwrite(&s,sizeof(s),1,fp);
  }

  fclose(fp);
}

