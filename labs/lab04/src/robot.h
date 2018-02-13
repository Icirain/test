/*
* @copyright 2018 Rui Zuo, All rights reserved.
*/

#ifndef LABS_LAB04_SRC_ROBOT_H_
#define LABS_LAB04_SRC_ROBOT_H_

#include <string>
#include <utility>

using namespace std;

namespace csci3081 {

class Robot{
 private:
    double x_;
    double y_;
    double radius_;
    double velocity_;
    double angle_;
    double center_x_;
    double center_y_;
 public:
       Robot(double radius, double x, double y);
       double radius() const;
       void radius(double radius);
       std::pair<double, double> position() const;
       void position(std::pair<double, double> pos);
       double velocity() const;
       void velocity(double velocity);
       double heading_angle() const;
       void heading_angle(double angle);
       void UpdatePosition(double dt);
       void UpdateHeadingAngle();
};
} // namespace csci3081



#endif  // LABS_LAB04_SRC_ROBOT_H_
