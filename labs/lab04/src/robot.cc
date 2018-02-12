#include<string>
#include "robot.h"
using namespace std

void Robot::Robot(double radius, double x, double y){
   this->radius = radius;
   this->x = x;
   this->y = y;
}

double Robot::radius() const{
  return this->radius;
}

void Robot::radius(double radius){
  this->radius = radius;
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

double Robot::velocity(){
   return this->velocity;
}

void Robot::velocity(double velocity){
    this->velocity = velocity;
}

double Robot::heading_angle() const{
    return this->heading_angle;
}

void Robot::heading_angle(double angle){
   this->heading_angle = angle;
}

void Robot::UpdatePosition(double dt){
   this->x +=  this->velocity*sin(dt);
   this->y +=  this->velocity*cos(dt);
}

