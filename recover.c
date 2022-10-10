#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(int argc, char *argv[])
{
    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // open input file (forensic image)
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    //set outfile pointer to NULL
    FILE *output = NULL;

    //create an array of 512 elements to store 512 bytes from the memory card
    uint8_t buffer[512];

    //count amount of jpeg files found
    int jpeg = 0;

    //string to hold a filename
    char filename[8] = {0};

    //read memory card untill the end of file
    while (fread(buffer, sizeof(uint8_t) * 512, 1, input) == 1)
    {
        //check if jpeg is found
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            //close output if jpeg was found before and written into ###.jpg
            if (output != NULL)
            {
                fclose(output);
            }
            sprintf(filename, "%03d.jpg", jpeg++);

            //open a new output for writing a new found jpeg
            output = fopen(filename, "w");
        }
        //keep writing to jpeg file if new jpeg is not found
        if (output != NULL)
        {
            fwrite(buffer, sizeof(uint8_t) * 512, 1, output);
        }
    }


    // close last opened outptr
    if (output != NULL)
    {
        fclose(output);
    }

    //close input file (forensic image)
    fclose(input);

    return 0;

}