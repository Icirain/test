/**
 * @file robot_land.cc
 *
 * @copyright 201 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_land.h"
#include <cmath>

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

// Hard coded for 2 robots moving in circular patterns
int RobotLand::get_num_robots(void) { return 2; }

// Hard coded for now...
// Once the robot class is added, this getter should call the robot getters
bool RobotLand::get_robot_pos(int id, double *x_pos, double *y_pos) {
  if (id == 0) {
    test1->UpdatePosition(sim_time_);
    *x_pos = test1->position().first;
    *y_pos = test1->position().second;
    return true;
  } else if (id == 1) {
    // make this robot slower
    double t = 0.75 * sim_time_;
    *x_pos = test2->position().first;
    *y_pos = test2->position().second;
    return true;
  } else {
    return false;
  }
}

// Hard coded for now...
// Once the robot class is added, this getter should call the robot getters
// Notice the use of "id" -- how will you handle this in your robot class??
bool RobotLand::get_robot_vel(int id, double *x_vel, double *y_vel) {
  double xnow, ynow, xprev, yprev;
  double delta = 0.1;
  if (id == 0) {
    double angle = sim_time_;
    double velocity = test1->velocity();

    *x_vel = velocity * cos(angle);
    *y_vel = velocity * sin(angle);

    return true;
  } else if (id == 1) {
    // make this robot slower
    double t = 0.75 * sim_time_;
    double angle = t;
    double velocity = test2->velocity();

    *x_vel = velocity * cos(angle);
    *y_vel = velocity * sin(angle);
    return true;
  } else {
    return false;
  }
}

// Hard coded for now...
double RobotLand::get_robot_radius(int id) { return 50; }

// Hard coded for now...  in radians
double RobotLand::get_robot_sensor_angle(int id) { return 2.0; }

// Hard coded for now...
double RobotLand::get_robot_sensor_distance(int id) {
  return 3.0 * get_robot_radius(id);
}

// Hard coded for now...
int RobotLand::get_num_obstacles() { return 1; }

// Hard coded for now...
bool RobotLand::get_obstacle_pos(int id, double *x_pos, double *y_pos) {
  if (id == 0) {
    *x_pos = 200;
    *y_pos = 300;
    return true;
  }
  return false;
}

// Hard coded for now...
double RobotLand::get_obstacle_radius(int id) { return 75; }
