## Lab 5 - Google Style Guide Compliance and Doxygen

**REMEMBER TO SIGN IN TODAY!!!**

**NOTE:** As you have experienced, the feedback from the gitbot has been very unstable. 
We will continue to work with systems to get it reliably working. 
When we think it is stable, we will send out an announcement. Having feedback before you
submit is a luxury. You have been turning in assignments for years without knowing
ahead of time how well you did -- and you did great, otherwise you wouldn't be here in 
college. Check your work and confirm you have met the requirements.

#### Requirements:
- Use cpplint to find then fix Google Style errors.
- Confirm the code is Google style compliant with respect to naming conventions.
- Add an Object class.
- Create a mainpage.
- Run doxygen and look over the html pages.
- Don't push your html.
- And again, use cpplint to find (and fix) Style errors.

### Part 1 - Google Style Compliance: Linting

https://google.github.io/styleguide/cppguide.html

A style guide sets guidelines for how files, classes, functions, and variables
should be named. It also sets guidelines for white space, line lengths, and
commenting within the code. By standardizing naming conventions and layout, it
is easier to integrate code from various programmers in a cohesive way that
is readable and understandable by everyone. Going forward, all code submitted
for this course must be compliant with the Google Style Guide. As stated before,
not everyone is going to agree on every Style aesthetically, but it is important to have
a standard that everyone programs to.

The code provided for this lab is mostly Google style compliant. There are still
a few compliance errors in a couple of files that you must fix.

To fix the errors, you will first need to identify them with _cpplint_. The
_cpplint.py_ file is available on CSE labs machines. To run the linter on your
code, navigate to the _src_ directory and do the following:

```
cpplint.py --root=.. *.h
cpplint.py *.cc
```
Invoking the linter on the headers and source files separately is not required,
but when you first start, if there are a lot of errors then you won't have to
scroll back up through screenfulls of text to see where they are. For all-in-one
do:

```
cpplint.py --root=.. *.h *.cc
```

Header guards must always be in place for header files. During compilation,
particularly when you have circular references in your code, a header file might
be included multiple times from multiple header files. If you have already
included the header during compilation, you don't want the compiler to include
it again, thus you are _guarding_ against including it multiple times (possibly
infinite if circular references exist). Google Style states that header guards
should use the full path to that file (e.g. `PROJECT_ITERATION1_SRC_ROBOT_H_`),
but for this class we are going to include only from the point of the _src_
directory. The _--root_ flag allows us to specify where in the path to start,
thus the header guard for _Robot.h_ will be `SRC_ROBOT_H`.

When you run the linter, you should get a report of each error that includes the
file, line number, and a short description of the problem. If you need guidance
in what is expected, you can consult the Style Guide:
https://google.github.io/styleguide/cppguide.html. Notice that the errors range
from the placement of braces to the use of the keyword `explicit` to commenting.

If you want to run the linter on your local copy on your personal machine, you
will need to download cpplint from the repository:
https://github.com/google/styleguide. If you are working on your own machine, it
is recommended that you install with the python installation tool _pip3_, which
might need to be installed (but probably not if you have python3 -- type `pip3
--version` to verify), then install cpplint with `pip3 install cpplint`.

As part of assessment, all files will be run through cpplint. Make sure your
code has 0 errors when you submit.

### Part 2 - Google Style Compliance: Advanced Analysis
There are some elements of google style that cannot be checked via linting, such
as variable names, class names, namespace names, function length, etc., as these
require more full-featured semantic analysis of the code that can really only be
done by a compiler. We use an external tool which is capable of such analysis in
order to check additional elements of google style. This will show up as an
additional element of the feedback/assessment, so please make sure to have 0
errors for this part before you submit as well.

### Part 3 - Doxygen

Now that your code is Google style compliant, the next part of this lab is to
generate documentation for the code you write. This is done via Doxygen.

According to their official website,
> Doxygen is the de facto standard tool for generating documentation from
> annotated C++ sources, but it also supports other popular programming languages
> such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and
> UNO/OpenOffice flavors), Fortran, VHDL, Tcl, and to some extent D.

Notice how the class RobotViewer in robot_viewer.h has a description above the
class definition. Doxygen makes use of this to generate documentation for this
class. Doxygen also generates documentation for all functions of a class.

NOTE: Students working on their personal machines will have to download the
doxygen executable before continuing. CSE labs machines already have doxygen
installed.

1. Create the configuration file.
  To start generating documentation, you must first generate a Doxygen
  configuration file in the docs directory. Run the following commands from the
  lab05 directory.

  ```
  mkdir docs
  doxygen -g docs/Doxyfile
  ```

  You will now see a new file **Doxyfile** in the docs directory.

2. Modify the Doxyfile to look in the _src_ folder when compiling. You can do
   this by setting the **INPUT** tag of your **Doxyfile** to point to src. 
   Also, set OUTPUT_DIRECTORY to point to docs and put in the appropriate
   project name in PROJECT_NAME tag.

3. Generate the html pages for this lab. Run the following command from the
  lab05 directory.
  ```
  doxygen docs/Doxyfile
  ```

  You can now view the generated documentation from the index.html file in the
  **html** directory that was generated inside the docs folder. But notice how
  your document has a blank landing page. This is because there is no mainpage.h
  file in your src directory.

4. Create a home page for the project. In your _src_ directory, create a file
   **mainpage.h** and paste the following in it.

  ```
  /*! \mainpage My Personal Index Page
   *
   * \section intro_sec Introduction
   *
   * This is the introduction.
   *
   */
 ```

  Generate documentation again by running doxygen as you did before from the
  lab05 directory and notice how you now have a landing page for your project.

 5. Edit the mainpage.h file by giving it a meaningful title and write a
    meaningful first sentence of the introduction.

 6. Add a class and the corresponding Doxygen comments in the code.
   ```
  class Obstacle {
  public:
     Obstacle() : radius_(10), position_(20.0,20.0) {}
     int get_radius() {return radius_;}
     std::pair<double,double> get_pos() {return pos_;}
  private:
      int radius_;
      std::pair<double, double> pos_;
  }
   ```
   When you have created this class with documentation (you only need the _.h_
   file), run it again and see how it appears in the class list. Click on the
   class and you will see more detailed information.

7. Make sure you are not pushing the html and latex folders to your repo (HINT:
   use .gitignore). These take a lot of space and can be generated from the
   Doxygen file, thus there is no need to have them in your repo.

 **IMPORTANT**:Make sure you run another Google style check before you make your
 final submission.
