### Feedback for Lab 04

Run on February 12, 20:11:19 PM.


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

+ Pass: make '../build/obj/src/robot.o' in directory 'src': expect result=build/obj/src/robot.o, timeout=500, extra_args='CS3081DIR=/project/f17c3081'

    make successful.
    Check build/obj/src/robot.o exists...OK: result build/obj/src/robot.o found

+ Pass: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'

    make successful.
    Check build/bin/robotviewer exists...OK: result build/bin/robotviewer found

+ Fail: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'
    make finished compiling target=all, directory=. with errors:

```shell
main.cc: In function ‘int main(int, char**)’:
main.cc:17:3: error: ‘Robot’ is not a member of ‘csci3081’
   csci3081::Robot r(10, 100, 100);
   ^
main.cc:17:3: note: suggested alternative:
In file included from ../src/robot_land.h:15:0,
                 from ../src/robot_viewer.h:14,
                 from main.cc:10:
../src/robot.h:8:7: note:   ‘Robot’
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

Failed to create GLFW window


#### Google C++ Style

+ Fail: Cpplint checking for for Google C++ compliance

Done processing src/robot.cc
Done processing src/main.cc
Done processing src/robot_land.cc
Done processing src/robot_viewer.cc
Done processing src/robot_viewer.h
Done processing src/robot.h
Done processing src/robot_land.h
Total errors found: 42src/robot.cc:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
src/robot.cc:2:  Include the directory when naming .h files  [build/include] [4]
src/robot.cc:3:  Found C++ system header after other header. Should be: robot.h, c system, c++ system, other.  [build/include_order] [4]
src/robot.cc:6:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.cc:9:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
src/robot.cc:9:  Missing space after ,  [whitespace/comma] [3]
src/robot.cc:10:  { should almost always be at the end of the previous line  [whitespace/braces] [4]
src/robot.cc:11:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
src/robot.cc:11:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
src/robot.cc:14:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:18:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:22:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:23:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:24:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:25:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:26:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:29:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:34:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:35:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:38:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:42:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:46:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:47:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/robot.cc:50:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:63:  Should have a space between // and comment  [whitespace/comments] [4]
src/robot.cc:64:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
src/robot.cc:66:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:70:  Extra space before last semicolon. If this should be an empty statement, use {} instead.  [whitespace/semicolon] [5]
src/robot.cc:67:  Add #include <utility> for pair<>  [build/include_what_you_use] [4]
src/robot_viewer.h:7:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_VIEWER_H_  [build/header_guard] [5]
src/robot_viewer.h:230:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_VIEWER_H_"  [build/header_guard] [5]
src/robot.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
src/robot.h:1:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_H_  [build/header_guard] [5]
src/robot.h:35:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_H_"  [build/header_guard] [5]
src/robot.h:5:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.h:9:  private: should be indented +1 space inside class Robot  [whitespace/indent] [3]
src/robot.h:17:  public: should be indented +1 space inside class Robot  [whitespace/indent] [3]
src/robot.h:30:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
src/robot.h:22:  Add #include <utility> for pair<>  [build/include_what_you_use] [4]
src/robot_land.h:7:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_LAND_H_  [build/header_guard] [5]
src/robot_land.h:177:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_LAND_H_"  [build/header_guard] [5]
src/robot_land.h:15:  Include the directory when naming .h files  [build/include] [4]

