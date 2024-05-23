#include<stdio.h>

struct time
{
  int hours, mins, secs;
};

struct time get_largest_time(struct time []);

main()
{
 struct time times[10];
 struct time largest;
 int i;

 // initialize random seed
 srand(time(NULL));

 // fill array
 for(i=0; i <10 ;i++)
 {
    times[i].hours = rand() % 24;
    times[i].mins = rand() % 60;
    times[i].secs = rand() % 60;
    print_time(times[i]);
 }

 largest = get_largest_time(times);
 printf("\nLargest Time");
 print_time(largest);
}

int  total_seconds(struct time t)
{
    return   t.hours * 3600 + t.mins * 60 + t.secs;
}

void print_time(struct time t)
{
   printf("\n%02d:%02d:%02d",t.hours, t.mins, t.secs);
}

// returns 0  - t1 == t2, > 0  - t1 > t2 , < 0 - t1 < t2

int  compare_times(struct time t1, struct time t2)
{
    return  total_seconds(t1) - total_seconds(t2);
}

struct time  get_largest_time(struct time times[10])
{
    int i;
    struct time largest = times[0];

    for(i=1; i <10; i ++)
    {
        //  check whether element is bigger than largest
        if ( compare_times(times[i], largest) > 0 )
              largest = times[i];
    }

    return largest;
}
