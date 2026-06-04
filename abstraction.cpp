#include <iostream>
#include <string>
#include <vector>

class IAnimal{
    public:
        virtual ~IAnimal()=default;
        virtual void speak()=0;
        virtual std::string type()=0;
};

class Dog:public IAnimal{
    public:
        void speak(){
        std::cout<<"Bow Bow"<<std::endl;
        }
        
        std::string type(){
        return "Dog";
        }
};

class Cat:public IAnimal{
    public:
        void speak(){
        std::cout<<"Meow"<<std::endl;
        }
        
        std::string type(){
        return "Cat";
        }
};

class Cow:public IAnimal{
    public:
        void speak(){
        std::cout<<"Moo"<<std::endl;
        }
        
        std::string type(){
        return "Cow";
        }
};

int main(){
  std::vector<IAnimal*> v;
  v.push_back(new Dog());
  v.push_back(new Cat());
  v.push_back(new Cow());
  for(IAnimal* b:v){
        b->speak();
  }
  for(IAnimal* b:v){
        delete b;
  }
  return 0;
}
