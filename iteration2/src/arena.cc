/**
 * @file arena.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <iostream>

#include "src/arena.h"
#include "src/arena_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params *const params)
    : x_dim_(params->x_dim),
      y_dim_(params->y_dim),
      factory_(new EntityFactory),
      entities_(),
      mobile_entities_(),
      game_status_(PLAYING),
      base_captured(0),
      is_playing(false) {
  AddRobot();
  AddEntity(kBase, 3);
  AddEntity(kLights, params->n_obstacles);
}

Arena::~Arena() {
  for (auto ent : entities_) {
    delete ent;
  } /* for(ent..) */
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Arena::AddRobot() {
  robot_ = dynamic_cast<Robot *>(factory_->CreateEntity(kRobot));
  entities_.push_back(robot_);
  mobile_entities_.push_back(robot_);
}

void Arena::AddEntity(EntityType type, int quantity) {
  for (int i = 0; i < quantity; i++) {
    ArenaEntity *new_entity = factory_->CreateEntity(type);
    entities_.push_back(new_entity);
    if (type == kLights) {
      Lights* new_obstacle = dynamic_cast<Lights *>(new_entity);
      mobile_entities_.push_back(new_obstacle);
      new_obstacle = NULL;
    }
    new_entity = NULL;
  }
}

void Arena::Reset() {
  for (auto ent : entities_) {
    ent->Reset();
  } /* for(ent..) */
} /* reset() */

