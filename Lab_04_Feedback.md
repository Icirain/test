### Feedback for Lab 04

Run on February 12, 14:10:42 PM.


#### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab04" exists.

+ Pass: Change into directory "labs/lab04".

+ Pass: Check that file "Makefile" exists.

+ Pass: Check that file "src/robot_land.cc" exists.

+ Pass: Check that file "src/robot_land.h" exists.

+ Pass: Check that file "src/robot_viewer.cc" exists.

+ Pass: Check that file "src/robot_viewer.h" exists.

+ Pass: Check that file "src/robot.cc" exists.

+ Pass: Check that file "src/robot.h" exists.


#### .gitignore configured properly

+ Fail: Check that file/directory "build/bin/robotviewer" does not exist.

     "build/bin/robotviewer" found.

+ Pass: Check that no files with extension ".o" exist in directory "."

+ Pass: Check that no files with extension ".d" exist in directory "."


#### make all functional

+ Fail: make '../build/obj/src/robot.o' in directory 'src': expect result=build/obj/src/robot.o, timeout=500, extra_args='CS3081DIR=/project/f17c3081'
    make finished compiling target=../build/obj/src/robot.o, directory=src with errors:

```shell
robot.cc: In constructor ‘Robot::Robot(double, double, double)’:
robot.cc:6:47: error: declaration of ‘y’ shadows a member of ‘Robot’ [-Werror=shadow]
 Robot::Robot(double radius, double x, double y){
                                               ^
In file included from robot.cc:2:0:
robot.h:21:15: note: shadowed declaration is here
        double y;
               ^
robot.cc:6:47: error: declaration of ‘x’ shadows a member of ‘Robot’ [-Werror=shadow]
 Robot::Robot(double radius, double x, double y){
                                               ^
In file included from robot.cc:2:0:
robot.h:20:15: note: shadowed declaration is here
        double x;
               ^
robot.cc:6:1: error: ‘Robot::x’ should be initialized in the member initialization list [-Werror=effc++]
 Robot::Robot(double radius, double x, double y){
 ^
robot.cc:6:1: error: ‘Robot::y’ should be initialized in the member initialization list [-Werror=effc++]
robot.cc:6:1: error: ‘Robot::radius_’ should be initialized in the member initialization list [-Werror=effc++]
robot.cc:6:1: error: ‘Robot::velocity_’ should be initialized in the member initialization list [-Werror=effc++]
robot.cc:6:1: error: ‘Robot::angle_’ should be initialized in the member initialization list [-Werror=effc++]
cc1plus: all warnings being treated as errors
make: *** [../build/obj/src/robot.o] Error 1

```

+ Fail: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'
    make finished compiling target=all, directory=. with errors:

```shell
robot.cc: In constructor ‘Robot::Robot(double, double, double)’:
robot.cc:6:47: error: declaration of ‘y’ shadows a member of ‘Robot’ [-Werror=shadow]
 Robot::Robot(double radius, double x, double y){
                                               ^
In file included from robot.cc:2:0:
robot.h:21:15: note: shadowed declaration is here
        double y;
               ^
robot.cc:6:47: error: declaration of ‘x’ shadows a member of ‘Robot’ [-Werror=shadow]
 Robot::Robot(double radius, double x, double y){
                                               ^
In file included from robot.cc:2:0:
robot.h:20:15: note: shadowed declaration is here
        double x;
               ^
robot.cc:6:1: error: ‘Robot::x’ should be initialized in the member initialization list [-Werror=effc++]
 Robot::Robot(double radius, double x, double y){
 ^
robot.cc:6:1: error: ‘Robot::y’ should be initialized in the member initialization list [-Werror=effc++]
robot.cc:6:1: error: ‘Robot::radius_’ should be initialized in the member initialization list [-Werror=effc++]
robot.cc:6:1: error: ‘Robot::velocity_’ should be initialized in the member initialization list [-Werror=effc++]
robot.cc:6:1: error: ‘Robot::angle_’ should be initialized in the member initialization list [-Werror=effc++]
cc1plus: all warnings being treated as errors
make[1]: *** [../build/obj/src/robot.o] Error 1
make: *** [proj01] Error 2

```

+ Fail: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'
    make finished compiling target=all, directory=. with errors:

```shell
main.cc: In function ‘int main(int, char**)’:
main.cc:17:3: error: ‘Robot’ is not a member of ‘csci3081’
   csci3081::Robot r(10, 100, 100);
   ^
main.cc:17:3: note: suggested alternative:
In file included from main.cc:11:0:
../src/robot.h:7:7: note:   ‘Robot’
 class Robot{
       ^
In file included from /usr/include/c++/5/cassert:43:0,
                 from /project/f17c3081/include/nanogui/formhelper.h:25,
                 from /project/f17c3081/include/nanogui/nanogui.h:37,
                 from /project/f17c3081/include/MinGfx-1.0/graphics_app.h:18,
                 from /project/f17c3081/include/MinGfx-1.0/mingfx.h:23,
                 from ../src/robot_viewer.h:13,
                 from main.cc:10:
main.cc:19:33: error: ‘r’ was not declared in this scope
   assert(10 == static_cast<int>(r.radius()));
                                 ^
make[1]: *** [../build/obj/src/main.o] Error 1
make: *** [proj01] Error 2

```

+ Fail: Run unit test 'build/bin/robotviewer', extra_args='', allowed_fails=0

./build/bin/robotviewer: error while loading shared libraries: libnanogui.so: cannot open shared object file: No such file or directory


#### Google C++ Style

+ Fail: Cpplint checking for for Google C++ compliance

Done processing src/main.cc
Done processing src/robot.cc
Done processing src/robot_land.cc
Done processing src/robot_viewer.cc
Done processing src/robot_land.h
Done processing src/robot.h
Done processing src/robot_viewer.h
Total errors found: 37src/robot.cc:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
src/robot.cc:2:  Include the directory when naming .h files  [build/include] [4]
src/robot.cc:3:  Found C++ system header after other header. Should be: robot.h, c system, c++ system, other.  [build/include_order] [4]
src/robot.cc:4:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.cc:6:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:7:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:8:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:9:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:12:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:16:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:20:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:21:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:22:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:23:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:24:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:27:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:32:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:33:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:36:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:40:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:44:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:45:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:48:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:49:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:50:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:27:  Add #include <utility> for pair<>  [build/include_what_you_use] [4]
src/robot_land.h:7:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_LAND_H_  [build/header_guard] [5]
src/robot_land.h:174:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_LAND_H_"  [build/header_guard] [5]
src/robot.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
src/robot.h:1:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_H_  [build/header_guard] [5]
src/robot.h:27:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_H_"  [build/header_guard] [5]
src/robot.h:5:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.h:8:  public: should be indented +1 space inside class Robot  [whitespace/indent] [3]
src/robot.h:19:  private: should be indented +1 space inside class Robot  [whitespace/indent] [3]
src/robot.h:13:  Add #include <utility> for pair<>  [build/include_what_you_use] [4]
src/robot_viewer.h:7:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_VIEWER_H_  [build/header_guard] [5]
src/robot_viewer.h:230:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_VIEWER_H_"  [build/header_guard] [5]

