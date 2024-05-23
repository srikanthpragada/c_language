// deletion of an element in an array
main()
{
  int a[10];
  int i,pos;

  srand(time(0));
  // fill it and display array
  printf("\nBefore deletion\n");
  for(i=0; i < 10; i++)
  {
      a[i] = rand()%100;
      printf("%d\t", a[i]);
  }
  printf("\nEnter position [0-9] : ");
  scanf("%d",&pos);

  // delete by pusing elements to right
  for(i=pos; i < 9;i++)
  {
      a[i] = a[i+1];
  }

  a[9]=0;

  printf("\nAfter deletion\n");
  for(i=0; i < 10; i++)
  {

      printf("%d\t", a[i]);
  }

}
