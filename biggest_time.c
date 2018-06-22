struct time
{
   int h,m,s;
};

int  total_seconds(struct time t) {
  return  t.h * 3600 + t.m * 60 + t.s;
}

int  timecompare(struct time t1, struct time t2)
{
    return  total_seconds(t1) - total_seconds(t2);
}

void print_time(struct time t)
{
    printf("%02d:%02d:%02d\n", t.h, t.m, t.s);
}

struct time  max(struct time t1, struct time t2)
{
  return  total_seconds(t1) > total_seconds(t2) ? t1 : t2;
}

main()
{
   int i;
   struct time times[5];
   struct time largest = {0,0,0};

       srand(time(0));
       for(i=0; i < 5; i ++)
       {
          times[i].h = rand() % 24;
          times[i].m = rand() % 60;
          times[i].s = rand() % 60;
          print_time(times[i]);
          if (timecompare(times[i],largest) > 0)
                largest = times[i];
       }

      print_time(largest);
}
