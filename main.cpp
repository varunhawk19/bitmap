#include <cstdio>
#include<iostream>
#include "bitmap_image.hpp"
using namespace std;
struct col
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
}m;
vector <col> c;
int main()
{
   bitmap_image image("mandelbrot_set.bmp");

   if (!image)
   {
      printf("Error - Failed to open: input.bmp\n");
      return 1;
   }

   unsigned int total_number_of_pixels = 0;

   const unsigned int height = image.height();
   const unsigned int width  = image.width();

   for (std::size_t y = 0; y < height; ++y)
   {
      for (std::size_t x = 0; x < width; x++)
      {
         rgb_t colour;

         image.get_pixel(x, y, colour);
         m.blue=colour.blue;
         m.red=colour.red;
         m.green=colour.green;
         c.push_back(m);

            total_number_of_pixels++;
      }
   }
      bitmap_image cool(width,height);
      cool.clear();
      for(int y = 0; y < height; ++y)
 {     for(int x = 0; x < width; ++x)
            {m=c.at(y*width+x);
            cool.set_pixel(x,y,m.red,m.green,m.blue);
            }
}

cool.save_image("cool.bmp");
   return 0;
}
