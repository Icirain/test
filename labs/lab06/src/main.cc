/**
 * @file main.cc
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <cmath>

#include "vector2d.h"

int main(int, char **) {
  Vector2d vector_1(2, 2);
  Vector2d vector_2(-3, 1);
  Vector2d vector_3(-2, -4);
  Vector2d vector_4(1, -3);
  Vector2d vector_m(3.14*3/4);

  Vector2d answer;

  answer = vector_1 + vector_2;
  answer = vector_3 - vector_4;
  answer = vector_1 * vector_3;
  answer = vector_2 + vector_4;

  std::cout << vector_1.DistanceBetween(vector_2) << std::endl;

  vector_1.Print();
  vector_1.RotateByRadians(3.14/4.0);
  vector_1.Print();

  vector_m.Print();
  vector_m.SetMagnitude(3);
  vector_m.Print();

  return 0;
}
