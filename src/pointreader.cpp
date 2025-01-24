#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pointreader.h"

// readPoints funtzioa definitzen da, fitxategi batetik puntuak irakurtzeko
int readPoints(const char* file, point_t** points)
{
    // Egiaztatu fitxategia existitzen den
    FILE* fp = fopen(file, "r");
    if (!fp)
    {
        // Fitxategia irekitzea huts egiten badu, errore mezua inprimatzen da
        printf("Ezin izan da fitxategia ireki: %s\n", file);
        perror("Errorea");
        return -1; // Fitxategia ezin izan da ireki
    }
    printf("Fitxategia ireki da: %s\n", file);
    // Hasierako edukiera definitzen da
    size_t capacity = 2180; // Hasierako edukiera
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
        // Lerro bakoitza sscanf erabiliz irakurtzen da eta puntuak gordetzen dira
        if (sscanf(line, "%lf %lf %lf %lf %lf %lf %lf",
            &(*points)[count].t, &(*points)[count].x, &(*points)[count].y,
            &(*points)[count].v, &(*points)[count].vx, &(*points)[count].vy,
            &(*points)[count].theta) == 7)
        {
            count++;
            // Edukierra maximoa gainditzen bada, irakurketa gelditzen da
            if (count >= capacity)
            {
                printf("Puntu kopuru maximoa (%zu) gainditu da\n", capacity);
                break; // Irakurketa gelditu edukiera gainditzen bada
            }
        }
    }

    // Puntuak irakurtzea huts egiten badu, errore mezua inprimatzen da
    if (count == 0)
    {
        printf("Ezin izan dira puntuak irakurri fitxategitik\n");
    }

    // Fitxategia ixten da
    fclose(fp);
    return count; // Irakurritako puntuen kopurua itzuli
}


