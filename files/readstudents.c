#include <stdio.h>

struct student
{
    char name[30];
    char mobile[11];
};

main()
{
  struct student s;
  int rollno;
  FILE *fp;


  fp = fopen("students.dat","rb");
  if (fp == NULL)
  {
      printf("\nSorry! Could not open file!");
      return;
  }

  while(1)
  {
      printf("\nEnter roll number[0 to stop]:");
      scanf("%d",&rollno);
      if (rollno == 0)
        break;

      fseek(fp,sizeof(s) * (rollno-1),0);

      fread(&s,sizeof(s),1,fp);
      printf("\nName    : %s", s.name);
      printf("\nMobile  : %s\n",s.mobile);

  }

  fclose(fp);
}

