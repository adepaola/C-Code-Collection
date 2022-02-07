/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 4 - Bits and Files  
 * 
 * This program reads a file into a bitmap struct and creates a pointer to the bitmap's pixel data.
 * A loop then averages out the colors of each pixel and over-writes each byte of the pixel with
 * the average value. The now overwritten bitmap is then output into another file.
 */

#include "bitmap.h"

int main(int argc, char *argv[])
{
    
    BITMAP* bmp = NULL;
    char* in_file_name;
    char* out_file_name;
    
    //added if's to use command line input
    if (argc == 3)
    {
        in_file_name = argv[1];
        out_file_name = argv[2];
    }
    else
    {
        puts("Enter name of first file: ");
        scanf("%s", in_file_name);
        puts("Enter name of out file: ");
        scanf("%s", out_file_name);
    }
        
      
    bmp=read_bitmap(in_file_name);
      
    if(bmp == NULL)
    {
        puts("ERROR: Loading File");
    }
    else
    {
        BYTE *img_byte = bmp->data; //get a pointer to the first byte of image data
        
        //greyscaling. Step by three, each pixel = 3 bytes.
        for (int i = 0; i < (bmp->info->img_size); i += 3)
        {
            //get the average color of all the colors of the pixel
            BYTE color = ((img_byte[i] + img_byte[i+1] + img_byte[i+2]) / 3);
            
            //then make each color byte the average
            img_byte[i] = color;
            img_byte[i+1] = color;
            img_byte[i+2] = color;
        }
        
        //file writing moved to only happen if file was opened and altered.
        write_bitmap(out_file_name, bmp);
    }
    
    return 0;
}