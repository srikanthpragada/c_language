#include <stdio.h>

main()
{
FILE * fp;
int ch,lines,i;
char line[5];
int * p;

  // count number of lines in marks.txt
  fp =  fopen("f:\\c\\feb9\\marks.txt","r");

  if ( fp == NULL)
  {
     printf("Sorry! File not found!");
     return;
  }

  lines = number_of_lines(fp);
  // allocate memory
  p = (int*) malloc(sizeof(int)*lines);

  load_file(fp,p);

  sort_numbers(p,lines);

  // print numbers after sorting
  for(i=0; i < lines; i++)
  {
    printf("\n%d", p[i]);
  }

  fclose(fp);
}

void sort_numbers(int * a, int size)
{
    int i,j,temp;

    for(i=0; i < size-1; i++)
    {
        for (j=i+1; j < size; j++)
        {
            if ( a[i] > a[j])
            {
                temp = a[i];
                a[i]  = a[j];
                a[j] = temp;
            }
        }
    }
}

int  number_of_lines(FILE *fp)
{
  int lines = 0;
  char line[5];
  do
  {
    if(fgets(line,5,fp) == NULL)
           break;
    remove_newline(line);
    if(strlen(line)>0)
       lines ++;
  }
  while(1);

  return lines;
}

int  load_file(FILE *fp, int * p)
{
  int  pos = 0;
  char line[5];
  fseek(fp,0,0);
  do
  {
    if(fgets(line,5,fp) == NULL)
           break;
    remove_newline(line);

    if(strlen(line)>0)
    {
       p[pos] = atoi(line); // convert string to int
       pos++;
    }
  }
  while(1);
}

void  remove_newline(char *s)
{
    int i =0;

    while(s[i])
    {
      if(!isdigit(s[i]))
      {
          s[i] = '\0';
          break;
      }
      i++;
    }
}
