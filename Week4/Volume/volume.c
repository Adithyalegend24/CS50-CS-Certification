// Modifies the volume of a WAV audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define WAV_HEADER_SIZE 44

int main(int argc, char *argv[])
{
    // Validate command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "rb");
    if (infile == NULL)
    {
        printf("Unable to open input file.\n");
        return 1;
    }

    // Open output file
    FILE *outfile = fopen(argv[2], "wb");
    if (outfile == NULL)
    {
        fclose(infile);
        printf("Unable to create output file.\n");
        return 1;
    }

    // Read scaling factor
    float scale = atof(argv[3]);

    // Copy WAV header
    uint8_t wav_header[WAV_HEADER_SIZE];

    fread(wav_header, sizeof(uint8_t), WAV_HEADER_SIZE, infile);
    fwrite(wav_header, sizeof(uint8_t), WAV_HEADER_SIZE, outfile);

    // Process audio samples
    int16_t sample;

    while (fread(&sample, sizeof(int16_t), 1, infile) == 1)
    {
        sample = (int16_t)(sample * scale);
        fwrite(&sample, sizeof(int16_t), 1, outfile);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
