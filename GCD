// GCD  Version 1

main()
{
  int n1,n2,i, small;

   printf("Enter two numbers :");
   scanf("%d%d",&n1,&n2);

   if (n1 % n2 == 0)
      printf("%d", n2);
   else
     if(n2 % n1 == 0)
       printf("%d",n1);
     else
     {
        small = n1 < n2 ? n1 : n2;
        for (i = small/2; i >=1 ; i --)
        {
            if ( n1 % i == 0 && n2 % i == 0)
            {
               printf("%d",i);
               break;
            }
        }
     }
}

GCD Version 2
=============
main()
{
  int n1,n2,i, small;

   printf("Enter two numbers :");
   scanf("%d%d",&n1,&n2);

   small = n1 < n2 ? n1 : n2;
   for (i = small; i >=1 ; i --)
   {
         if ( n1 % i == 0 && n2 % i == 0)
         {
            printf("%d",i);
            break;
         } // if
   } // for

} // main

