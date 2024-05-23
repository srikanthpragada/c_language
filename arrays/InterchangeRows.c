
main()
{
  int a[6][6];
  int i,j,temp;

      srand(time(0));
      for (i = 0; i < 6; i ++)
      {
         for(j=0; j < 6; j ++)
         {
           a[i][j] = rand() % 100;
           printf("%5d", a[i][j] );
         }
         printf("\n");
      }


      for (i = 0; i < 3; i ++)
      {
         for(j=0; j < 6; j ++)
         {
            temp = a[i][j] ;
            a[i][j] = a[5-i][j];
            a[5-i][j] = temp;
         }
      }

      printf("\nAfter Interchange\n");

      for (i = 0; i < 6; i ++)
      {
         for(j=0; j < 6; j ++)
         {
           printf("%5d", a[i][j] );
         }
         printf("\n");
      }
}
