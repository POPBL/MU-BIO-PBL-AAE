#include <csv.h>
#include <stdio.h>
#include "point.h"
#include "pointreader.h"
#include "angularvelocitycalculator.h"

// main funtzioa definitzen da
int main(int argc, char** argv)
{
    // Argumentu kopurua egiaztatzen da
    if (argc != 2)
    {
        // Errore mezua pantailaratzen da argumentu kopuru okerra bada
        printf("Programa abiadura angeluar maximoa kalkulatzeko Tracker-ek sortutako koma bereizitako balioen txt fitxategi batetik\n");
        printf("Erabilera: %s <fitxategiaren izena>\n", argv[0]);
        return -1;
    }
    struct point_t* points;

    // Fitxategitik puntuak irakurtzen dira
    int numberOfPoints = readPoints(argv[1], &points);

    // Fitxategia irakurtzean errorea gertatu bada, errore mezua pantailaratzen da
    if (numberOfPoints < 0)
    {
        printf("Errorea fitxategia irakurtzean\n");
        return -1;
    }

    // Abiadura angeluar maximoa inprimatzen da
    float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);

    printf("Abiadura angeluar maximoa: %f rad/s\n", maximumAngularVelocity);

    // Puntuak askatzen dira memoria garbitzeko
    freePoints(&points);
    return 0;
}