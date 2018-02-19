/**
 * @file obstacle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */


/**
 * A new class named obstacle to define the attribute of
 * Will be used afterwards
 */

#ifndef SRC_OBSTACLE_H_
#define SRC_OBSTACLE_H_

#include <utility>

class Obstacle {
 public:
  Obstacle() : radius_(10), position_(20.0, 20.0) {}
  int get_radius() {return radius_;}
  std::pair<double, double> get_pos() {return pos_;}
 private:
  int radius_;
  std::pair<double, double> pos_;
}

#endif  // SRC_OBSTACLE_H_ *
