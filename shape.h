#ifndef shape_h
#define shape_h
class shape{
  public:
    virtual ~shape()=default;
    virtual double area() const=0;
};
class circle:public shape{
  private:
    double radius;
  public:
    circle(double r);
    double area() const override;
};
class rectangle:public shape{
  private:
    double width,height;
  public:
    rectangle(double w,double h);
    double area() const override;
};
class triangle:public shape{
  private:
    double base,height;
  public:
    triangle(double b,double h);
    double area() const override;
};
#endif
