/**
 * @file controller.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>

#include "src/arena_params.h"
#include "src/common.h"
#include "src/controller.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

Controller::Controller() : last_dt(0) {
  // Initialize default properties for various arena entities
  arena_params aparams;
  aparams.n_obstacles = N_OBSTACLES;
  aparams.x_dim = ARENA_X_DIM;
  aparams.y_dim = ARENA_Y_DIM;

  arena_ = new Arena(&aparams);

  // Start up the graphics (which creates the arena).
  // Run() will enter the nanogui::mainloop().
  viewer_ = new GraphicsArenaViewer(&aparams, arena_, this);
}

void Controller::Run() { viewer_->Run(); }

void Controller::AdvanceTime(double dt) {
  if ((last_dt + dt) <= .05) {
    last_dt += dt;
    return;
  }
  last_dt = 0;
  arena_->AdvanceTime(dt);
}

void Controller::AcceptCommunication(Communication com) {
  if (com == kNewGame) {
    arena_ = viewer_ -> GetNewArenaAddress();
    return;
  }
  arena_->AcceptCommand(ConvertComm(com));
}

/** Converts communication from one source to appropriate communication to
 * the other source. For example, the viewer sends a kKeyUp communication,
 * and this translate to a kIncreaseSpeed communication to Arena.
 */
/**
  * @TODO: Complete the conversion code for all key presses.
  */
Communication Controller::ConvertComm(Communication com) {
  Communication command_to_arena;
  switch (com) {
    case (kKeyUp) :
      command_to_arena = kIncreaseSpeed;
      break;
    case (kKeyDown) :
      command_to_arena = kDecreaseSpeed;
      break;
    case (kKeyLeft) :
      command_to_arena = kTurnLeft;
      break;
    case (kKeyRight) :
      command_to_arena = kTurnRight;
      break;
    case (kPlay) :
      command_to_arena = kPlay;
      break;
    case (kPause) :
      command_to_arena = kPause;
      break;
    case (kNewGame) :
    default: return kNone;
  }
  return command_to_arena;
}

NAMESPACE_END(csci3081);
