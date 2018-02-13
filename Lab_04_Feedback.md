### Feedback for Lab 04

Run on February 12, 21:06:20 PM.


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
In file included from robot.cc:2:0:
robot.h:8:16: error: expected constructor, destructor, or type conversion before ‘(’ token
 NAMESPACE_BEGIN(csci3081);
                ^
robot.h:35:14: error: expected constructor, destructor, or type conversion before ‘(’ token
 NAMESPACE_END(csci3081);
              ^
robot.cc:6:16: error: expected constructor, destructor, or type conversion before ‘(’ token
 NAMESPACE_BEGIN(csci3081);
                ^
make: *** [../build/obj/src/robot.o] Error 1

```

+ Fail: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'
    make finished compiling target=all, directory=. with errors:

```shell
In file included from ../src/robot_land.h:15:0,
                 from robot_land.cc:10:
../src/robot.h:8:16: error: expected constructor, destructor, or type conversion before ‘(’ token
 NAMESPACE_BEGIN(csci3081);
                ^
../src/robot.h:35:14: error: expected constructor, destructor, or type conversion before ‘(’ token
 NAMESPACE_END(csci3081);
              ^
In file included from robot_land.cc:10:0:
../src/robot_land.h:173:3: error: ‘csci3081’ does not name a type
   csci3081::Robot* test1 = new csci3081::Robot(40, 512, 350);
   ^
../src/robot_land.h:174:3: error: ‘csci3081’ does not name a type
   csci3081::Robot* test2 = new csci3081::Robot(100, 512, 350);
   ^
robot_land.cc: In member function ‘bool RobotLand::get_robot_pos(int, double*, double*)’:
robot_land.cc:24:5: error: ‘test1’ was not declared in this scope
     test1->UpdatePosition(sim_time_);
     ^
robot_land.cc: In member function ‘bool RobotLand::get_robot_vel(int, double*, double*)’:
robot_land.cc:47:23: error: ‘test1’ was not declared in this scope
     double velocity = test1->velocity();
                       ^
make[1]: *** [../build/obj/src/robot_land.o] Error 1
make: *** [proj01] Error 2

```

+ Fail: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'
    make finished compiling target=all, directory=. with errors:

```shell
In file included from ../src/robot_land.h:15:0,
                 from robot_land.cc:10:
../src/robot.h:8:16: error: expected constructor, destructor, or type conversion before ‘(’ token
 NAMESPACE_BEGIN(csci3081);
                ^
../src/robot.h:35:14: error: expected constructor, destructor, or type conversion before ‘(’ token
 NAMESPACE_END(csci3081);
              ^
In file included from robot_land.cc:10:0:
../src/robot_land.h:173:3: error: ‘csci3081’ does not name a type
   csci3081::Robot* test1 = new csci3081::Robot(40, 512, 350);
   ^
../src/robot_land.h:174:3: error: ‘csci3081’ does not name a type
   csci3081::Robot* test2 = new csci3081::Robot(100, 512, 350);
   ^
robot_land.cc: In member function ‘bool RobotLand::get_robot_pos(int, double*, double*)’:
robot_land.cc:24:5: error: ‘test1’ was not declared in this scope
     test1->UpdatePosition(sim_time_);
     ^
robot_land.cc: In member function ‘bool RobotLand::get_robot_vel(int, double*, double*)’:
robot_land.cc:47:23: error: ‘test1’ was not declared in this scope
     double velocity = test1->velocity();
                       ^
make[1]: *** [../build/obj/src/robot_land.o] Error 1
make: *** [proj01] Error 2

```

+ Fail: Run unit test 'build/bin/robotviewer', extra_args='', allowed_fails=0

./build/bin/robotviewer: error while loading shared libraries: libnanogui.so: cannot open shared object file: No such file or directory


#### Google C++ Style

+ Fail: Cpplint checking for for Google C++ compliance

Done processing src/robot.cc
Done processing src/robot_viewer.cc
Done processing src/main.cc
Done processing src/robot_land.cc
Done processing src/robot.h
Done processing src/robot_land.h
Done processing src/robot_viewer.h
Total errors found: 42src/robot.cc:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
src/robot.cc:2:  Include the directory when naming .h files  [build/include] [4]
src/robot.cc:3:  Found C++ system header after other header. Should be: robot.h, c system, c++ system, other.  [build/include_order] [4]
src/robot.cc:4:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.cc:11:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
src/robot.cc:11:  Missing space after ,  [whitespace/comma] [3]
src/robot.cc:12:  { should almost always be at the end of the previous line  [whitespace/braces] [4]
src/robot.cc:13:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
src/robot.cc:13:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
src/robot.cc:16:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:20:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:24:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:25:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:26:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:27:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:28:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:31:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:36:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:37:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:40:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:44:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:48:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:49:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:52:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:65:  Should have a space between // and comment  [whitespace/comments] [4]
src/robot.cc:66:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
src/robot.cc:68:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:72:  Extra space before last semicolon. If this should be an empty statement, use {} instead.  [whitespace/semicolon] [5]
src/robot.cc:69:  Add #include <utility> for pair<>  [build/include_what_you_use] [4]
src/robot.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
src/robot.h:1:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_H_  [build/header_guard] [5]
src/robot.h:38:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_H_"  [build/header_guard] [5]
src/robot.h:6:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.h:11:  private: should be indented +1 space inside class Robot  [whitespace/indent] [3]
src/robot.h:19:  public: should be indented +1 space inside class Robot  [whitespace/indent] [3]
src/robot.h:32:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
src/robot.h:24:  Add #include <utility> for pair<>  [build/include_what_you_use] [4]
src/robot_land.h:7:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_LAND_H_  [build/header_guard] [5]
src/robot_land.h:177:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_LAND_H_"  [build/header_guard] [5]
src/robot_land.h:15:  Include the directory when naming .h files  [build/include] [4]
src/robot_viewer.h:7:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_VIEWER_H_  [build/header_guard] [5]
src/robot_viewer.h:232:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_VIEWER_H_"  [build/header_guard] [5]

