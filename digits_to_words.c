/* print words of digits in a number using recursion, string array and reverse number algorithms */

char words[10][10]=
{ "Zero","One","Two","Three","Four",
  "Five","Six","Seven","Eight","Nine"};

main()
{
   print(695);
   putchar('\n');
   print3(695);
   putchar('\n');
   print3(695);
}

void print(int n)
{
  if ( n > 0)
  {
     print( n / 10);
     printf("%s ", words[n % 10]);

  }
}

void print2(int n)
{
  char w[10][10];
  int pos=0;

  while (n)
  {
    strcpy(w[pos],words[ n % 10]);
    pos ++;
    n /=10;
  }

  for(pos --; pos>=0;  pos --)
    printf("%s ", w[pos]);
}

// reverse number first and then print words
void print3(int n)
{
  int rn=0;
  // reverse number
  while (n)
  {
      rn = rn * 10 + n % 10;
      n/=10;
  };

  // print words for digits in reverse number
  while (rn)
  {
    printf("%s ", words[ rn % 10]);
    rn /=10;
  }
}
