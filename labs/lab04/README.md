# Proof-of-Concept for the RobotSim project for 3081W

The base code for the robot simulator project of 3081W was born from this
proof-of-concept application written by Dan Keefe. There are 2 primary
components: the _robot_ _viewer_ and _robot_ _land_. Robots live in robot land
and are quite oblivious to being viewed by the viewer. The viewer is in control
of everything in that it sends a message to robot_land to update, meaning move
the robots the appropriate amount given how much time has passed since the last
update. It then gets the appropriate positional information from each robot and
draws these to the screen. All the while, the system is listening for keyboard
and mouse activity by the user. If any action occurs, the associated callback is
executed.

This should sound similar to the MVC paradigm that was presented in class,
although it is not an exact match (the project will be, however).

<hr>

## Mechanics of the System

### Resources

You will probably want to refer to these as you work on the lab.

- libMinGfx : https://github.com/ivlab/MinGfx
- nanogui : https://github.com/wjakob/nanogui
- nanogui documentation: https://nanogui.readthedocs.io/en/latest/
- nanovg : https://github.com/memononen/NanoVG
- Google Style Guide : https://google.github.io/styleguide/cppguide.html
- cpplint : https://github.com/google/styleguide/tree/gh-pages/cpplint

### libMinGfx and /project/f17c3081

The robot viewer is derived from `GraphicsApp` in MinGfx. When building the
simulator, the local object files are linked with libMinGfx located at
`/classes/csel-s18c3081`, which is publicly accessible on all cselabs
machines. If you want to compile on your own platform, you will have to create a
similar directory and change the makefile to reflect your local drive (i.e. edit
the `CS3081DIR` variable in src/Makefile to point to the directory where
libMinGfx has been installed.)

> **Do not submit to your repo any of the code from libMinGfx. Also, do
> not submit a Makefile in which you are linking to your personal local
> directory - it must refer to the cselabs directory.**

### Directory Structure

The directory structure for this lab is identical to that of the project.

- `Makefile`:
   - `make all` and `make clean` for the whole project (calls make recursively
     in subdirs).

- `src`:
  - All source code (.cc AND .h) lives under here. For this lab, that is
    robot_viewer.h/cc and robot_land.h/cc.

