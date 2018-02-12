#ifndef LAB04_ROBOT_H_
#define LAB04_ROBOT_H_

#include<string>
using namespace std

class Robot{
   public:
       Robot(double radius, double x, double y);
       double radius(void) const;
       void radius(double radius);
       std::pair<double, double> position(void) const;
       void position(std::pair<double, double> pos);
       double velocity(void) const;
       void velocity(double velocity);
       double heading_angle(void) const;
       void heading_angle(double angle);
       void UpdatePosition(double dt);
    private:
       double x;
       double y;
       double radius;
}
