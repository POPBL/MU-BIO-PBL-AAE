#include "point.h"
#include <stdlib.h> //  malloc eta free funtzioak erabiltzeko liburutegia.

// freePoints funtzioa definitzen da
void freePoints(point_t** const points) // freePoints funtzioa definitzen du, point_t motako puntuen array bat askatzeko erabiltzen dena.
{
    // Egiaztatzen points eta *points ez direla NULL
    if (points && *points) // Memoria askatu aurretik, points eta *points baliozkoak direla ziurtatzen du, erroreak saihesteko.
    {
        // Memoria askatu
        free(*points); // malloc bidez esleitutako memoria askatzeko erabiltzen da, memoria ihesak (memory leaks) saihesteko.
        // Puntua NULL-ra ezarri
        *points = NULL; // Memoria askatu ondoren, points NULL - ra ezartzeak segurtasuna hobetzen du, askatutako memoria berriro erabiltzea saihestuz.
    }
}