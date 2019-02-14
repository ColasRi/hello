#include "rectangle.hh"

#include <iostream>

Rectangle::Rectangle(float x, float y) {
  x_ = x;
  y_ = y;
}

void Rectangle::SetX(float x) {
  x_ = x;
}

void Rectangle::SetY(float y) {
  y_ = y;
}

float Rectangle::Perimeter() {
  return 2 * (x_ + y_);
}

float Rectangle::Area() {
  return x_ * y_;
}

void Rectangle::Show() {
  std::cout << "Size: (" << x_ << ", " << y_ << ")" << std::endl;
  std::cout << "Area: " << this->Area() << std::endl;
}

bool Rectangle::SameArea(Rectangle r) {
  return this->Area() == r.Area();
}
