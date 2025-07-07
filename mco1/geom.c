#include <stdio.h>
#include <math.h>
#include "geom.h"

/* comparePolarOrder: compares the angle of two points with respect to a reference point p0
    @param p0: the reference point
    @param p1: the first point to compare
    @param p2: the second point to compare
    @return int: returns 1 if p2 has a greater polar angle w/ respect to p0 than p1 and 0 otherwise
*/
int comparePolarOrder(Point p0, Point p1, Point p2)
{
    int orientation = angleOrientation(p0, p1, p2); // 0 means collinear, 1 means clockwise, -1 means counterclockwise
    if (orientation == 0)
        return euclidianDistance(p0, p1) < euclidianDistance(p0, p2); // compare distances from pivotPoint to both points

    else
        return orientation == -1; // true if counterclockwise else clockwise
}

/* angleOrientation: returns an integer corresponding to the orientation of the next point with respect to the vector formed by two points (prev and top)
    @param prev: the first point 
    @param top: the current point 
    @param next: the next point of which to compare the incoming orientation of
    @return int: returns 0 if the points are collinear, 1 if the orientation is clockwise, and -1 if the orientation is counter-clockwise
*/
int angleOrientation(Point prev, Point top, Point next)
{
    int returnVal = 0;
    // formula for finding the determinant of a 2x2 matrix using 3 point cross product to compute for orientation
    // (y2-y1) * (x3-x2) - (x2-x1) * (y3-y1) derived from ad-bc
    double angleVal = (top.y - prev.y) * (next.x - top.x) - (top.x - prev.x) * (next.y - top.y);
    if (angleVal == 0)
    {
        returnVal = 0; // collinear
    }
    else if (angleVal > 0)
    {
        returnVal = 1; // clockwise
    }
    else
    {
        returnVal = -1; // counter-clockwise
    }
    return returnVal;
}

/* euclidianDistance: returns the distance between two points on a Euclidian plane (or basically, a cartesian plane)
    @param p1: the first point 
    @param p2: the second point
    @return double: the distance between the two points p1 and p2
*/
double euclidianDistance(Point p1, Point p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}