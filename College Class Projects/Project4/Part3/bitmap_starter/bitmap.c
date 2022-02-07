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
#include "bitmap.h"


//-----FUNCTIONS----

/**
* loads a bitmap file into memory
* arguments: a c string representing a path to the file
* return value: a pointer to a BITMAP struct
***/
BITMAP* read_bitmap(char* file)
{
  BITMAP* bmp = NULL;
  FILE *in_file = NULL;

  int error = 0;

  in_file = fopen(file,"r");

  if(in_file==NULL)
  {
    puts("ERROR: no input file found");
    error = 1;
  }
  else
  {
      //file exists
      //allocate bitmap struct
      bmp =malloc(sizeof(BITMAP));

      //allocate the header struct
      bmp->header = malloc(sizeof(HEADER));
      //read the header into the struct
      fread(bmp->header, sizeof(HEADER), 1, in_file);

      if(bmp->header->signature != 0x4D42)
      {
        puts("ERROR: not bmp file format");
        error=1;
      }
  }

  //File loaded and data is bitmap
  if(error == 0)
  {
    //allocate and read the information header
    bmp->info = malloc(sizeof(INFO));
    fread(bmp->info, sizeof(INFO), 1, in_file);

    //collect everything between the header/infoheader and the img data
    //color table, padding, etc
    size_t size  = bmp->header->offset - (sizeof(HEADER) + sizeof(INFO));
    bmp->extra = malloc(size);
    fread(bmp->extra, size, 1, in_file);

    //allocate and read the actual image data
    bmp->data = malloc(bmp->info->img_size);
    fread(bmp->data, bmp->info->img_size, 1, in_file);
  }
  else
  {
    //something went wrong
    //clean up what has been allocated
    //and set bmp (return value) to NULL
    free(bmp->header);
    free(bmp);
    bmp = NULL;
  }

  //close the file and return bitmap or NULL
  fclose(in_file);
  return bmp;
}


/*
* write a bitmap file into memory
* arguments: a c string representing a path to the file and a bitmap struct
*      a file is created if it does not exist.
* return value: nothing
***/
void write_bitmap(char* file, BITMAP* bmp)
{
  FILE *out_file;
  //if file does not exist, create it
  out_file = fopen(file,"w+");

  //figure out how big the extra struct is
  size_t size  = bmp->header->offset - (sizeof(HEADER) +sizeof(INFO));

  //write all the parts
  fwrite(bmp->header, sizeof(HEADER), 1, out_file);
  fwrite(bmp->info, sizeof(INFO), 1, out_file);
  fwrite(bmp->extra, size, 1, out_file); //math above for this
  fwrite(bmp->data, bmp->info->img_size, 1, out_file);

  //close the file
  fclose(out_file);
}

