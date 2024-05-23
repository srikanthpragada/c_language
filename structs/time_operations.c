struct time
{
   int h,m,s;
};

struct time read_time(); // declaration

main()
{
    struct time t1 = {1,20,30};
    struct time t2;

    t2 = read_time();

    printf("Result  : %d\n", compare(t1,t2));

    print_time(t1);
}

void print_time(struct time t)
{
    printf("%02d:%02d:%02d", t.h,t.m,t.s);
}

int compare(struct time t1, struct time t2)
{
   return get_total_seconds(t1) - get_total_seconds(t2);
}

int get_total_seconds(struct time t)
{
   return  t.h * 3600 + t.m *60 + t.s;
}

struct time read_time()
{
    struct time t;

      printf("Enter time [hh:mm:ss] : ");
      scanf("%d:%d:%d", &t.h,&t.m, &t.s);
      return t;
}

struct time  next_second(struct time t)
{
   t.s ++;
   if ( t.s == 60)
   {
       t.s = 0;
       t.m ++;
       if ( t.m == 60)
       {
           t.m =0;
           t.h ++;
           if (t.h == 24)
              t.h = 0;
       }
   }

   return t;

}
