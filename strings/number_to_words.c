/* print words of digits in a number using recursion */

char words[10][10]=
{ "Zero","One","Two","Three","Four",
  "Five","Six","Seven","Eight","Nine"};

main()
{
   print(6717695);
}

void print(int n)
{
  if ( n > 0)
  {
     print( n / 10);
     printf("%s ", words[n % 10]);

  }

}
