/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 4 - Bits and Files  
 * 
 * This program causes a "source file" containing a greenscreen image to be layered
 * on top of a "destination" file. First each file is loaded into a bitmap struct
 * and pointers are created to point to the bitmap's pixel data. A loop then checks every
 * pixel in the source file. If the pixel is not completely green, the pixel in the same spot
 * in the destination file is turned black. A second loop then runs and replaces each black pixel
 * in the destination file with the corresponding pixel from the source (with the source being tested
 * even further for green-ness to reduce a green outline.) The destination bitmap is then saved into
 * a new file.
 */

#include "bitmap.h"

int main(int argc, char *argv[])
{
    
    BITMAP* destination_bmp = NULL;
    BITMAP* source_bmp = NULL;
    char* first_file_name;
    char* second_file_name;
    char* out_file_name;
    
    //added if's to use command line input
    if (argc == 4)
    {
        first_file_name = argv[1];
        second_file_name = argv[2];
        out_file_name = argv[3];
    }
    else
    {
        puts("Enter name of destination file: ");
        scanf("%s", first_file_name);
        puts("Enter name of source file: ");
        scanf("%s", second_file_name);
        puts("Enter name of out file: ");
        scanf("%s", out_file_name);
    }
        
      
    destination_bmp=read_bitmap(first_file_name);
    source_bmp = read_bitmap(second_file_name);
      
    if(destination_bmp == NULL || source_bmp == NULL)
    {
        puts("ERROR: Loading File");
    }
    else
    {
        BYTE *destination_byte = destination_bmp->data;//get a pointer to the first byte of destination image data
        BYTE *source_byte = source_bmp->data; //get a pointer to the first byte of the source image data
        
        //Bitblipping. Step by three, each pixel = 3 bytes. Iterate while there are still pixels in the source.
        
        //first loop makes a pixel in destination black anywhere the source isn't completely green
        for (int i = 0; i < (source_bmp->info->img_size); i += 3)
        {
            if (source_byte[i+1] < 235)
            {
                destination_byte[i] = 0;
                destination_byte[i+1] = 0;
                destination_byte[i+2] = 0;
            }
        }
        
        //second loop prints the source image anywhere the destination is black.
        //source bytes tested as well to reduce green outline.
        for (int i = 0; i < (source_bmp->info->img_size); i += 3)
        {
            if (destination_byte[i] == 0 &&
                destination_byte[i+1] == 0 &&
                destination_byte[i+2] == 0 &&
                source_byte[i] > 10 &&
                source_byte[i+1] < 225 &&
                source_byte[i+2] > 10)
            {
                destination_byte[i] = source_byte[i];
                destination_byte[i+1] = source_byte[i+1];
                destination_byte[i+2] = source_byte[i+2];
            }
        }
        
        //file writing moved to only happen if file was opened and altered.
        write_bitmap(out_file_name, destination_bmp);
    }
    
    return 0;
}