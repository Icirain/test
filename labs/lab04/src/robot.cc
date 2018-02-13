#include<string>
#include "robot.h"
#include <cmath>
using namespace std;

NAMESPACE_BEGIN(csci3081);
#define PI 3.141592653589793238462643383279502884


Robot::Robot(double radius, double x, double y):
x_(x), y_(y),radius_(radius) ,velocity_(0.005), angle_(PI/2),center_x_(x - radius), center_y_(y)
{

}

double Robot::radius() const{
  return this->radius_;
}

void Robot::radius(double radius){
  this->radius_ = radius;
}

std::pair<double, double> Robot::position() const{
   std::pair<double, double> pos;
   pos.first = this->x_;
   pos.second = this->y_;
   return pos;
}

void Robot::position(std::pair<double, double> pos){
     this->x_ = pos.first;
     this->y_ = pos.second;
}

double Robot::velocity() const{
   return this->velocity_;
}

void Robot::velocity(double velocity){
    this->velocity_ = velocity;
}

double Robot::heading_angle() const{
    return this->angle_;
}

void Robot::heading_angle(double angle){
   this->angle_ = angle;
}

void Robot::UpdatePosition(double dt){
    std::pair<double, double> pos = this->position();
    double speed = this->velocity();
    /*double angle = this->heading_angle();
    double s_x = speed * cos(angle);
    double s_y = speed * sin(angle);
    pos.first += s_x * dt;
    pos.second += s_x * dt;*/
    double s_x = speed * cos(dt);
    double s_y = speed * sin(dt);
    pos.first += s_x * dt;
    pos.second += s_y * dt;
    this->position(pos);
    //this->UpdateHeadingAngle();

}
void Robot::UpdateHeadingAngle(){
     std::pair<double, double> pos = this->position();
     double delta_x = pos.first - this->center_x_;
     double delta_y = pos.second - this->center_y_;
     this->angle_ = PI/2 - atan2(delta_x, delta_y) ;
}
