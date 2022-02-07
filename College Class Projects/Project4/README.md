## README
- Andrew DePaola 
- CIS205 - T8 
- Project 4 - Bits and Files

This file is comprised of three parts. Input for all program should be through the command line.

1) The first part contains two programs which encrypt and decrypt text files with
a bitwise Caesar Cypher. For each program a text file is read in, and their most
(or least for decryption) are moved to the position of the least significant bits 
(most significant to decrypt.)

2) The second part contains two programs to splice and seperate the nybbles of two
text files. The splice program saves the nybbles from the first passed text file
into the output file's most significant bits and the nybbles from the second passed
files into the output file's least significant bits. The seperate program does the
opposite, reconstructing the text from file1 by combining all it's most significant
bits, and the text from file2 by combining it's least significant bits.

3) The third part contains three programs. The first is a program which converts a
bitmap image into grayscale by averaging out the color of each pixel. The second rips
a specified color from the passed bitmap image, outputting a seperate file which 
contains only the specified color in different quantities per pixel. The final program
does my best interpretation of a "bit blit" by overlaying a source image with a greenscreen
onto a background image and saving the result into another output file.

## Compile instructions 

To compile the program type the following in the terminal 

```
make
```
To run the program, type the following in the terminal
```
./main.exe
``` 
Alternatively, the following command can be used to compile and run at the same time
```
make init
```

## Completion Statement

This project was probably the most fun of the entire semester! The hardest part was
definitely wrapping my mind around the manipulation of the bits, but after the first
part it became almost second nature. As far as I can tell I did everything asked 
from this project, however I didn't get the chance to try the photo steganography. I intend 
to do that over the summer, though. Thanks for an incredible first year of college, 
and I'll see you next Spring in CS2!

## Citations

