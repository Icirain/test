/**
 * @file obstacle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_OBSTACLE_H_
#define SRC_OBSTACLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/arena_mobile_entity.h"
#include "src/arena_immobile_entity.h"
#include "src/common.h"
#include "src/entity_type.h"
#include "src/pose.h"
#include "src/motion_handler_obstacle.h"
#include "src/motion_behavior_differential.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing an immobile obstacle within the Arena.
 *
 * Since obstacles are immobile, the Obstacle class is very simple.
 */
class Obstacle : public ArenaMobileEntity {
 public:
  /**
   * @brief Constructor.
   */
  Obstacle();

  /**
   * @brief Get the name of the Obstacle for visualization purposes, and to
   * aid in debugging.
   */
  std::string get_name() const override {
    return "Obstacle" + std::to_string(get_id());
  }

  void TimestepUpdate(unsigned int dt) override;
  /**
   * @brief Make obstacle reversed when collision happens and move in an arc within fixed time
   */
  void HandleCollision(EntityType object_type, ArenaEntity * object = NULL);
  /**
   * @param[out] reference of obstacle's motion handler
   */
  MotionHandlerObstacle get_motion_handler() {return motion_handler_; }
  /**
   * @param[out] reference of obstacle's motion behavior
   */
  MotionBehaviorDifferential get_motion_behavior() {return motion_behavior_; }

 private:
  MotionHandlerObstacle motion_handler_;
  MotionBehaviorDifferential motion_behavior_;
  int arc_time_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSTACLE_H_
