/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>

#include "src/sensor_touch.h"
#include "src/base.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorTouch::HandleCollision(
  __unused EntityType object_type,
  __unused ArenaEntity * object) {
  // if(object_type >= kRightWall && object_type <= kBottomWall) {
     output_ = true;
  //}
}

NAMESPACE_END(csci3081);
