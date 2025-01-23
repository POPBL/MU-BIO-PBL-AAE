#include "angularvelocitycalculator.h"
#include <math.h>
#include <stdio.h>


float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints) {
	
    if (numberOfPoints < 2)
    {
        printf("Not enough points for angular velocity calculation.\n");
        return 0.0f;
    }

    float maxAngularVelocity = 0.0f;

    for (int i = 1; i < numberOfPoints; i++)
    {
        double deltaTheta = points[i].theta - points[i - 1].theta;
        double deltaT = points[i].t - points[i - 1].t;

        printf("Point %d: deltaTheta=%f, deltaT=%f\n", i, deltaTheta, deltaT);

        // Check if deltaT is sufficiently large to avoid errors
        if (fabs(deltaT) > 1e-6)
        {
            float angularVelocity = fabs(deltaTheta / deltaT);
            printf("Computed angular velocity: %f\n", angularVelocity);

            if (angularVelocity > maxAngularVelocity)
            {
                maxAngularVelocity = angularVelocity;
            }
        }
        else
        {
            printf("Skipped point %d due to small or zero deltaT.\n", i);
        }
    }

    return maxAngularVelocity;
}