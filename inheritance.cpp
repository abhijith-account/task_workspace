#include <string>
#include <iostream>

class Vehicle {
  private:
      std::string brand_;
      int speed;
  public:
      std::string getBrand() const{
      return brand_;
      }
      int getSpeed() const{
      return speed;
      }
      virtual ~Vehicle()=default;
      int accelerate(int a){
      speed=speed+a;
      return speed;
      }
      
      int brake(int b){
      speed=speed-b;
      return speed;
      }
      Vehicle(std::string b,int s):brand_(b),speed(s){}
      virtual void describe(){
            std::cout<<brand_<<":"<<speed<<std::endl;
      }
};
 
class Car:public Vehicle{
  private:
      int doors_;
  public:
      Car(std::string b,int s,int d):Vehicle(b,s),doors_(d){}
      void describe() override{
            std::cout<<getBrand()<<":"<<getSpeed()<<","<<doors_<<std::endl;
      }
};

class MotorCycle:public Vehicle{
  private:
      bool hasSidecar_;
  public:
      MotorCycle(std::string b,int s,bool c):Vehicle(b,s),hasSidecar_(c){}
      void describe() override{
            std::cout<<getBrand()<<":"<<getSpeed()<<","<<hasSidecar_<<std::endl;
      }
};

int main(){
Car c("Toyota",120,4);
c.describe();
MotorCycle m("Bajaj",100,false); 
m.describe();
return 0;
}
