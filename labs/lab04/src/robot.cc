#include<string>
#include "robot.h"
#include <cmath>
using namespace std;

Robot::Robot(double radius, double x, double y){
   this->radius_ = radius;
   this->x = x;
   this->y = y;
}

double Robot::radius() const{
  return this->radius_;
}

void Robot::radius(double radius){
  this->radius_ = radius;
}

std::pair<double, double> Robot::position() const{
   std::pair<double, double> pos;
   pos.first = this->x;
   pos.second = this->y;
   return pos;
}

void Robot::position(std::pair<double, double> pos){
     this->x = pos.first;
     this->y = pos.second;
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
   this->x +=  this->velocity()*sin(dt);
   this->y +=  this->velocity()*cos(dt);
}

