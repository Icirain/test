/**
 * @file vector2d.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_VECTOR2D_H_
#define SRC_VECTOR2D_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple representation of a 2d vector at the origin.
 * It is stored as an (x,y). Magnitude and direction are derived from x,y
 */
class Vector2d {
 public:
  /**
    * Constructors
  **/
  Vector2d(void) : x_(0), y_(0) {}
  Vector2d(double x, double y) : x_(x), y_(y) {}

  /**
    * Constructor
    * param [in] theta: direction of the vector.
    *
    * Converts direction into (x,y) as a unit vector (i.e. magnitude=1);
    **/
  explicit Vector2d(double theta);

  /**
  * Overloaded Operators
  **/

  /**
    * Dot product of two vectors.
    * param [in] rhs: right hand side of this*rhs.
    * param [out] constant Vector with results of dot product
    **/
  const Vector2d operator*(const Vector2d& lhs);

  /**
    * Vector addition.
    * param [in] rhs: right hand side of this+rhs
    * param [out] constant Vector with results of added vectors
    **/
  const Vector2d operator+(const Vector2d& lhs);

  /**
    * Vector subtraction.
    * param [in] rhs: right hand side of this-rhs
    * param [out] constant Vector with results of subtracted vectors
    **/
  const Vector2d operator-(const Vector2d& lhs);

  /**
    * Absolute distance between the end points of each vector.
    * param [in] rhs: left hand side of this-rhs
    * param [out] constant Vector with results of subtracted vectors
    **/
  double DistanceBetween(const Vector2d& vector);

  /**
    * Mutator: Rotate the vector by theta degrees about the origin.
    * param [in] theta: double in radians
    **/
  void RotateByRadians(double theta);

  /**
    * Mutator: Set the magnitude of the vector using its direction.
    * param [in] theta: double in radians
    **/
  void SetMagnitude(double magnitude);


  /**
    * Derived getter of magnitude (length) of vector
    **/
  double GetMagnitude();


  void Print();

  /**
    * Derived getter of direction (angle of rotation) of vector
    **/
  double GetDirection();

  void set_xy(double x, double y) { x_ = x; y_ = y; }

  /**
    * Component-wise getters and setters.
    **/
  double get_x() {return x_;}
  void set_x(double x) { x_ = x; }
  double get_y() {return y_;}
  void set_y(double y) { y_ = y; }

 private:
  double x_;
  double y_;
};

#endif /* SRC_VECTOR2D_H_ */
