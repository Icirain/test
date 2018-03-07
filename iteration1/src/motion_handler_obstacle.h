/**
 * @file motion_handler_obstacle.h
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
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A class used to manage the speed of obstacles. Currently speed on both sides are set same.
 *
 * The factory keeps track of the number of entities of each type and overall.
 * It assigns ID's to the entity when it creates it.
 * The factory randomly places entities, and in doing so, attempts to not
 * have them overlap.
 */
class MotionHandlerObstacle : public MotionHandler {
 public:
/**
 *@brief Default constructor for MontionHandler
 */
  explicit MotionHandlerObstacle(ArenaMobileEntity * ent)
      : MotionHandler(ent) {this->set_velocity(3.0, 3.0); }

  MotionHandlerObstacle(const MotionHandlerObstacle& other) = default;
  MotionHandlerObstacle& operator=
  (const MotionHandlerObstacle& other) = default;
  
  /**
  *Currently called from arena to update the speed and pose of obstacle.
  */
  void UpdateVelocity() override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_MOTION_HANDLER_OBSTACLE_H_

