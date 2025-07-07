#pragma once

typedef struct
{
    double x;
    double y;
} Point;

int comparePolarOrder(Point P0, Point point, Point key);
int angleOrientation(Point nextToTop, Point Top, Point pointToBeInserted);
double euclidianDistance(Point P0, Point point);