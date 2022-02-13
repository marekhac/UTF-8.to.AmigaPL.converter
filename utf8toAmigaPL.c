#include <stdio.h>

#define AMIGAPL_A 194
#define AMIGAPL_C 202
#define AMIGAPL_E 203
#define AMIGAPL_L 206
#define AMIGAPL_N 207
#define AMIGAPL_O 211
#define AMIGAPL_S 212
#define AMIGAPL_X 218
#define AMIGAPL_Z 219
#define AMIGAPL_a 226
#define AMIGAPL_c 234
#define AMIGAPL_e 235
#define AMIGAPL_l 238
#define AMIGAPL_n 239
#define AMIGAPL_o 243
#define AMIGAPL_s 244
#define AMIGAPL_x 250
#define AMIGAPL_z 251

#define AMIGA_DOUBLE_QUOTATION_MARK 0x22

#define UTF8_A 0x84
#define UTF8_C 0x86
#define UTF8_E 0x98
#define UTF8_L 0x81
#define UTF8_N 0x83
#define UTF8_O 0x93
#define UTF8_S 0x9A
#define UTF8_X 0xB9
#define UTF8_Z 0xBB
#define UTF8_a 0x85
#define UTF8_c 0x87
#define UTF8_e 0x99
#define UTF8_l 0x82
#define UTF8_n 0x84
#define UTF8_o 0xB3
#define UTF8_s 0x9B
#define UTF8_x 0xBA
#define UTF8_z 0xBC

#define UTF8_LEFT_DOUBLE_QUOTATION_MARK 0x9C
#define UTF8_RIGHT_DOUBLE_QUOTATION_MARK 0x9E

char* concat(const char *s1, const char *s2);

int main(int argc, char *argv[])
{
    FILE *fileIn = fopen(argv[1], "r");

    if (argc != 2)
    {
        printf("Wrong number of parameters!\n");
        printf("usage: UTF8-txt-input-file\n");
        return 0;
    }

    if (fileIn)
    {
    	char *outputFileName = concat(argv[1], ".apl");
        FILE *fileOut = fopen(outputFileName, "w+");
        if (fileOut)
        {
            int oneChar;
            while (1)
            {
                oneChar = fgetc(fileIn);
                if (feof(fileIn))
                    break;

                switch(oneChar)
                {
                    case 0xC3:
                        oneChar = fgetc(fileIn);
                        if (feof(fileIn))
                            break;
                        switch(oneChar)
                        {
                            case UTF8_O: // Ã
                                fputc(AMIGAPL_O, fileOut);
                                break;
                            case UTF8_o: // Ã³
                                fputc(AMIGAPL_o, fileOut);
                                break;
                        }
                        break;
                    case 0xC4:
                        oneChar = fgetc(fileIn);
                        if (feof(fileIn))
                            break;
                        switch(oneChar)
                        {
                            case UTF8_A: // Ä
                                fputc(AMIGAPL_A, fileOut);
                                break;
                            case UTF8_C: // Ä
                                fputc(AMIGAPL_C, fileOut);
                                break;
                            case UTF8_E: // Ä
                                fputc(AMIGAPL_E, fileOut);
                                break;
                            case UTF8_a: // Ä
                                fputc(AMIGAPL_a, fileOut);
                                break;
                            case UTF8_c: // Ä
                                fputc(AMIGAPL_c, fileOut);
                                break;
                            case UTF8_e: // Ä
                                fputc(AMIGAPL_e, fileOut);
                                break;
                        }
                        break;
                    case 0xC5:
                        oneChar = fgetc(fileIn);
                        if (feof(fileIn))
                            break;
                        switch(oneChar)
                        {
                            case UTF8_L: // Å
                                fputc(AMIGAPL_L, fileOut);
                                break;
                            case UTF8_N: // Å
                                fputc(AMIGAPL_N, fileOut);
                                break;
                            case UTF8_S: // Å
                                fputc(AMIGAPL_S, fileOut);
                                break;
                            case UTF8_Z: // Å»
                                fputc(AMIGAPL_Z, fileOut);
                                break;
                            case UTF8_X: // Å»
                                fputc(AMIGAPL_X, fileOut);
                                break;
                            case UTF8_l: // Å
                                fputc(AMIGAPL_l, fileOut);
                                break;
                            case UTF8_n: // Å
                                fputc(AMIGAPL_n, fileOut);
                                break;
                            case UTF8_s: // Å
                                fputc(AMIGAPL_s, fileOut);
                                break;
                            case UTF8_z: // Å¼
                                fputc(AMIGAPL_z, fileOut);
                                break;
                            case UTF8_x: // Åº
                                fputc(AMIGAPL_x, fileOut);
                                break;
                        }
                        break;
                    case 0xE2:
                        oneChar = fgetc(fileIn);
                        if (feof(fileIn))
                            break;
                        switch(oneChar)
                        {
                            case 0x80:
                                oneChar = fgetc(fileIn);
                                if (feof(fileIn))
                                    break;
                                switch(oneChar)
                                {
                                    case UTF8_LEFT_DOUBLE_QUOTATION_MARK:
                                    case UTF8_RIGHT_DOUBLE_QUOTATION_MARK:
                                        fputc(AMIGA_DOUBLE_QUOTATION_MARK, fileOut);
                                        break;
                                }
                        }
                        break;
                    default:
                        fputc(oneChar, fileOut);
                }

            }
            fclose(fileOut);
        }
        else
        {
            printf("Open file '%s' failed!\n", outputFileName);
        }

        fclose(fileIn);
    }
    else
    {
        printf("Open file '%s' failed!\n", argv[1]);
    }

    return 0;
}

char* concat(const char *string1, const char *string2)
{
    char *result = (char *) malloc(strlen(string1) + strlen(string2) + 1);

    strcpy(result, string1);
    strcat(result, string2);

    return result;
}