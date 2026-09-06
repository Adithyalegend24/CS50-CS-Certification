#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        return 1;
    }

    uint8_t block[512];
    FILE *output = NULL;
    char filename[8];
    int image_count = 0;
    int started = 0;

    while (fread(block, sizeof(uint8_t), 512, input) == 512)
    {
        int is_jpeg =
            block[0] == 0xff &&
            block[1] == 0xd8 &&
            block[2] == 0xff &&
            (block[3] & 0xf0) == 0xe0;

        if (is_jpeg)
        {
            if (started)
            {
                fclose(output);
            }

            snprintf(filename, sizeof(filename), "%03i.jpg", image_count);
            output = fopen(filename, "w");

            if (output == NULL)
            {
                fclose(input);
                return 1;
            }

            fwrite(block, sizeof(uint8_t), 512, output);
            image_count++;
            started = 1;
        }
        else if (started)
        {
            fwrite(block, sizeof(uint8_t), 512, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);
    return 0;
}
