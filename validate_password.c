// password check

main()
{
   char ch;
   int i,digits, upper,special;

   digits = upper = special = 0;

   printf("Enter your password :");

   for(i=1; i <= 6; i ++)
   {
       ch = getch();
       putch('.');
       if (isupper(ch))
            upper++;
       else
         if ( isdigit(ch))
            digits ++;
         else
             if(ch == '_' || ch == '-' || ch == '*' || ch == '#')
                special ++;
   }

   if (upper == 0)
        printf("\nUpper case letter is missing!");

   if (digits == 0)
        printf("\nDigit is missing!");

   if (special == 0)
        printf("\nSpecial char #,_, _ ,* is missing!");

   if (upper>0 && digits> 0 && special > 0)
        printf("\nValid password!");

}
