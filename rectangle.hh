#ifndef RECTANGLE_HH
#define RECTANGLE_HH

class Rectangle
{
  private:
    double x_;
    double y_;
  public:
    Rectangle(float x=0, float y=0);
    void SetX(float x);
    void SetY(float y);
    float Perimeter();
    float Area();
    void Show();
    bool SameArea(Rectangle r);
};

#endif // RECTANGLE_HH
