/**
 * @file position.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_POSITION_H_
#define SRC_POSITION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>

#include "vector2d.h"

Vector2d::Vector2d(double theta) :
    x_(cos(theta)),
    y_(sin(theta)) {}

const Vector2d Vector2d::operator+(const Vector2d& rhs) {
  return Vector2d(x_+rhs.x_, y_+rhs.x_);
}

const Vector2d Vector2d::operator-(const Vector2d& rhs) {
  return Vector2d(rhs.x_-x_, rhs.y_-y_);
}

const Vector2d Vector2d::operator*(const Vector2d& rhs) {
  // dot product of two vectors
  return Vector2d(x_*rhs.x_, y_*rhs.y_);
}

void Vector2d::RotateByRadians(double theta) {
  x_ = x_*cos(theta) - y_*sin(theta);
  y_ = x_*sin(theta) + y_*sin(theta);
}

void Vector2d::SetMagnitude(double magnitude) {
  double theta = atan(y_/x_);
  x_ = magnitude * cos(theta);
  y_ = magnitude * sin(theta);
}

double Vector2d::GetMagnitude() {
  return pow(x_*x_ + y_*y_, 0.5);
}

double Vector2d::DistanceBetween(const Vector2d& vector) {
  double delta_x = x_ - vector.x_;
  double delta_y = y_ - vector.y_;
  return pow(delta_x*delta_x + delta_y*delta_y, 0.5);
}

void Vector2d::Print() {
  std::cout << "(" << x_ << "," << y_ << ")" << std::endl;
}

double Vector2d::GetDirection() {
  // return positive radians only
  return atan(y_/x_);
}

#endif /* SRC_POSITION_H_ */
