#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pointreader.h"

// CSV goiburua irakurtzen eta balidatzen du
int read_csv_header(FILE* file)
{
    char header[256];
    if (fgets(header, sizeof(header), file))
    {
        // Balidatu goiburua hemen (adibidez, zutabe izenak egiaztatu)
        return 0; // Balidazioa arrakastatsua bada
    }
    return -1; // Balidazioa huts egiten badu
}

// CSV lerro bat parseatzen du
int parse_csv_row(const char* row, point_t* point)
{
    int parsed = sscanf(row, "%lf %lf %lf %lf %lf %lf %lf",
        &point->t, &point->x, &point->y,
        &point->v, &point->vx, &point->vy,
        &point->theta);
    if (parsed != 7)
    {
        printf("Error parsing row: %s\n", row);
        return -1; // Parsing error
    }
    return 0; // Parsing successful
}

// X eta Y koordenatuak ateratzen ditu
void extract_coordinates(const point_t* point, double* x, double* y)
{
    *x = point->x;
    *y = point->y;
}

// Puntuak irakurtzen ditu CSV fitxategitik
int readPoints(const char* file, point_t** points)
{
    FILE* fp = fopen(file, "r");
    if (!fp)
    {
        // Fitxategia irekitzea huts egiten badu, errore mezua inprimatzen da
        printf("Ezin izan da fitxategia ireki: %s\n", file);
        perror("Errorea");
        return -1; // Fitxategia ezin izan da ireki
    }
    printf("Fitxategia ireki da: %s\n", file);
    
    // CSV goiburua irakurtzen eta balidatzen du
    if (read_csv_header(fp) != 0)
    {
        fclose(fp);
        printf("CSV goiburua irakurtzea huts egin du\n");
        return -1;
    }


    // Hasierako edukiera definitzen da
    size_t capacity = 2000; // Hasierako edukiera
    *points = (point_t*)malloc(capacity * sizeof(point_t));
    if (!*points)
    {
        // Memoria esleipena huts egiten badu, fitxategia ixten da eta errore mezua inprimatzen da
        fclose(fp);
        printf("Memoria esleipena huts egin du\n");
        return -1; // Memoria esleipena huts egin du
    }
    printf("Memoria esleitu da\n");

    int count = 0;
    char line[256];
    // Fitxategiko lerroak irakurtzen dira
    while (fgets(line, sizeof(line), fp))
    {
        // Lerro bakoitza parseatzen da eta puntuak gordetzen dira
        if (parse_csv_row(line, &(*points)[count]) == 0)
        {
            count++;
            // Edukiera maximoa gainditzen bada, irakurketa gelditzen da
            if (count >= capacity)
            {
                break; // Irakurketa gelditu edukiera gainditzen bada
            }
        }
        else
        {
            printf("Error reading line: %s\n", line);
        }

    }

    // Puntuak irakurtzea huts egiten badu, errore mezua inprimatzen da
    if (count == 0)
    {
        printf("Ezin izan dira puntuak irakurri fitxategitik\n");
    }

    // Fitxategia ixten da
    fclose(fp);
    return count; // Irakurritako puntuen kopurua
}

