#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string.h>
#include<memory>

class IObserver{
  public:
    virtual ~IObserver()=default;
    virtual void onEvent(const std::string& msg)=0;
};

class LoggerObserver:public IObserver{
  public:
    void onEvent(const std::string& msg) override{
        std::cout<<"LOG: "<<msg<<"\n";
    }
};

class ShapeEventBus{
  private:
      std::vector<IObserver*> observers;
  public:
      void addObserver(IObserver* obs){
        observers.push_back(obs);
      }
      void notify(const std::string& msg){
        for (auto obs:observers){
          obs->onEvent(msg);
        }
      }
};

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
      private:
          ShapeEventBus& bus;
      public:
          ShapeFactory(ShapeEventBus& busRef):bus(busRef){}
          std::unique_ptr<IShape> create(ShapeType type){
              std::unique_ptr<IShape> shape=nullptr;
              switch(type){
                  case ShapeType::circle:
                      shape=std::make_unique<circle>(5.5f);
                      break;
                  case ShapeType::triangle:
                      shape=std::make_unique<triangle>(4.2f,6.1f);
                      break;
                  case ShapeType::rectangle:
                      shape=std::make_unique<rectangle>(3.3f,8.8f);
                      break;
               }
               if (shape){
                  bus.notify("Created a "+ shape->name());
               }
               return shape;
          }                                  
};

class IRoundingStrategy{
  public:
      virtual ~IRoundingStrategy()=default;
      virtual float roundValue(float val)=0;
};

class FloorStrategy:public IRoundingStrategy{
  public:
      float roundValue(float val) override{
        return std::floor(val);
      }
};
 
class CeilStrategy:public IRoundingStrategy{
  public:
      float roundValue(float val) override{
        return std::ceil(val);
      }
};

class RoundStrategy:public IRoundingStrategy{
  public:
      float roundValue(float val) override{
        return std::round(val);
      }
};

class AreaCalculator{
  private:
    IRoundingStrategy* strategy=nullptr;
  public:
    void setStrategy(IRoundingStrategy* newStrategy){
      strategy=newStrategy;
    }
    float calculateRoundedArea(const IShape& shape){
      float exactArea=shape.area();
      return strategy?strategy->roundValue(exactArea):exactArea;
    }
};

int main(){
  ShapeEventBus bus;
  LoggerObserver logger;
  bus.addObserver(&logger);
  ShapeFactory factory(bus);
  
  FloorStrategy floorStrat;
  CeilStrategy ceilStrat;
  RoundStrategy roundStrat;
  AreaCalculator calc;
  
  auto c=factory.create(ShapeType::circle);
  auto t=factory.create(ShapeType::triangle);
  auto r=factory.create(ShapeType::rectangle);
  
  std::cout<<"Area of "<<c->name()<<": "<<c->area()<<std::endl;
  std::cout<<"Area of "<<t->name()<<": "<<t->area()<<std::endl;
  std::cout<<"Area of "<<r->name()<<": "<<r->area()<<std::endl;
  
  calc.setStrategy(&floorStrat);
  std::cout<<c->name()<<"Floored value: "<<calc.calculateRoundedArea(*c)<<std::endl;
  
  calc.setStrategy(&ceilStrat);
  std::cout<<t->name()<<"Ceiled value: "<<calc.calculateRoundedArea(*t)<<std::endl;
  
  calc.setStrategy(&roundStrat);
  std::cout<<r->name()<<"Rounded value: "<<calc.calculateRoundedArea(*r)<<std::endl;
}