- `src/Makefile`:
  - You should *NOT* have to modify this makefile _EXCEPT_ for the `CS3081DIR`
    variable described above (both for this lab and the project).
  - Builds the project source, assumes it should build all .cc files in the
    current directory.
  - Creates the `build/bin/robotviewer` executable.
  - Uses g++ auto dependency generation to get dependencies from #includes in
    .cc files (So that you don't have to worry about this).

- `build`: Created by the Makefiles. Should be added to your `.gitignore`.
  - `build/bin`: All executables generated for the project will appear in here.
  - `build/obj`: all .o's and .d's (from make depend) go in here.

<hr>

## Getting Started

1. _pull_ the class repo.

2. `cp` the lab to your personal repo.

3. If you are working from your local machine, modify the `CS3081DIR` variable
   in `src/Makefile` so that it points to your local installation of
   libMinGfx. Ignore this step if working on a CSE labs machine.

4. At the top level from the OS command prompt: `make`. You can add `-j` if you
   are impatient like I am and want things to compile really fast.

   If you have trouble compiling, it might be that your account is behind on the
   gcc version. At the prompt, type `gcc --version` and if it says 4.x, you need
   to load gcc:

        module unload gcc
        module load /soft/gcc/7.1

   or if that does not work, you can try the nuclear option:

        resetenv

  Note that this will reset any .bashrc, .screenrc, etc. config that you may
  have had in place (not delete, but move to a backup directory).


5. At command prompt: `./build/bin/robotviewer`

6. Verify that you can run the Google C++ linter, `cpplint.py`. It is installed
   on the lab machines already, so nothing needs to be done if you are working
   from one of those. If you are on your own machine, you will need to download
   and install it (see above). Verify that it works by doing:

        /path/to/cpplint.py --help

   If you see output, then it is working.

<hr>

## Code Explanation

### class GraphicsApp

The GraphicsApp makes use of the nanogui, nanovg, and openGL libraries to create
a window with 2D graphics and a GUI. As with most graphics applications, there
is a main loop in which keyboard and mouse events are handled, then all objects
in the graphics window are drawn. The loop is executed at the frame rate until
the application is closed. The actual loop is in the Run method of GraphicsApp with
logic something like this:

```C++
while (Active(window)) {  // ie user has not clicked 'x' to close the window
   handleKeyMouseEvents();
   clearScreen()   // start with a fresh screen/buffer
   drawContents();
   swapBuffers(window);    // double-buffered system
}
```

Once that main loop is initiated, GraphicsApp::draw() will
be called. Notice the **two very important function calls `UpdateSimulation()`
and `DrawUsingNanoVG()`**.

```C++
void GraphicsApp::draw(NVGcontext *ctx) {

double now = glfwGetTime();
UpdateSimulation(now - last_draw_time_);
last_draw_time_ = now;

// Draw the user interface using the nanogui library, which is built upon nanovg
Screen::draw(ctx);

// Draw other vector graphics using the nanovg library
DrawUsingNanoVG(ctx);
}
```

### class RobotViewer in robot_viewer.h / .cc

RobotViewer is a subclass of GraphicsApp. In this application, it is
instantiated in main() with the name _app_. Notice in the constructor of
RobotViewer, you see the instantiation of `RobotLand`. The simulator gets
started with a call to app->Run(), which enters the loop discussed above:

```C++
int main(int argc, char **argv) {
   csci3081::RobotViewer \*app = new csci3081::RobotViewer();
   app->Run();
   return 0;
}
```

Recall that in the Run() function of the GraphicsApp, there is a call to
UpdateSimulation() and DrawUsingNanoVG(). **Look at these function definitions
in _robot\_viewer.cc._** All that is happening in Update is a call to robot land
to update based on how much time has passed. In the draw function, each object
of robot land is being drawn. Notice that the graphics commands for drawing each
of the objects begins with `nvg` for nanovg. The header file
`https://github.com/memononen/nanovg/blob/master/src/nanovg.h` is pretty well
documented. Take a moment to look at this header file and read about some of the
function calls that you see in drawing the various graphics objects
(e.g. DrawRobot, DrawObstacle).

(The keyboard and mouse event processing is discussed below.)

### class RobotLand

This is the View part of the MVC framework.

RobotLand has no awareness of robot viewer, despite the fact that it was
instantiated inside of robot viewer. You can think about robots in RobotLand
constantly moving around (even though they move in discrete steps), but
periodically the robot viewer takes a snapshot of the situation and displays it
on the screen. RobotViewer interacts with RobotLand through getters, which get
information from each robot and each obstacle that is relevant to drawing them
in the graphics window.

Currently, RobotLand consists of one stationary obstacle and two robots going
around in circles. No robot class exists, but if it did, it would consist of a
position, velocity, color, and size. The color and size is fixed. The position
and velocity are determined by the circular pattern they are following. A call
to circle_x() and circle_y() with a time value will generate the current
position of the robot. Notice that the RobotLand::advance_time() sets the
current time of the simulation. When the robot viewer needs to draw the objects,
circle_x and circle_y are called to calculate and return the current position of
the robot.

### Keyboard and Mouse Event Handling

Events are handled inside robot viewer, because this manages all aspects of the
GUI. Look in robot_viewer.cc to see the various events to be handled
(e.g. OnKeyDown(), which handles the down arrow key). The name gives an
indication of which event it is responding to. When that event occurs, this is
the function that is called. You never see the call to this function, but know
that it does happen. Currently, for the most part, events are handled by
printing messages to a terminal, but they really come in handy when you want the
user to interact with the graphics window. For example, you might want the
functionality that wherever the user clicks the mouse, a robot is created at
that position.

The menu you see in the application with a reset and pause button was a custom
menu made for this application. If you downloaded the nanogui examples, you saw
how complex these menus can be. It is quite easy to add buttons with various
functionality to the menu. Let's trace that process through the code ...

It starts in the RobotViewer constructor:

```C++
nanogui::FormHelper *gui = new nanogui::FormHelper(screen());

nanogui::ref<nanogui::Window> window =
   gui->addWindow(Eigen::Vector2i(10, 10), "Simulation Controls");
pause_btn_ =
   gui->addButton("Pause", std::bind(&RobotViewer::OnPauseBtnPressed, this));
gui->addButton("Restart", std::bind(&RobotViewer::OnRestartBtnPressed, this));
```

You start with the instantiation of FormHelper, then add the various
components. The parameters being passed to the `addButton` are the name that
appears on the button and the _callback_ function, meaning the one that is
called when the button is pressed (which is registered via a mouse
click). Again, all of this is going on behind the scenes and you will not see an
explicit call to the callback function.

Next, look at each of the functions passed to the "Restart" and "Pause" buttons:

```C++
void RobotViewer::OnRestartBtnPressed() {
   robot_land_->set_time(0.0); }

void RobotViewer::OnPauseBtnPressed() {
   paused_ = !paused_;
   if (paused_) {
   pause_btn_->setCaption("Play");
   } else {
   pause_btn_->setCaption("Pause");
   }
}
```

At this point, you should have a general understanding of the framework for the
graphics application. If you are really not understanding it, read through again
or talk to a peer.

Seriously, do it. The project works in the same way, and is MUCH larger, so you
should try to have a good handle on the basic flow before continuing with this
lab, and eventually the project.

> Notice the special form of the comments. They are following doxygen
> formatting, which when compiled for doxygen, generates the documentation in
> the form of a pdf or web pages.

<hr>

## Your Assignment

1. Add a robot class to the application. Define the robot class in the 2 files
   _robot.h_ and _robot.cc_. Use the robot class to save the size, color,
   position, and velocity. The Robot class should have the following interface:

```C++
Robot(double radius, double x, double y);
double radius(void) const;
void radius(double);

std::pair<double, double> position(void) const;
void position(std::pair<double, double> pos);

double velocity(void) const;
void velocity(double); // Set robot velocity.
double heading_angle(void) const;
void heading_angle(double); // Set heading angle for robot.
void UpdatePosition(double dt); // Updates robot position after dt timesteps to move in a circle

```
   - Modify the position and velocity of each robot when time is advanced.
   - Instantiate 2 robots as members of the class RobotLand when RobotLand is
     instantiated (i.e. use composition).

> RECOMMENDATION: Create your robot class and test its functionality before
> trying to incorporate it into the graphics application. To test your robot
> class, create an instance of the class then use setters and getters to check
> that the member variables and methods are working properly. You can
> instantiate your robot temporarily in main(), commenting out the
> graphics. Then **gradually** incorporate the functionality of the robot class
> into the graphics.

2. Add a button to the GUI to change the color of a robot - either robot.
   - Create an OnColorChangeBtnPressed() function that changes a robot color in
     the RobotViewer class.
   - Create a new nanogui button in the RobotViewer constructor, binding its
     click action to the function you just created (look at the other buttons in
     the constructor for examples of how to do this).

> Show your lab TA this before continuing.

3. For this lab, and the project, we will be following the Google C++ style
   guide. As such, all code is expected to pass the Google linter, `cpplint.py`.
   `cpplint.py` is already installed on all the lab machines (if you are on your
   own machine you will need to download it and put it somewhere). Run the
   linter with:

        cpplint.py *.h *.cc

   Fix anything that the linter flags. If something it flags seems dumb/does not
   make sense ask a TA--Google has very good reasons for their preferred
   style. You may not agree with them, but they are well thought out (see their
   C++ style guide for full details) from a practical/coding standpoint.

4. If you get this far, do something for fun! Maybe you want to ...
   - Add a different kind of object.
   - Move the robot in a different pattern.
   - Have the robot bounce off of other objects.
   - Add more functionality to the GUI by adding more buttons.
