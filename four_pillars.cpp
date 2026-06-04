#include <iostream>
#include <vector>

class IEmployee{
    public:
        virtual ~IEmployee()=default;
        virtual float calculatePay()=0;
};

class FullTimeEmployee:public IEmployee{
    private:
        float salary;
    public:
        FullTimeEmployee(float s):salary(s){}
        float calculatePay() override{
            return salary;
        }
};

class PartTimeEmployee:public IEmployee{
    private:
        float hours;
        float rate;
    public:
        PartTimeEmployee(float h,float r):hours(h),rate(r){}
        float calculatePay() override{
            return hours*rate;
        }
};

class Contractor:public IEmployee{
    private:
        float rate;
        float days;
    public:
        Contractor(float r,float d):rate(r),days(d){}
        float calculatePay() override{
            return rate*days;
        }
};
        
int main(){
std::vector<IEmployee*> v;
v.push_back(new FullTimeEmployee(50000));
v.push_back(new PartTimeEmployee(48,1000));
v.push_back(new Contractor(31,645.16129));
float total=0;
for (IEmployee* i:v){
    total=i->calculatePay()+total;
}
std::cout<<total<<std::endl;
for (IEmployee* i:v){
    delete i;
}
};
