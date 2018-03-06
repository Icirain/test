/**
 * @file obstacle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/obstacle.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Obstacle::Obstacle() :
    motion_handler_(this),
    motion_behavior_(this),
    arc_time_(0) {
  set_color(OBSTACLE_COLOR);
  set_pose(OBSTACLE_POSITION);
  set_radius(OBSTACLE_RADIUS);
  set_type(kObstacle);
}

void Obstacle::TimestepUpdate(unsigned int dt) {
  if (arc_time_ > 0) {
    arc_time_ -= dt;
    if (arc_time_ == 0) {
       motion_handler_.set_velocity(3.0, 3.0);
    }
  }

  motion_handler_.UpdateVelocity();
  motion_behavior_.UpdatePose(dt, motion_handler_.get_velocity());
  sensor_touch_->Reset();
}

void Obstacle::HandleCollision(__unused EntityType object_type,
                               __unused ArenaEntity * object) {
  sensor_touch_->HandleCollision(object_type, object);
  if (object_type == kBase || object_type == kRobot) {
     motion_handler_.set_velocity(1.5, 3.0);
     arc_time_ = 20;
  }
}

NAMESPACE_END(csci3081);
