#include <stdio.h>
#include "a4.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void free_image(PPM_IMAGE *p);
static int compare (const void * a, const void * b)
{
  Individual *IndividualA = (Individual *)a;
  Individual *IndividualB = (Individual *)b;

  int comp = ((IndividualA->fitness) - (IndividualB ->fitness));
  return comp;
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate)
{
  srand(time(0));
  int width = image->width;
  int height = image->height;
  int maxC = image->max_color;
  Individual *pop = generate_population(population_size , width , height , maxC);

  comp_fitness_population(image->data, (pop), population_size);
  qsort (pop, population_size, sizeof(Individual), compare);
  for(int i = 1; i< num_generations;i++)
  {
    crossover(pop, population_size);
    mutate_population(pop, population_size, rate);
    comp_fitness_population(image->data, (pop), population_size);
    qsort (pop, population_size, sizeof(Individual), compare);

  }

  PPM_IMAGE *fittest;
  fittest = malloc(sizeof(PPM_IMAGE));
  fittest = &pop[0].image;
  //printf("fitness:%f \n",pop[0].fitness );
  //printf("fitness:%f \n",pop[1].fitness );
  return fittest;
}

void free_image(PPM_IMAGE *p)
{
   //printf("Freeing Memory \n" );
   free(p);


}
