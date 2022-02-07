/*
Michael Penta

This program reads a bitmap file a

The bitmap structure represents the file data. This structure is comprised
of a file header, a bitmap info header, a color table and padding,
and lastly image data.

the read_bitmap function will load a bitmap into these
structures and return a bitmap structure.

once a bitmap structure is constructed it can be write to a file using the
write_bitmap function

use the included make file to build your project

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bitmap.h"

int main(int argc, char** argv)
{

  BITMAP* bmp = NULL;
  char* in_file_name = "underwater.bmp";
  char* out_file_name = "out.bmp";
  
  bmp=read_bitmap(in_file_name);

  
  if(bmp == NULL)
  {
    puts("ERROR: Loading File");
  }
  else
  {
    //things look ok
    //Do stuff
    //PRINT some bitmap info
    puts("--------------");
    puts("BITMAP INFO");
    puts("--------------");
    printf("BitCount:\t%d\n",bmp->info->bitcount);
    printf("Image Size:\t%.2fMB\n",bmp->info->img_size/1000000.0);//B to MB
    printf("Image Width:\t%d\n",bmp->info->width);
    printf("Image Height:\t%d\n",bmp->info->height);
    printf("Image offset:\t%d\n",bmp->header->offset);
    puts("--------------");
    
    BYTE *img_byte = bmp->data; //get a pointer to the first byte of image data
    

  }

	//write_bitmap(out_file_name, bmp);
  
  return 0;
}