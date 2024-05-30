#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // Create a buffer for a block of data
    BYTE buffer[512];

    // Set outfile pointer to NULL
    FILE *outptr = NULL;

    // Count amount of JPEG files
    int count = 0;

    char filename[8] = {0};

    // While there's still data left to read from the memory card
    while (fread(buffer, sizeof(BYTE), 1, inptr) == 1)
    {
        // Search 0xff 0xd8 0xff
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            sprintf(filename, "%03i.jpg", count++);

            outptr = fopen(filename, "w");
        }
        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    fclose(inptr);

    return 0;
}
