#include <iostream>
#include <string>
#include <memory>
#include <cmath>

enum class ShapeType{circle,rectangle,triangle};

class IShape{
  public:
      virtual ~IShape()=default;
      virtual float area() const=0;
      virtual std::string name() const=0;
};

class circle:public IShape{
  private:
      float radius;
  public:
      circle(float r):radius(r){}
      float area() const override{
        return 3.14159f*radius*radius;
      }
      std::string name() const override{
          return "circle";
      }
};

class rectangle:public IShape{
  private:
      float width,height;
  public:
      rectangle(float w,float h):width(w),height(h){}
      float area() const override{
        return width*height;
      }
      std::string name() const override{
        return "rectangle";
      }
};

class triangle:public IShape{
  private:
      float base,height;
  public:
      triangle(float b,float h):base(b),height(h){}
      float area() const override{
        return 0.5f*base*height;
      }
      std::string name() const override{
          return "triangle";
      }
};

class ShapeFactory{
      public:
          static std::unique_ptr<IShape> create(ShapeType type){
              switch (type){
                  case ShapeType::circle: 
                      return std::make_unique<circle>(5.0f);
                  case ShapeType::rectangle: 
                      return std::make_unique<rectangle>(4.0f,6.0f);
                  case ShapeType::triangle:
                      return std::make_unique<triangle>(3.0f,8.0f);
                  default:
                      return nullptr;
               }
          }
};

int main(){
  auto c=ShapeFactory::create(ShapeType::circle);
  auto t=ShapeFactory::create(ShapeType::triangle);
  auto r=ShapeFactory::create(ShapeType::rectangle);
  
  std::cout<<"Area of "<<c->name()<<": "<<c->area()<<std::endl;
  std::cout<<"Area of "<<t->name()<<": "<<t->area()<<std::endl;
  std::cout<<"Area of "<<r->name()<<": "<<r->area()<<std::endl;
  
  return 0;
}

    
          
                      
