// insertion of an element in an array

main()
{
  int a[10];
  int i,pos,num;

  srand(time(0));
  // fill it and display array
  printf("\nBefore Insertion\n");
  for(i=0; i < 9; i++)
  {
      a[i] = rand()%100;
      printf("%d\t", a[i]);
  }

  printf("\nEnter position :[0-9]");
  scanf("%d",&pos);

  printf("\nEnter number :");
  scanf("%d",&num);

  // insert by pusing elements to right

  for(i=8; i>=pos;i--)
  {
      a[i+1] = a[i];
  }

  a[pos]=num;

  printf("\nAfter Insertion\n");
  for(i=0; i < 10; i++)
  {

      printf("%d\t", a[i]);
  }

}
