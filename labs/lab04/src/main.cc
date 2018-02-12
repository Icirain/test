/**
 * @file main.cc
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
//#include "src/robot_viewer.h"
#include <iostream>
#include "robot.h"

using namespace std;
using std::cout;
using std::endl;
/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int argc, char **argv) {
  // RobotViewer is a subclass of GraphicsApp, found in libSimpleGraphics
  // Run() is a function defined in the GraphicsApp class definition.
  // Run() calls nanogui::mainloop().
 // csci3081::RobotViewer *app = new csci3081::RobotViewer();
  //app->Run();
  //return 0;

  Robot* test = new Robot(1.0, 2.0, 2.0);
  test->radius(2.0);
  std::pair<double, double> pos = test->position();
  test->velocity(4.9);
  test->heading_angle(2.7);
  cout<< test->velocity() <<"pos is "<<pos.first<<pos.second<<"angle is "<<
     test->heading_angle()<<endl;




}
