
main() {
  int a[12],i,j,temp;

    srand(time(0));
    printf("\nOriginal Array\n\n");
    for(i = 0; i < 12; i ++)
    {
      a[i] = rand() % 100;
      printf("%d  ", a[i]);
    }

    printf("\n\nPress any key to continue...");
    getch();

    for(i = 0, j = 11; i < 6; i ++, j --)
    {
           temp = a[i];
           a[i] = a[j];
           a[j] = temp;
    }


    printf("\n\nAfter Interchange\n\n");
    for(i = 0; i < 12; i ++)
    {
      printf("%d  ", a[i]);
    }

    printf("\n\nPress any key to continue...");
    getch();
}
