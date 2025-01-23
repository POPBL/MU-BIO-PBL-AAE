#include "point.h"
#include <stdlib.h>

void freePoints(point_t** const points)
{
    if (points && *points)
    {
        free(*points);
        *points = NULL;
    }
}