#include <iostream>
#include <vector>
#include <string>
#include <numbers>

class Shape{
  public:
      virtual float area()=0;
      virtual std::string name()=0;
      virtual ~Shape()=default;
};

class Circle:public Shape{
  private:
      float radius;
  public:
      Circle(float r):radius(r){}
      
      float area() override{
          return (std::numbers::pi*radius*radius);
      }
      
      std::string name() override{
          return "Circle";
      }
};

class Rectangle:public Shape{
  private:
      float width,height;
  public:
      Rectangle(float w,float h):width(w),height(h){}
      
      float area() override{
          return (width*height);
      }
      
      std::string name() override{
          return "Rectangle";
      }
};

class Triangle:public Shape{
  private:
      float base,height;
  public:
      Triangle(float b,float h):base(b),height(h){}
      
      float area() override{
          return (0.5f*base*height);
      }
      
      std::string name() override{
          return "Triangle";
      }
};

int main(){
std::vector<Shape*> v;
v.push_back(new Circle(5));
v.push_back(new Rectangle(4,3));
v.push_back(new Triangle(3,4));
for (Shape* i:v){
    std::cout<<i->name()<<":"<<i->area()<<std::endl;
}
for (Shape* i:v){
    delete i;
}

return 0;
}
