#include <iostream>
#include "calculator.h"
#include "shape.h"
int main(){
std::cout<<"5+3="<<calculator::add(5,3)<<"\n";
std::cout<<"5*3="<<calculator::multiply(5,3)<<"\n";
std::cout<<"5-3="<<calculator::subtract(5,3)<<"\n";
std::cout<<"10.0/3.0="<<calculator::divide(10.0,3.0)<<"\n\n";
std::cout<<"Area of circle(r=5)="<<circle(5).area()<<"\n";
std::cout<<"Area of rectangle(w=4,h=6)="<<rectangle(4,6).area()<<"\n";
return 0;
}
