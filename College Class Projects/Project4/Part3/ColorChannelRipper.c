/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 4 - Bits and Files  
 * 
 * This file prompts the user for the color they wish to rip from the file. The file
 * is then loaded into a bitmap and a pointer created pointing to the bitmap's pixel data.
 * A loop then iterates over each pixel in the bitmap which contains another loop that changes
 * the the values of the colors not picked by the user to 0. The bitmap (now containing only
 * the color picked by the user) is then written out to a file.
 */

#include "bitmap.h"
enum colors {BLUE=0, GREEN, RED};

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
    
    int choice = 0;
    puts("Rip which color?");
    printf("%d : Blue\n%d : Green\n%d : Red\n", BLUE, GREEN, RED);
    scanf("%d", &choice);
    
    while(choice < 0 || choice > 2)
    {
      puts("INVALID: Enter a valid number");
      scanf("%d", &choice);
    }
    
      
    bmp=read_bitmap(in_file_name);
      
    if(bmp == NULL)
    {
        puts("ERROR: Loading File");
    }
    else
    {
        BYTE *img_byte = bmp->data; //get a pointer to the first byte of image data
        
        //Color channel ripping. Step by three, each pixel = 3 bytes.
        for (int i = 0; i < (bmp->info->img_size); i += 3)
        {
            //set values in the pixel to 0 if they're not the color chosen by the user.
            for(int j = 0; j < 3; j++)
            {
              if (j != choice)
              {
                img_byte[i+j] = 0;
              }
            }
        }
        
        //file writing moved to only happen if file was opened and altered.
        write_bitmap(out_file_name, bmp);
    }
    
    return 0;
}