// Manage Students in students.dat using Binary file concept and Linked List

#define FILENAME  "students.dat"
#include <stdio.h>

struct student
{
   char name [30];
   int marks;
};

struct node
{
    struct student data;
    struct node * next;
};

void add_student()
{
  FILE * fp;
  struct student stud;

       fp = fopen(FILENAME, "ab"); // Append and Binary

       fflush(stdin);
       printf("Enter student name  : ");
       gets(stud.name);

       printf("Enter student marks : ");
       scanf("%d",&stud.marks);

       fwrite(&stud,sizeof(struct student),1,fp); // Write to file

       fclose(fp);
       printf("\nSuccessfully added new student with %d bytes!\n", sizeof(struct student));
}

// Take student number and new marks and update
void update_student()
{
  FILE * fp;
  struct student stud;
  int pos;

       fp = fopen(FILENAME, "r+b"); // Read-Write and Binary

       fflush(stdin);
       printf("Enter student number  : ");
       scanf("%d",&pos);

       // Move to required position
       fseek(fp, (pos-1) * sizeof(struct student), SEEK_SET);
       fread(&stud,sizeof(struct student),1,fp);  // read record from file


       printf("Enter student marks   : ");
       scanf("%d",&stud.marks);

       // Write back to file after moving to same record
       fseek(fp, (pos-1) * sizeof(struct student), SEEK_SET);
       fwrite(&stud,sizeof(struct student),1,fp); // Write to file

       fclose(fp);
       printf("\nSuccessfully updated marks!\n");
}



void list_students()
{
  FILE * fp;
  struct student stud;
  int count,pos;

       fp = fopen(FILENAME, "rb"); // Read and Binary

       printf("\n*** List of Students ***\n");
       pos = 1;
       while(1)
       {
         count = fread(&stud,sizeof(struct student),1,fp); // read from file
         if(count == 0)   // EOF
            break;
         printf("\n%3d %-20s  %3d",pos, stud.name, stud.marks);
         pos ++;
       }
       fclose(fp);
       printf("\n\n");
}

void delete_student()
{
  FILE * fp;
  struct student stud;
  struct node * root = NULL, *current, * prev;
  int pos, delpos,count;

       fp = fopen(FILENAME, "rb"); // Read and Binary
       printf("Enter student number :");
       scanf("%d",&delpos);

       pos = 1;
       while(1)
       {
         count = fread(&stud,sizeof(struct student),1,fp); // read from file
         if(count == 0)   // EOF
            break;

         // Ignore student to be deleted
         if (pos != delpos)
         {
           // Create a node
           current = (struct node *) malloc(sizeof(struct node));
           current->next = NULL;
           current->data = stud;
           if(root == NULL)  // first node
             root = current;
           else
             prev->next = current;

           prev = current;
         }
         pos++;
       }
       fclose(fp);

       // Write list back to file
       fp = fopen(FILENAME, "wb");
       current = root;
       while(current != NULL)
       {
           fwrite(&current->data, sizeof(current->data),1,fp);
           current = current -> next;
       }
       fclose(fp);
       printf("\nDeleted Student Successfully!\n\n");
}

main()
{
  int choice;

    while(1)
    {
        printf("\n*** Menu ***");
        printf("\n1. Add Student");
        printf("\n2. List Students");
        printf("\n3. Update Student");
        printf("\n4. Delete Student");
        printf("\n5. Exit");
        printf("\nChoice [1-5]: ");
        scanf("%d",&choice);

        switch(choice)
        {
           case 1 : add_student();
                    break;
           case 2 : list_students();
                    break;
           case 3 : update_student();
                    break;
           case 4 : delete_student();
                    break;
           case 5 :  exit(0);  // Stop Program
        }
    }
}
