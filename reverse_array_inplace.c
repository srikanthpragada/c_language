// Reversing array without any temp array using swapping
main()
{
  int a[10];
  int i, temp;

  srand(time(0));
  // fill it and display array
  printf("\nBefore Reversing \n");
  for(i=0; i < 10; i++)
  {
      a[i] = rand()%100;
      printf("%d\t", a[i]);
  }


  // Reverse array by swapping first 5 with last 5 elements
  for(i=0; i < 5 ; i++)
  {
      temp = a[i];
      a[i] = a[9-i];
      a[9-i] = temp;
  }

  printf("\nAfter Reversing\n");
  for(i=0; i < 10; i++)
  {

      printf("%d\t", a[i]);
  }
}
