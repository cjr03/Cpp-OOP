//
//  line.cpp
//  Homework3
//
//  Created by Cole Roberts on 1/25/25.
//

#include "line.h"
#include <limits>

// constructor
// pre-condition: (init_x0, init_y0) and (init_x1, init_y1) are different points
// post-condition:  this line has been initialized with the given points
line::line(double init_x0,
           double init_y0,
           double init_x1,
           double init_y1) {
    p0 = point(init_x0, init_y0);
    p1 = point(init_x1, init_y1);
};

// constructor
// pre-condition: p0 and p1 are different points
// post-condition:  this line has been initialized with the given points
line::line(point p0, point p1) {
    p0 = p0;
    p1 = p1;
};

//  pre-condition: none
//  post-condition: true if this line is vertical
bool line::is_vertical() const {
    return p0.x == p1.x;
};

// pre-condition: none
// post-condition: true if this line is horizontal
bool line::is_horizontal() const {
    return p0.y == p1.y;
};

// pre-condition: none
// post-condition: true if (x, y) is on this line
bool line::contains(double x, double y) const {
    if(x > p0.x){
        return y == p0.y + (x - p0.x) * slope();
    } else {
        return y == p0.y - ((p0.x - x) * slope());
    }
};

// pre-condition: none
// post-condition: true if p is on this line
bool line::contains(const point p) const {
    if(p.x > p0.x){
        return p.y == p0.y + (p.x - p0.x) * slope();
    } else {
        return p.y == p0.y - ((p0.x - p.x) * slope());
    }
};

// pre-condition: none
// post-condition: true if this line is parallel to line l
bool line::is_parallel_to(const line & l) const {
    return slope() == l.slope();
};

// pre-condition: none
// post-condition: slope of this line is returned (+/-inf if this line is vertical)
double line::slope() const{
    if(is_vertical()){
        return std::numeric_limits<double>::infinity();
    } else {
        return (p1.y - p0.y) / (p1.x - p0.x);
    }
};

// pre-condition: none
// post-condition: x-intercept of this line is returned (+/-inf if this line is horizontal)
double line::x_intercept() const {
    if(is_horizontal()){
        return std::numeric_limits<double>::infinity();
    } else {
        if(p0.x > 0.00){
            return p0.x - (p0.y / slope());
        } else {
            return p0.x + ((0.00 - p0.y) / slope());
        }
    }
};


// pre-condition: none
// post-condition: y-intercept of this line is returned (+/-inf if this line is vertical)
double line::y_intercept() const {
    if(is_vertical()){
        return std::numeric_limits<double>::infinity();
    } else {
        if(p0.x > 0.00){
            return p0.y - (p0.x * slope());
        } else {
            return p0.y + ((0.00 - p0.x) * slope());
        }
    }
};

// pre-condition: none
// post-condition: returns p0
point line::get_p0() const {
    return p0;
};

// pre-condition: none
// post-condition: returns p1
point line::get_p1() const {
    return p1;
};

// pre-condition: none
// post-condition: a line has been read from input stream is as 4 double values (x0, y0) (x1, y1)
//                 and (x0 != x1) or (y0 != y1)
std::istream & operator >> (std::istream & left, line & right) {
    double x0, y0, x1, y1;
    left >> x0 >> y0 >> x1 >> y1;
    if(x0 == x1 && y0 == y1){
        throw std::invalid_argument("Points must be unique to create a line.");
    } else {
        right = line(x0, y0, x1, y1);
        return left;
    }
};

// pre-condition: none
// post-condition: a line has been printed to output stream os in the format (p0.x, p0.y) (p1.x, p1.y)
std::ostream & operator << (std::ostream & left, const line & right) {
    left << '(' << right.get_p0().x << ", " << right.get_p0().y << ") (" << right.get_p1().x << ", " << right.get_p1().y << ')';
    return left;
};
