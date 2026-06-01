#include "shape.h"
#include <numbers>
#include "calculator.h"
const double pi=std::numbers::pi;
circle::circle(double r):radius(r){}
double circle::area() const{
return calculator::multiply(calculator::multiply(pi,radius),radius);
}
rectangle::rectangle(double w, double h):width(w),height(h){}
double rectangle::area() const{
return calculator::multiply(width,height);
}
triangle::triangle(double b, double h):base(b),height(h){}
double triangle::area() const{
return calculator::multiply(calculator::multiply(0.5,base),height);
}
