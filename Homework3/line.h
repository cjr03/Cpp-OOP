//
//  line.h
//  Homework3
//
//  Created by Cole Roberts on 1/25/25.
//

#ifndef LINE_H
#define LINE_H

#include <iostream>

struct point
{
   double x, y;
   point (double ix = 0.0, double iy = 0.0)
   {
     x = ix;
     y = iy;
   }
};

class line
{
public:
    line(double init_x0 = 0.0,
         double init_y0 = 0.0,
         double init_x1 = 1.0,
         double init_y1 = 0.0);
    // constructor
    // pre-condition: (init_x0, init_y0) and (init_x1, init_y1) are different points
    // post-condition:  this line has been initialized with the given points

    line (point p0, point p1);
    // constructor
    // pre-condition: p0 and p1 are different points
    // post-condition:  this line has been initialized with the given points

    bool is_vertical() const;
    //  pre-condition: none
    //  post-condition: true if this line is vertical

    bool is_horizontal() const;
    // pre-condition: none
    // post-condition: true if this line is horizontal

    bool contains(double x, double y) const;
    // pre-condition: none
    // post-condition: true if (x, y) is on this line

    bool contains(const point p) const;
    // pre-condition: none
    // post-condition: true if p is on this line

    bool is_parallel_to(const line & l) const;
    // pre-condition: none
    // post-condition: true if this line is parallel to line l

    double slope() const;
    // pre-condition: none
    // post-condition: slope of this line is returned (+/-inf if this line is vertical)

    double x_intercept() const;
    // pre-condition: none
    // post-condition: x-intercept of this line is returned (+/-inf if this line is horizontal)

    double y_intercept() const;
    // pre-condition: none
    // post-condition: y-intercept of this line is returned (+/-inf if this line is vertical)

    point get_p0() const;
    // pre-condition: none
    // post-condition: returns p0

    point get_p1() const;
    // pre-condition: none
    // post-condition: returns p1

private:
    point p0, p1;
    // invariant: p1 and p1 are two distinct points  on the line


};

std::istream & operator >> (std::istream & left, line & right);
// pre-condition: none
// post-condition: a line has been read from input stream is as 4 double values (x0, y0) (x1, y1)
//                 and (x0 != x1) or (y0 != y1)

std::ostream & operator << (std::ostream & left, const line & right);
// pre-condition: none
// post-condition: a line has been printed to output stream os in the format (p0.x, p0.y) (p1.x, p1.y)


#endif // LINE_H
