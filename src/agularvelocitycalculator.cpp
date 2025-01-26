#include "angularvelocitycalculator.h"
#include <math.h>
#include <stdio.h>

// computeMaximumAngularVelocity funtzioa definitzen da
float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints)
{

    // Puntu kopurua 2 baino gutxiago bada, errore mezua pantailaratzen da eta 0.0 itzuliko da
    if (numberOfPoints < 2)
    {
        printf("Not enough points for angular velocity calculation.\n");
        return 0.0f;
    }

    // Abiadura angeluar maximoa hasieratzen da
    float maxAngularVelocity = 0.0f;

    // Puntuak prozesarzen dira
    for (int i = 1; i < numberOfPoints; i++)
    {
        // Bi puntu arteko angeluar aldaketa kalkulatzen da
        double deltaTheta = points[i].theta - points[i - 1].theta;
        // Bi puntu arteko denbora aldaketa kalkulatzen da
        double deltaT = points[i].t - points[i - 1].t;


        // Egiaztatu deltaT nahikoa handi den erroreak saihesteko
        if (fabs(deltaT) > 1e-6)
        {
            // Abiadura angeluarra kalkulatzen da
            float angularVelocity = fabs(deltaTheta / deltaT);

            // Abiadura angeluar maximoa baino handiagoa bada, maximoa eguneratzen
            if (angularVelocity > maxAngularVelocity)
            {
                maxAngularVelocity = angularVelocity;
            }
        }
        else
        {
            // DeltaT txikia edo zero bada, errore mezua inprimatzen da eta puntua saltazen da
            printf("Skipped point %d due to small or zero deltaT.\n", i);
        }
    }

    // Abiadura angeluar maximoa itzultzen da
    return maxAngularVelocity;
}