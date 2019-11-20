#include <stdio.h>
#include <ctype.h>
#include "a4.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


double comp_distance(const PIXEL *A, const PIXEL *B, int image_size);
void comp_fitness_population(const PIXEL *image, Individual * individual, int population_size);

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size)
{
  double sum = 0;
  double distance;
  for(int i = 0; i< image_size; i++)
  {
    distance = pow((abs(A[i].r-B[i].r)),2) + pow((abs(A[i].g-B[i].g)),2) + pow((abs(A[i].b-B[i].b)),2);
    //printf("%d  distance:%f\n",i, distance );
    sum += distance;
  }
  sum = sqrt(sum);
  return sum;
}

void comp_fitness_population(const PIXEL *image, Individual * individual, int population_size)
{

  int image_size =  individual[0].image.height * individual[0].image.width;
  for(int i = 0; i < population_size; i++)
  {
    individual[i].fitness = comp_distance(image, individual[i].image.data ,image_size );
  }

}
