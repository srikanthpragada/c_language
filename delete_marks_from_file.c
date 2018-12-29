// Program to delete marks from marks.txt that are < 60

#include <stdio.h>
#define FILENAME "marks.txt"

main()
{
  FILE * fp;
  char * cp;
  int * p;
  int count, pos,i;
  char line[10];

      fp = fopen(FILENAME,"rt");
      if(fp == NULL)
      {
        printf("Sorry! File cannot be opened!");
        exit(1);
      }
      count = 0;
      while(1)
      {
         cp = fgets(line,10,fp);
         if (cp == NULL)
           break;
         count ++;
      }

      // printf("No. of marks : %d\n",count);

      // take memory to store all marks
      p = (int*) malloc(count * sizeof(int));
      // take file pointer to beginning of file
      fseek(fp,0,SEEK_SET);

      // Read and copy each line into an element of the array
      pos = 0;
      while(1)
      {
         cp = fgets(line,10,fp);
         if (cp == NULL)
           break;
         p[pos] = atoi(line);  // convert string to int
         pos ++;
      }
      fclose(fp);

      // Write marks >= 60 into file
      fp = fopen(FILENAME,"wt");
      for(i = 0; i < count ; i ++)
        if (p[i] >= 60)
            fprintf(fp,"%d\n", p[i]);

      fclose(fp);
}

marks.txt
========
66
90
68
99
88
77
78
85
67
98
33
44
68
91
81
55
77
78
45
85
67
98

marks.txt after program is run
===============================
66
90
68
99
88
77
78
85
67
98
68
91
81
77
78
85
67
98