// The primary driver of simulation movement. Called from the Controller
// but originated from the graphics viewer.
void Arena::AdvanceTime(double dt) {
  // std::cout<<is_playing<<std::endl;
  // If is_playing is false, which means
  // the game is in paused status, the time will not be advanced
  if (!(dt > 0) || !is_playing) {
    return;
  }
  // When the is_playing is true,
  // all the entities will be updated and game is active
  for (size_t i = 0; i < 1; ++i) {
    UpdateEntitiesTimestep();
  } /* for(i..) */
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep() {
  /*
   * First, update the position of all entities, according to their current
   * velocities.
   * @TODO: Should this be just the mobile entities ??
   */
  // int base_captured = 0;
  for (auto ent : entities_) {
    ent->TimestepUpdate(1);
  }
  for (auto &ent1 : mobile_entities_) {
    // If confronted a robot, UpdateEntitiesTimestepRobot will be called
    if (ent1 -> get_type() == kRobot) {
      Robot* robot_entity_ = dynamic_cast<Robot*>(ent1);
      UpdateEntitiesTimestepRobot(robot_entity_);
      robot_entity_ = NULL;
    } else {
    // If a obstacle confronted,
    // UpdateEntitiesTimestepLights will be called
      Lights* obstacle_entity_ = dynamic_cast<Lights*>(ent1);
      UpdateEntitiesTimestepLights(obstacle_entity_);
      obstacle_entity_ = NULL;
    }
  }
  return;
}  // UpdateEntitiesTimestep()

void Arena::UpdateEntitiesTimestepRobot(Robot* robot_entity_) {
  EntityType wall = GetCollisionWall(robot_entity_);
  // Process the conditio that collides with a wall
  if (kUndefined != wall) {
    AdjustWallOverlap(robot_entity_, wall);
    robot_entity_-> HandleCollision(wall);
  }
  for (auto &ent : entities_) {
    if (ent == robot_entity_)continue;
    if (!IsColliding(robot_entity_, ent))continue;
    robot_entity_->HandleCollision(ent->get_type(), ent);
    AdjustEntityOverlap(robot_entity_, ent);
    if (ent->get_type() == kBase) {
      // If collide entity is a base, status of base will
      // be changed and base_captured will add one if it is an uncaptured base
      Base* temp_base_refer = dynamic_cast<Base*>(ent);
      if (!temp_base_refer-> IsCaptured()) {
        temp_base_refer->set_captured(true);
        this->base_captured++;
        RgbColor new_color(kBlue, kBlue, kBlue);
        temp_base_refer->set_color(new_color);
        // change the color of base if captured
      }
      temp_base_refer = NULL;
      // Check if all bases are captured, if so, game is won
      if (base_captured == 3) {
        set_game_status(WON);
      }
    }
    if (ent->get_type() == kLights) {
      Lights* temp_obstacle_refer = dynamic_cast<Lights*>(ent);
      // If confronted a obstacle, HandleCollision
      // function will be called by collided obstacle
      // to let it seperated
      temp_obstacle_refer->HandleCollision(robot_entity_->get_type(),
      robot_entity_);
      temp_obstacle_refer = NULL;
    }
  }
  // Check if robot has been dead
  if (robot_entity_->get_lives() == 0) {
    set_game_status(LOST);
  }
}

void Arena::UpdateEntitiesTimestepLights(Lights* obstacle_entity_) {
  EntityType wall = GetCollisionWall(obstacle_entity_);
  if (kUndefined != wall) {
    AdjustWallOverlap(obstacle_entity_, wall);
    obstacle_entity_->HandleCollision(wall);
  }
  for (auto &ent : entities_) {
    if (ent == obstacle_entity_)continue;
    if (!IsColliding(obstacle_entity_, ent))continue;
    // Call the HandleCollision of obstacle to make necessary response
    obstacle_entity_->HandleCollision(ent->get_type(), ent);
    AdjustEntityOverlap(obstacle_entity_, ent);
    if (ent->get_type() == kBase) {
      continue;
    }
    if (ent->get_type() == kRobot) {
      Robot* temp_robot_refer = dynamic_cast<Robot*>(ent);
      temp_robot_refer->HandleCollision(obstacle_entity_->get_type(),
        obstacle_entity_);
      // Check if collided robot is dead
      if (temp_robot_refer->get_lives() == 0) {
        set_game_status(LOST);
      }
      temp_robot_refer = NULL;
    }
    if (ent->get_type() == kLights) {
      Lights* temp_obstacle_refer = dynamic_cast<Lights*>(ent);
      // Both obstacles will leave with already set arc
      temp_obstacle_refer->HandleCollision(obstacle_entity_->get_type(),
        obstacle_entity_);
      temp_obstacle_refer = NULL;
    }
  }
}

// Determine if the entity is colliding with a wall.
// Always returns an entity type. If not collision, returns kUndefined.
EntityType Arena::GetCollisionWall(ArenaMobileEntity *const ent) {
  if (ent->get_pose().x + ent->get_radius() >= x_dim_) {
    return kRightWall;  // at x = x_dim_
  } else if (ent->get_pose().x - ent->get_radius() <= 0) {
    return kLeftWall;  // at x = 0
  } else if (ent->get_pose().y + ent->get_radius() >= y_dim_) {
    return kBottomWall;  // at y = y_dim
  } else if (ent->get_pose().y - ent->get_radius() <= 0) {
    return kTopWall;  // at y = 0
  } else {
    return kUndefined;
  }
} /* GetCollisionWall() */

/* The entity type indicates which wall the entity is colliding with.
* This determines which way to move the entity to set it slightly off the wall. */
void Arena::AdjustWallOverlap(ArenaMobileEntity *const ent, EntityType object) {
  Pose entity_pos = ent->get_pose();
  switch (object) {
    case (kRightWall):  // at x = x_dim_
    ent->set_position(x_dim_-(ent->get_radius()+5), entity_pos.y);
    break;
    case (kLeftWall):  // at x = 0
    ent->set_position(ent->get_radius()+5, entity_pos.y);
    break;
    case (kTopWall):  // at y = 0
    ent->set_position(entity_pos.x, ent->get_radius()+5);
    break;
    case (kBottomWall):  // at y = y_dim_
    ent->set_position(entity_pos.x, y_dim_-(ent->get_radius()+5));
    break;
    default:
    {}
  }
}

/* Calculates the distance between the center points to determine overlap */
bool Arena::IsColliding(
  ArenaMobileEntity * const mobile_e,
  ArenaEntity * const other_e) {
    double delta_x = other_e->get_pose().x - mobile_e->get_pose().x;
    double delta_y = other_e->get_pose().y - mobile_e->get_pose().y;
    double distance_between =
    sqrt(delta_x*delta_x + delta_y*delta_y);
    double delta = distance_between -
    (mobile_e->get_radius() + other_e->get_radius());
    // Since for a minimum distance AdjustEntityOverlap
    // function can not help two collided entities recovered
    // A minimum interacted distance is set to avoid this mistake
    if (delta <= 0 && abs(delta) > 0.00000000001) {
       return true;
    }
    return false;
}

/* This is called when it is known that the two entities overlap.
* We determine by how much they overlap then move the mobile entity to
* the edge of the other
*/
/* @TODO: Add functionality to Pose to determine the distance distance_between two instances (e.g. overload operator -)
*/
/* @BUG: The robot will pass through the home base on occasion. The problem
 * is likely due to the adjustment being in the wrong direction. This could
 * be because the cos/sin generate the wrong sign of the distance_to_move
 * when the collision is in a specific quadrant relative to the center of the
 * colliding entities..
 */
void Arena::AdjustEntityOverlap(ArenaMobileEntity * const mobile_e,
  ArenaEntity *const other_e) {
    double delta_x = mobile_e->get_pose().x - other_e->get_pose().x;
    double delta_y = mobile_e->get_pose().y - other_e->get_pose().y;
    double distance_between = sqrt(delta_x*delta_x + delta_y*delta_y);
    double distance_to_move =
       mobile_e->get_radius() + other_e->get_radius() - distance_between + 5;
    double angle = atan2(delta_y, delta_x);
     mobile_e->set_position(
       mobile_e->get_pose().x+cos(angle)*distance_to_move,
       mobile_e->get_pose().y+sin(angle)*distance_to_move);
}

// Accept communication from the controller. Dispatching as appropriate.
/** @TODO: Call the appropriate Robot functions to implement user input
  * for controlling the robot.
  */
void Arena::AcceptCommand(Communication com) {
  switch (com) {
    case(kIncreaseSpeed):
    if (is_playing)
    // When this command received , the velocity of robot should be increased
    robot_->IncreaseSpeed();
    break;
    // When this command received , the velocity of robot should be decreased
    case(kDecreaseSpeed):
    if (is_playing)
    robot_->DecreaseSpeed();
    break;
    case(kTurnLeft):
    if (is_playing)
    robot_->TurnLeft();
    break;
    case(kTurnRight):
    if (is_playing)
    robot_->TurnRight();
    break;
    // if play button pressed , the game will be active
    case(kPlay):
    is_playing = true;
    break;
    // When pause button pressed, game will be paused
    case(kPause):
    is_playing = false;
    break;
    case(kReset):
    case(kNone):
    default: break;
  }
} /* AcceptCommand */

NAMESPACE_END(csci3081);
