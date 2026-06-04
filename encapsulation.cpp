#include <iostream>

class BankAccount {
  private:
      float balance_=0;
  public:
      void deposit(float amt){
          balance_=amt+balance_;
      }
      
      void withdraw(float amt){
          if (balance_<amt){
            std::cout<<"error"<<std::endl;
          }
          else{
            balance_=balance_-amt;
          }
      }
      
      float getBalance(){
          return balance_;
      }
};

int main(){
  BankAccount acc;
  acc.deposit(1000);
  acc.withdraw(300);
  acc.withdraw(800);
  std::cout<<acc.getBalance()<<std::endl;
  return 0;
}
