#include <stdio.h>

struct student
{
    char name[20];
    int marks;
};

void print_students(struct student s[])
{  int i;

    for(i=0; i < 10; i ++)
    {
        printf("\n%-10s %3d", s[i].name, s[i].marks);
    }
}

main()
{
    struct student studs[10];
    struct student temp;
    int i,j;

    srand(time(NULL));
    // load data into array

    for(i=0; i < 10; i ++)
    {
        sprintf(studs[i].name,"Name%d",i + 1);
        studs[i].marks =  rand() % 100;
    }
    printf("\nOriginal List\n");
    print_students(studs);

    // sort array of struct student
    for(i=0; i < 9; i ++)
    {
      for(j = i + 1; j < 10; j ++)
      {
          if (studs[i].marks > studs[j].marks)
          {
              temp = studs[i];
              studs[i] = studs[j];
              studs[j] = temp;
          }
      }
    }

    printf("\n\nSorted List\n");

    print_students(studs);
}
