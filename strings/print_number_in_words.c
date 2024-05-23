
char * words[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

main()
{
  int num;

     printf("Enter a number :");
     scanf("%d",&num);

     print_in_words(num);
}

void print_in_words(int num)
{
 char digits[10];
 int i;

    itoa(num,digits, 10);  // convert number to string 

    for(i=0; digits[i] ; i ++)
    {
        // get numeric value for each digit as it stored in ascii code 
        printf("%s ", words[digits[i] - 48]);
    }
}

