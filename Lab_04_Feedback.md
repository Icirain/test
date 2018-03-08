### Feedback for Lab 04

Run on March 08, 00:22:53 AM.


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

+ Pass: Check that file/directory "build/bin/robotviewer" does not exist.

+ Pass: Check that no files with extension ".o" exist in directory "."

+ Pass: Check that no files with extension ".d" exist in directory "."


#### make all functional

+ Pass: make '../build/obj/src/robot.o' in directory 'src': expect result=build/obj/src/robot.o, timeout=500, extra_args='CS3081DIR=/project/f17c3081'

    make successful.
    Check build/obj/src/robot.o exists...OK: result build/obj/src/robot.o found

+ Pass: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'

    make successful.
    Check build/bin/robotviewer exists...OK: result build/bin/robotviewer found

+ Pass: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'

    make successful.
    Check build/bin/robotviewer exists...OK: result build/bin/robotviewer found

+ Fail: Run unit test 'build/bin/robotviewer', extra_args='', allowed_fails=0


#### Google C++ Style

+ Fail: Cpplint checking for for Google C++ compliance

Done processing src/robot_land.cc
Done processing src/main.cc
Done processing src/robot_viewer.cc
Done processing src/robot.cc
Done processing src/robot_viewer.h
Done processing src/obstacle.h
Done processing src/robot.h
Done processing src/robot_land.h
Total errors found: 21src/robot_viewer.cc:34:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
src/robot_viewer.cc:68:  Missing space before {  [whitespace/braces] [5]
src/robot.cc:7:  Include the directory when naming .h files  [build/include] [4]
src/robot.cc:8:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.cc:76:  At least two spaces is best between code and comments  [whitespace/comments] [2]
src/obstacle.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
src/obstacle.h:0:  No #ifndef header guard found, suggested CPP variable is: SRC_OBSTACLE_H_  [build/header_guard] [5]
src/obstacle.h:2:  public: should be indented +1 space inside class Obstacle  [whitespace/indent] [3]
src/obstacle.h:3:  Missing space after ,  [whitespace/comma] [3]
src/obstacle.h:5:  Missing space after ,  [whitespace/comma] [3]
src/obstacle.h:6:  private: should be indented +1 space inside class Obstacle  [whitespace/indent] [3]
src/obstacle.h:7:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/obstacle.h:8:  Weird number of spaces at line-start.  Are you using a 2-space indent?  [whitespace/indent] [3]
src/obstacle.h:8:  Add #include <utility> for pair<>  [build/include_what_you_use] [4]
src/robot.h:5:  #ifndef header guard has wrong style, please use: SRC_ROBOT_H_  [build/header_guard] [5]
src/robot.h:41:  #endif line should be "#endif  // SRC_ROBOT_H_"  [build/header_guard] [5]
src/robot.h:11:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.h:37:  At least two spaces is best between code and comments  [whitespace/comments] [2]
src/robot_land.h:7:  #ifndef header guard has wrong style, please use: SRC_ROBOT_LAND_H_  [build/header_guard] [5]
src/robot_land.h:177:  #endif line should be "#endif  // SRC_ROBOT_LAND_H_"  [build/header_guard] [5]
src/robot_land.h:15:  Include the directory when naming .h files  [build/include] [4]

