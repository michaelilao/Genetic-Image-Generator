#include <stdio.h>
#include "a4.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void mutate(Individual *individual, double rate)
{
  int counter = rate/100*((individual->image.width)*(individual->image.height));
  int max = (individual->image.width)*(individual->image.height);
  int i, change, change2, change3, index;
  if (rate ==  100)
  {
    for(i = 0; i < max; i++)
    {
      change = rand()%(255 + 1);
      change2 = rand()%(255 + 1);
      change3 = rand()%(255 + 1);
      individual->image.data[i].r = change;
      individual->image.data[i].g = change2;
      individual->image.data[i].b = change3;
    }
  }
  else
  {
    int loopcount = 0;
    const int n = counter;
    int storage[n];
    while (loopcount != counter)
    {
      change = rand()%(255 + 1);
      change2 = rand()%(255 + 1);
      change3 = rand()%(255 + 1);
      jump:
      index = rand()%(max + 1);
      for(i = 0; i < loopcount; i++)
      {
        if (index == storage[i])
        {
          goto jump;
        }
      }
      storage[loopcount] = index;
      individual->image.data[index].r = change;
      individual->image.data[index].g = change2;
      individual->image.data[index].b = change3;
      loopcount++;
    }
    //printf("doneloop");
  }
}

void mutate_population(Individual *individual, int population_size, double rate)
{
  int start = population_size/4;
  int i;
  for(i = start; i < population_size-1; i++)
  {
    mutate((individual + i), rate);
  }
}
