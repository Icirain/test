/**
 * @file obstacle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/*! Basically , at every this robot game initiated, one robot,
 *three bases with fixed size and 4 obstacles with varied size
 *will be placed in an area surrounded by white line,
 *which is the boundaries of this area. Basically this game
 *are built with a standard MVC style which contains model,
 *view and controller.
 *Viewer is the part of code which has a update function
 *repeatedly called behind to draw the whole graphic part of this game.
 *Arena is the backend model which records the status like
 *velocity, position and if_captured for base.
 *All of these data is stored in an instance of arena
 *class implemented in arena.h & arena.cc.
 *The instances of robot,
 *bases and obstacles are the composition of
 *arena so that arena
 *has access to all of their data and able to
 *modify them if necessary.
 *
 *To implement the communication between viewer and arena(model), functionality
 *of controller is implemented mainly in controller.cc and controller.cc. When
 *some activity in the viewer model activated like buttion pressed, if will be
 *sent to controller immediately and finally forwarded to arena finally. In our
 *code the instance of viewer and arena is the private variable in controller,
 *which enables controller to send communication code to arena with function
 *“AcceptCommunication()” inside arena. For example when button in the viewer
 *called the relative communication code will be sent to controller and
 *controller will forward it to arena to produce necessary response,
 *which is the base stone of our game’s interaction mechanism.
 *
 *To control the robot’s velocity and direction,
 *we use arrow key to do that. When any arrow key
 *pressed , the viewer’ call back function will be
 *called and relative communication, which is listed
 *in communication.h, will be sent to controller and
 *finally to the arena. For instance when up arrow
 *key pressed, the velocity of robot inside arena
 *will be increased and vice versa. Arrow key of
 *left and right is to control the direction of
 *robot which will lead to different velocity on
 *two sides of robot. With same logic , the functionality
 *of new game, pause& play are implemented. When button,
 *corresponding communication will be forwarded to arena through controller.
 *
 *For the play&pause funtionality, when button pressed.
 *A variable of arena will be modified between true and
 *false whose name is is_playing. If is_playing is true
 *the regulated time interaction named dt will be passed
 *to AdvanceTIme() function in arena which drives the update
 *of all the instances in arena. But if pause button pressed
 *in viewer, AdvanceTime function will stopped ahead of the
 *update happening to implement the pause of whole game.
 *Graphically all stuff in the playing area will keep not
 *moving in paused status. And for new game functionality.
 *When this button named “New Game” pressed, in the
 *graphics_arena_viewer.cc, the old arena instance
 *inside viewer will be deleted and a new one will
 *be created. And the communication code “kNewGame”
 *will be sent to controller and the new arena instance
 *will be redirected inside controller to prevent segment
 *fault.
 *
 *In fixed time period dt , the game is proceeding
 *and the viewer will be updated in every dt. And
 *collision is the major functionality implemented
 *in this iteration. For two kinds of mobile entity
 *obstacle and robot. Whenever the robot collision
 *happens, in the funtion HandleCollision, the lives
 *will be deducted and speed will be set to 0. For
 *obstacle, it will reverse direction and finish an
 *arc to avoid double collison. For the whole game
 *rule, the player needs to control the speed and
 *direction of robot to capture all 3 bases before
 *losing all lives. Whenver the lives is 0 or all bases
 *captured the game will end up. Player needs to press
 *new game button to restart a new game. And in the
 *control area the status of game is descripted and updated.

 *Have fun with this game!
 */
#endif  // SRC_MAINPAGE_H_

/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 */
