// Student Marks Manager
# include <stdio.h>
# include <string.h>
# define  FILENAME "marks.dat"

struct student
{
   char name[20];
   int marks;
};

void add_student()
{
  FILE * fp;
  struct student s;

     fp = fopen(FILENAME,"ab");
     if (fp == NULL)
     {
         printf("\nSorry! File cannot be opened!\n");
         return;
     }
     while(1)
     {
       fflush(stdin); // clear keyboard buffer
       printf("Enter Student Name [Enter to stop] :");
       gets(s.name);
       if(strlen(s.name) == 0)  // user wants to stop
            break;
       printf("Enter Marks :");
       scanf("%d",&s.marks);
       fwrite(&s,sizeof(s),1,fp);
     }
     fclose(fp);
}

void list_students()
{
  FILE * fp;
  struct student s;
  int count;

     fp = fopen(FILENAME,"rb");
     if (fp == NULL)
     {
         printf("\nSorry! File cannot be opened!\n");
         return;
     }
     printf("\n\nList Of Students\n");
     printf("=================\n");
     while(1)
     {
       count = fread(&s,sizeof(s),1,fp);
       if (count == 0)
         break;
       printf("%-20s %3d\n",s.name,s.marks);
     }

     fclose(fp);
}

void update_marks()
{
  FILE * fp;
  struct student s;
  int admno,count,pos;

     fp = fopen(FILENAME,"r+b");
     if (fp == NULL)
     {
         printf("\nSorry! File cannot be opened!\n");
         return;
     }
     printf("Enter Admno :");
     scanf("%d",&admno);
     pos = (admno -1) * sizeof(s);
     fseek(fp,pos,SEEK_SET); // move to required record
     count = fread(&s,sizeof(s),1,fp);
     if (count == 1)
     {
       printf("Enter Marks :");
       scanf("%d",&s.marks);
       fseek(fp,pos,SEEK_SET);  // move back to starting of record
       fwrite(&s,sizeof(s),1,fp);
     }
     else
        printf("\nSorry! Student not found!\n");

     fclose(fp);
}


main()
{
  int choice;

     while(1)
     {
         printf("\nStudents Menu\n");
         printf("=============\n");
         printf("1. Add Student\n");
         printf("2. List Students\n");
         printf("3. Update marks\n");
         printf("4. Exit\n");
         printf("\nChoice[1-4]:");
         scanf("%d",&choice);

         switch(choice)
         {
            case 1: add_student();
                    break;
            case 2: list_students();
                    break;
            case 3: update_marks();
                    break;
            case 4: return;
         }
     }
}
