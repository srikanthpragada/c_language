#include <stdio.h>

struct student
{
  char name[30];
  int marks;
};

void add_student(FILE * fp)
{
 struct student s;
 int count;

    printf("\nAdding Student\n");
    fflush(stdin); // clear keyboard buffer
    printf("Enter name :");
    gets(s.name);
    printf("Enter marks:");
    scanf("%d",&s.marks);
    // take file pointer to end of file
    fseek(fp,0,SEEK_END);
    count = fwrite(&s,sizeof(s),1,fp);
    if (count == 1)
        printf("\nAdded Student Successfully!\n");
}

void update_student(FILE * fp)
{
 struct student s;
 int count, rollno, marks,pos;

    printf("\nUpdating Marks of Student\n");
    fflush(stdin); // clear keyboard buffer
    printf("Enter rollno   :");
    scanf("%d",&rollno);
    printf("Enter new marks:");
    scanf("%d",&marks);
    pos = (rollno - 1) * sizeof(s);

    // take file pointer to starting of the record
    fseek(fp,pos,SEEK_SET);
    // read current record
    count = fread(&s,sizeof(s),1,fp);
    // modify marks
    s.marks = marks;
    // write record back to same position
    fseek(fp,pos,SEEK_SET);
    count = fwrite(&s,sizeof(s),1,fp);
    if (count == 1)
    {
        printf("\nUpdated Student Successfully!\n");
        fflush(fp); // send changes to file
    }
    else
        printf("\nSorry! Could not update student!\n");
}


void list_students(FILE *fp)
{
  struct student s;
  int count;
     // move file pointer to beginning
     fseek(fp,0,SEEK_SET);
     printf("\nStudents List\n");

     while(1)
     {
         count = fread(&s,sizeof(s),1,fp);
         if (count == 0)
            break;

         printf("%-30s  %3d\n",s.name,s.marks);
     }
}

main()
{
  int choice;
  FILE *fp;

    fp = fopen("students.dat","r+b");
    if (fp == NULL)
    {
        // create file
        fp = fopen("students.dat","w+b");
        if (fp == NULL)
        {
           printf("Sorry! File students.dat cannot be created!");
           exit(1);
        }
    }

    while(1)
    {
       printf("\nMenu\n");
       printf("====\n");
       printf("1. Add\n");
       printf("2. List\n");
       printf("3. Update\n");
       printf("4. Exit\n");
       printf("Choice :");
       scanf("%d",&choice);
       switch(choice)
       {
          case 1 : add_student(fp);
                   break;
                   
          case 2 : list_students(fp);
                   break;
                   
          case 3 : update_student(fp);
                   break;
          case 4 : exit(0);
          
          default: printf("\nSorry! Invalid option. Try again!\n");
       }
    }
}
