// count no. of occurrences of a string
#include <string.h>
#include <stdio.h>
main()
{
  char line[100], st[20];
  char * p;
  int count = 0;

  printf("Enter a line   :");
  gets(line);

  printf("Enter a string :");
  gets(st);

  p = line;  // start at the beginning of string
  while(1)
  {
     p = strstr(p,st);
     if (p == NULL) // not found
        break;

     count++;
     p++;
  }

  printf("Count = %d",count);

}
