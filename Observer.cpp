#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class IObserver{
  public:
    virtual ~IObserver()=default;
    virtual void onEvent(const std::string& msg)=0;
};

class LoggerObserver: public IObserver {
  public:
      void onEvent(const std::string& msg) override{
          std::cout<<"LOG: "<< msg <<"\n";
      }
};

class CounterObserver: public IObserver{
  private:
      int count=0;
  public:
      void onEvent(const std::string&) override{
          count++;
      }
      int getCount() const{
          return count;
      }
};

class EventBus{
  private:
      std::vector<IObserver*> observers;
  public:
      void addObserver(IObserver* obs){
        observers.push_back(obs);
      }
      
      void removeObserver(IObserver* obs){
          observers.erase(std::remove(observers.begin(),observers.end(),obs),observers.end());
      }
      
      void notify(const std::string& msg){
          for (auto obs:observers){
              obs->onEvent(msg);
          }
      }
};

int main(){
    EventBus bus;
    LoggerObserver logger;
    CounterObserver counter;
    
    bus.addObserver(&logger);
    bus.addObserver(&counter);
    
    bus.notify("button pressed");
    bus.notify("button pressed");
    bus.notify("button pressed");
    
    std::cout<<"count="<< counter.getCount()<<"\n\n";
    return 0;
}



