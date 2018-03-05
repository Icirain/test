/**
 * @file motion_handler_robot.h
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

#ifndef SRC_MOTION_HANDLER_OBSTACLE_H_
#define SRC_MOTION_HANDLER_OBSTACLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cassert>
#include <iostream>

#include "src/common.h"
#include "src/motion_handler.h"
#include "src/sensor_touch.h"
#include "src/communication.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/

class MotionHandlerObstacle : public MotionHandler {
 public:
  explicit MotionHandlerObstacle(ArenaMobileEntity * ent)
      : MotionHandler(ent) {this->set_velocity(3.0, 3.0); }

  MotionHandlerObstacle(const MotionHandlerObstacle& other) = default;
  MotionHandlerObstacle& operator=(const MotionHandlerObstacle& other) = default;

  void UpdateVelocity() override;

	
};

NAMESPACE_END(csci3081);

#endif  // SRC_MOTION_HANDLER_OBSTACLE_H_