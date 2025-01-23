#pragma once
typedef struct point_t
{
    double t;     // Denbora
    double x;     // X koordenatua
    double y;     // Y koordenatua
    double vx;    // X abiadura
    double vy;    // Y abiadura
    double v;     // Abiadura totala
    double theta; // Angeluaren balioa (radianetan)
} point_t;

void freePoints(point_t** points);
