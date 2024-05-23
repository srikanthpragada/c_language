// deletion of an element in an array
main()
{
  int a[10], b[10];
  int i;

  srand(time(0));
  // fill it and display array
  printf("\nBefore Reversing Array \n");
  for(i=0; i < 10; i++)
  {
      a[i] = rand()%100;
      printf("%d\t", a[i]);
  }


  // copy from a to b in reverse
  for(i=0; i < 10;i++)
  {
      b[9-i] = a[i];
  }

  // copy b to a  and print
  printf("\nAfter Reversing Array \n");
  for(i=0; i < 10; i++)
  {
      a[i] = b[i];
      printf("%d\t", a[i]);
  }

}
