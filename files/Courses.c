// Program to manage courses using binary files of C 
// Stores data that is in a struct course into courses.dat file 

#include <stdio.h>

struct course
{
   char name[20];
   int duration, fee;
};

main()
{
 FILE * fp;
 int opt;


     fp =  fopen("e:\\c\\apr27\\courses.dat","r+b");
     if (fp == NULL)
     {
        printf("Sorry! Could not open file!");
        exit(1);
     }

     while(1)
     {
         printf("\n *** Menu ***\n");
         printf("1. Add Course\n");
         printf("2. List Courses\n");
         printf("10. Exit\n");

         scanf("%d",&opt);
         switch(opt)
         {
             case 1 : add_course(fp); break;
             case 2 : list_courses(fp); break;
             case 10 : exit(0);
         }
     }

     fclose(fp);
}

void  add_course(FILE * fp)
{
  struct course c;

     // clear keyboard buffer
     fflush(stdin);
     printf("Enter name     : ");
     gets(c.name);
     printf("Enter duration : ");
     scanf("%d",&c.duration);
     printf("Enter fee      : ");
     scanf("%d",&c.fee);

     // go to end of file and write a new record
     fseek(fp,0, SEEK_END);
     fwrite(&c, sizeof(c), 1, fp);
     printf("Added Course Successfully!");
     getch();
}


void list_courses(FILE *fp)
{
    struct course c;
    int count;

    // go to beginning of file
    fseek(fp,0,SEEK_SET);
    while(1)
    {
        count = fread(&c,sizeof(c),1,fp);
        if (count != 1)
            break;
        printf("%-20s  %3d %5d\n", c.name, c.duration, c.fee);
    }
    getch();  // wait for key

}
