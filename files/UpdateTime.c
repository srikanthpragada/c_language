// Update time (increments time by one second) at the given position
// Uses birnary files, random access and struct time

#include <stdio.h>

struct time {
    int h,m,s;
};

struct time next_second(struct time t)
{
      t.s ++;
      if (t.s > 59)
      {
          t.s = 0;
          t.m ++;
          if (t.m > 59)
          {
              t.m = 0;
              t.h ++;
              if(t.h > 23)
                 t.h = 0;
          }
      }
      return t;
}
main()
{
    FILE * fp;
    struct time t;
    int count;
    int pos, result;
     // make sure you have this file with some data 
     fp = fopen("times.dat","r+b");  
     while(1)
     {
      printf("\nEnter position [0 to stop] : ");
      scanf("%d",&pos);

      if (pos == 0)
         break;

      result = fseek(fp, (pos-1) * sizeof(t),0);  // got to required record
      if (result != 0)
      {
          printf("\nSorry! Position not found!");
          continue;
      }

      count = fread(&t,sizeof(t),1,fp);          // read record
      if (count == 0)
      {
          printf("\nSorry! Could not read record!");
          continue;
      }

      t = next_second(t);                // change time to next second
      fseek(fp, (pos-1) * sizeof(t),0);  // go back to record
      fwrite(&t,sizeof(t),1,fp);         // overwrite record with new time
      printf("\nUpdated Time!");
     }

     fclose(fp);
}
