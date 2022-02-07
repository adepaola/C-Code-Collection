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

#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h> //for datatypes wit specific widths (uint8_t, uint16_t...)
//---------TYPEDEF-----------

typedef struct header HEADER; //bitmap file header
typedef struct info INFO; //bitmap image info header

typedef struct bitmap BITMAP;
typedef uint8_t BYTE; //one byte
typedef uint16_t WORD; //two bytes
typedef uint32_t DWORD; //four bytes

//-------END TYPEDEF---------

//--------STRUCTURES--------

struct bitmap
{
  HEADER* header; //bitmap file header
  INFO* info; //bitmap image info header
  BYTE* extra; //color table, padding, etc
  BYTE* data; //image data
};

#pragma pack(push, 1)
struct header //14 bytes - info aabout the file
{
  WORD signature; //BM for bitmap
  DWORD file_size; //Size of the entire BMP file
  WORD reserved1;  //reserved; must be 0
  WORD reserved2;  //reserved; must be 0
  DWORD offset; //the location of the image data
};
#pragma pack(pop)

#pragma pack(push, 1)
struct info //40 bytes - info about the image
{
  DWORD struct_size; //size of this struct - 40 bytes
  DWORD width;//width of the image
  DWORD height;//height of the image
  WORD planes;//layers in image
  WORD bitcount;//number of bits per pixel
  DWORD compression;///spcifies the type of compression
  DWORD img_size;  //size of image in bytes
  DWORD x_pixels_meter; //number of pixels per meter in x axis
  DWORD y_pixels_meter; //number of pixels per meter in y axis
  DWORD colors_used; //number of colors used in the bitmap
  DWORD important_colors; //number of important colors

};
#pragma pack(pop)
//-------END STRUCTURES-----

//-------PROTOTYPES----

BITMAP* read_bitmap(char* file);

void write_bitmap(char* file, BITMAP* bitmap);

float color_dif(BYTE r1, BYTE g1, BYTE b1, BYTE r2, BYTE g2,BYTE b2);

//----END PROTOTYPES---

#endif
