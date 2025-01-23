#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pointreader.h"

int readPoints(const char* file, point_t** points)
{
    FILE* fp = fopen(file, "r");
    if (!fp)
    {
        return -1; // Fitxategia ezin izan da ireki
    }
    printf("File opened\n");
    size_t capacity = 100; // Hasierako gaitasuna
    *points = (point_t*)malloc(capacity * sizeof(point_t));
    if (!*points)
    {
        fclose(fp);
        return -1; // Memoria esleipena huts egin du
    }
    printf("Memory allocated\n");

    int count = 0;
    while (fscanf(fp, "%lf,%lf,%lf,%lf,%lf,%lf,%lf",
        &(*points)[count].t, &(*points)[count].x, &(*points)[count].y,
        &(*points)[count].v, &(*points)[count].vx, &(*points)[count].vy,
        &(*points)[count].theta) == 7)
    {
        count++;
        if (count >= capacity)
        {
            break; // Stop reading if capacity is reached
        }
    }

    fclose(fp);
    return count; // Irakurritako puntuen kopurua
}

