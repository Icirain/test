### Feedback for Lab 04

Run on February 11, 23:50:31 PM.


#### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab04" exists.

+ Pass: Change into directory "labs/lab04".

+ Pass: Check that file "Makefile" exists.

+ Pass: Check that file "src/robot_land.cc" exists.

+ Pass: Check that file "src/robot_land.h" exists.

+ Pass: Check that file "src/robot_viewer.cc" exists.

+ Pass: Check that file "src/robot_viewer.h" exists.

+ Fail: Check that file "src/robot.cc" exists.

     "src/robot.cc" not found.

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
make: *** No rule to make target '../build/obj/src/robot.o'.  Stop.

```

+ Pass: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'

    make successful.
    Check build/bin/robotviewer exists...OK: result build/bin/robotviewer found

+ Fail: make 'all' in directory '.': expect result=build/bin/robotviewer, timeout=500, extra_args='CS3081DIR=/project/f17c3081'
    make finished compiling target=all, directory=. with errors:

```shell
In file included from main.cc:11:0:
../src/robot.h:1:0: error: unterminated #ifndef
 #ifndef LAB04_ROBOT_H_
 ^
make[1]: *** [../build/obj/src/main.o] Error 1
make: *** [proj01] Error 2

```

+ Fail: Run unit test 'build/bin/robotviewer', extra_args='', allowed_fails=0

Failed to create GLFW window


#### Google C++ Style

+ Fail: Cpplint checking for for Google C++ compliance

Done processing src/robot_land.cc
Done processing src/main.cc
Done processing src/robot_viewer.cc
Done processing src/robot.h
Done processing src/robot_land.h
Done processing src/robot_viewer.h
Total errors found: 12src/robot.h:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
src/robot.h:1:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_H_  [build/header_guard] [5]
src/robot.h:0:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_H_"  [build/header_guard] [5]
src/robot.h:5:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
src/robot.h:7:  Missing space before {  [whitespace/braces] [5]
src/robot.h:8:  public: should be indented +1 space inside class Robot  [whitespace/indent] [3]
src/robot.h:19:  private: should be indented +1 space inside class Robot  [whitespace/indent] [3]
src/robot.h:13:  Add #include <utility> for pair<>  [build/include_what_you_use] [4]
src/robot_land.h:7:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_LAND_H_  [build/header_guard] [5]
src/robot_land.h:174:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_LAND_H_"  [build/header_guard] [5]
src/robot_viewer.h:7:  #ifndef header guard has wrong style, please use: LABS_LAB04_SRC_ROBOT_VIEWER_H_  [build/header_guard] [5]
src/robot_viewer.h:230:  #endif line should be "#endif  // LABS_LAB04_SRC_ROBOT_VIEWER_H_"  [build/header_guard] [5]
