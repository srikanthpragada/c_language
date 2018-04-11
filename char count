// Counts Alpha, Digits, Whitespaces and others
#include <stdio.h>
main()
{
  FILE * fp;
  int alpha,digits,whitespace, others, ch;
  char filename[50];

      printf("Enter filename :");
      gets(filename);

      fp = fopen(filename,"r");  // open file in write mode
      if(fp == NULL)
      {
          printf("Sorry! Could not open file. Quitting...");
          return;
      }

      alpha = digits = whitespace = others = 0;
      while(1)
      {
          ch = fgetc(fp);
          if (ch == EOF)
            break;

          if(isalpha(ch))
             alpha++;
          else
             if (isdigit(ch))
               digits ++;
             else
              if (isspace(ch))
                whitespace ++;
              else
                others ++;
      }
      fclose(fp);

      printf("\nAlpha       : %d", alpha);
      printf("\nDigits      : %d", digits);
      printf("\nWhitespaces : %d", whitespace);
      printf("\nOthers      : %d", others);


}
