#include <stdio.h>
#include <ctype.h>
#include "a4.h"
#include <stdlib.h>
#include <string.h>

PPM_IMAGE *read_ppm(const char *file_name);
void write_ppm(const char *file_name, const PPM_IMAGE *image);


PPM_IMAGE *read_ppm(const char *file_name)
{
   char type[10];
   int width, height, maxvalue;

   FILE *fp;
   fp = fopen (file_name, "r");


   fscanf(fp, "%s %d %d %d", type, &width, &height, &maxvalue);

   // printf("Type |%s|\n", type );
   // printf("width |%d|\n", width );
   // printf("height |%d|\n", height );
   // printf("Max_value |%d|\n", maxvalue );


   int sizeArray = width*height;
   const int N = sizeArray * 3;
   int arr[N];

   for(int i = 0; i < N; i++)
   {
     fscanf(fp,"%d", &arr[i]);
     // printf("%d ", arr[i]);

   }

   PIXEL arrayofPixels[N];

   int j =0;
   for(int i=0;i<sizeArray;i++)
   {
     arrayofPixels[i].r=arr[j];
     arrayofPixels[i].g=arr[j+1];
     arrayofPixels[i].b=arr[j+2];
     // printf("Pixel Number: %d \n",i);
     // printf("Red:%d Green:%d Blue:%d\n", arrayofPixels[i].r,arrayofPixels[i].g,arrayofPixels[i].b);
     j = j+3;
   }
   PPM_IMAGE *temp = malloc(sizeof(PPM_IMAGE));
   temp->data=arrayofPixels;
   temp->width=width;
   temp->height=height;
   temp->max_color=maxvalue;

   // printf("%d %d \n",height, width );
   fclose(fp);
   return temp;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image)
{
  int i;
  FILE *pFile;
  pFile = fopen(file_name, "w");
  int numPixel = (image->width)*(image->height);

  if(pFile != NULL)
  {
    fprintf(pFile, "P3\n");
    fprintf(pFile, "%d %d\n", image->width, image->height);
    fprintf(pFile, "%d\n", image->max_color);
    for(i = 0; i < numPixel; i++)
    {
      fprintf(pFile, "%d %d %d ", image->data[i].r, image->data[i].g, image->data[i].b);
    }
    fclose(pFile);
  }
}
