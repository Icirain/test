/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Robot::Robot() :
    motion_handler_(this),
    motion_behavior_(this),
    lives_(4),
    mercy_time_(0) {
  set_type(kRobot);
  set_color(ROBOT_COLOR);
  set_pose(ROBOT_INIT_POS);
  set_radius(ROBOT_RADIUS);
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Robot::TimestepUpdate(unsigned int dt) {
  // Update heading as indicated by touch sensor
  if (mercy_time_ > 0) {
    mercy_time_ -= dt;
    // set_color(mercy_time_%2 == 0? ROBOT_COLOR:DEFAULT_COLOR);
  }
  // Change color for robot in mercy_time_
  if (mercy_time_ % 2 == 0)set_color(ROBOT_COLOR);
  else
  set_color(MERCY_COLOR);
  motion_handler_.UpdateVelocity();

  // Use velocity and position to update position
  motion_behavior_.UpdatePose(dt, motion_handler_.get_velocity());

  // Reset Sensor for next cycle
  sensor_touch_->Reset();
} /* TimestepUpdate() */

void Robot::Reset() {
  set_pose(ROBOT_INIT_POS);
  motion_handler_.set_max_speed(ROBOT_MAX_SPEED);
  motion_handler_.set_max_angle(ROBOT_MAX_ANGLE);
  sensor_touch_->Reset();
} /* Reset() */

void Robot::HandleCollision(EntityType object_type, ArenaEntity * object) {
  sensor_touch_->HandleCollision(object_type, object);
  if (object_type >= kRightWall && object_type <= kBottomWall) {
    int lives_remained = get_lives();
    set_lives(lives_remained <= 0? 0 : lives_remained - 1);
    return;
    // lives will be deducted iff robot is
    // out of mercy_time_ when mercy_time_ is 0
  } else if (object_type == kLights && mercy_time_ == 0) {
    int lives_remained = get_lives();
    set_lives(lives_remained <= 0? 0 : lives_remained - 1);
    // When collided with an obstacle ,
    // a mercy time will be provided in about 2s
    mercy_time_ = 36;
  }
  motion_handler_.set_velocity(0, 0);
}

void Robot::IncreaseSpeed() {
  motion_handler_.IncreaseSpeed();
}
void Robot::DecreaseSpeed() {
  motion_handler_.DecreaseSpeed();
}
void Robot::TurnRight() {
  motion_handler_.TurnRight();
}
void Robot::TurnLeft() {
  motion_handler_.TurnLeft();
}

NAMESPACE_END(csci3081);
