#include "calculator.h"
#include <stdexcept>

double calculator::add(double a, double b){
    return a+b;
}
double calculator::multiply(double a, double b){
    return a*b;
}
double calculator::subtract(double a, double b){
    return a-b;
}
float calculator::divide(float a, float b){
    if (b==0){
      throw std::invalid_argument("Division by zero");
    }
    return a/b;
}
