## Lab 2 - Compiling and Linking

In this lab, you are going to learn how to compile the source code and link the executable. The source code is in .cc and .h files. The object code is in the .o files. Executables are either .out or have no extension.

In addition to practicing compilation, you will define classes and subclasses. In class exercises, we have demonstrated the basics on class definitions. The syntax of a class and subclass definition is also provided within this document.

Deliverables:
- main.cc
- decoy_duck.cc
- decoy_duck.h
- mystery_duck.cc
- mystery_duck.h

In this lab, you will write and edit some C++ code, build it, and run it. Please follow the instructions below. The given source code will help you get started.

### Getting Started and Words of Advice

The starting code base for this lab exercise is available in the class repo. You do not want to edit within the class repo or it will cause merge conflicts. Copy the code to your
individual repo and work within that. Please follow the same directory structure
such that lab02 is within the labs folder.

At each push, an automatic feedback file will be pushed to your repo.
> <b>Don't forget to _pull_ the feedback before making more edits to your repo or you will cause merge conflicts.</b>

The automated feedback encompasses a majority, if not all, the tests that will be used to grade your lab. Please make sure you review the feedback from your final submission to ensure it passes all the tests. Minor fixable errors can result in 0 points for the lab because automated grading fails. You are responsible for ensuring your code passes all tests in the feedback.

> <b> We will not reconsider your lab grade after the due date if the feedback file gave you information that you ignored. </b>

Text editors designed for coding are essential. There are many good options available for free and on the cselabs machines.

### Step 1: Update Your Repositories

   _If you did not do last week's lab, refer to lab01 for directions on how to set up git for both the class repo and your individual repo._

1. Open a terminal window.
3. Navigate to the directory of your 3081 class repo.
1. `pull` to get lab02 base code
1. Copy the directory into your _labs_ directory in your individual class repo.

   ``` mv labs/lab02 <path_to_individual_repo>/labs/.```

1. Navigate into the lab02 directory in your individual repo:

### Step 2: Compile the Source Code

> BE VERY CAREFUL with -o option. If you put a source or header file name immediately after -o, 
it will overwrite that file with no way to get it back. Using the -o option is not necessary 
(see notes below), but it is common practice to explicitly state that in the makefile -- which we will 
explore next week.

1. Compile the .cc files into object files.
   ``` 
   % g++ -c -o main.o main.cc
   % g++ -c -o duck.o duck.cc
   % g++ -c -o mallard_duck.o mallard_duck.cc
   % g++ -c -o rubber_duck.o rubber_duck.cc
   ```
   <b> What does all this mean? </b>
   - `g++` : call to the gnu c++ compiler
   - `-c`  : a flag to indicate compilation, as opposed to linking
   - `-o`  : output the results of compilation into the file following this flag
   - `main.cc` : the last file is the one to be compiled
   - If `-c` is not provided, the compiler will attempt to compile AND link.
   - If `-o` with an output file is not provided, the compiler will use the name of the .cpp file for the .o filename.

   Notice that each file is independently compiled, even though there are interdependencies among them. If you look in the .cpp file, there will be a `#include file.h` statement which essentially inserts the text of <file.h> at the location of the #include statement. Compilation will create symbol tables for all classes, variables, functions declared within those header files, but with no associated address for the definition of those elements. When the files are _linked_, those dependencies will be resolved and the definitions of the various objects will be included in the complete program.

### Step 3: Linking to Generate the Executable

1. Link the object files into an executable: 

   ```% g++ -o duck main.o duck.o mallard_duck.o rubber_duck.o```

   * What does all this mean? *
   - `g++` : call to the gnu c++ compiler
   - `-o`  : output the executable into the file following this flag
   - list of files : all the files that need to be linked.
   -If `-o` and output file are not provided, the compiler will create the executable `a.out`

  _Notice there was no need to tell the compiler that we are in the linking phase._

  > HINT: A shortcut for linking is `% g++ -o duck *.o`

2. Run the program: 

   ```% ./duck```

### Step 4: Add DecoyDuck to Current Project

First, let's review the syntax for class definitions in C++. This is a simple class definition that we can think of as defining an interface for the subclasses which will inherit from _Duck_.
```
#ifndef LAB02_DUCK_H_
#define LAB02_DUCK_H_
...
#endif
```
This serves as a guard for the header file. If there are interdependencies among files such that the compiler is instructed to include this several times, this safeguard communicates to the compiler that this code has already been incorporated. It makes compilation more efficient, and when you have circular references or definitions within the header, it is necessary.

#### duck.h

```C++
class Duck {
public:
    Duck();
    virtual void PerformQuack();
    virtual std::string get_description();
protected:
    std::string description_text_;
    std::string sound_;
};
```

- `Duck()` is the constructor with no passed parameters.
- 'virtual' indicates this can be overwritten by the subclass. When we study polymorphism, the need for `virtual` will become clearer.
- `public:` gives direct access to members and methods outside the class.
- '};' : Don't forget to conclude your definition with a semi-colon


#### duck.cc

```C++
#include "duck.h"
```
Don't forget to include the Duck.h file - of course the compiler will let you know if you forget it when it tries to search for the _Duck_ class for inheritance.

```C++
class RubberDuck : public Duck {
public:
    RubberDuck();

    std::string get_description();
    void PerformQuack();
};
```
- `class RubberDuck : public Duck` is the declaration of a new class RubberDuck that inherits from the class Duck. `public` indicates that RubberDuck will have full access to those elements in the Duck class.
- Notice that all methods of the Duck class are restated in the RubberDuck class definition because they will all be overridden by RubberDuck. Definitions of these functions are in the `RubberDuck.cc` file.

#### main.cc

```C++
#include "mallard_duck.h"
#include "rubber_duck.h"
```
Notice that we are not including Duck.h. Can you guess why we don't need it, even though we are referencing it below?

```C++
using std::cout;
using std::endl;

int main() {

    // Create Ducks
    Duck jane;
    MallardDuck maloy;
    RubberDuck lemon;
```

These are the instantiations of the different types of ducks. The beauty of subclasses comes into play when we can treat all types of ducks identically, so that the code chooses the appropriate method for the given type. This is polymorphism, which requires knowledge of pointers and dynamic allocation - soon to be covered.

```C++
Duck ducks[3];
ducks[0] = jane;
ducks[1] = maloy;
ducks[2] = lemon;
for (int i=0;i<3;i++) {
  cout << "This is " << ducks[i].get_description() << " who says ";
  ducks[i].perform_quack();
}
```

Above is an attempt to use polymorphism in C++, such that we refer to objects of different duck types in one structure using the same interface. It doesn't work because we aren't using dynamic allocation.

### Lab Activity
The lab activity is composed of 3 steps.

#### Step 1: Create a New Class for DecoyDuck

Your task is to add another duck subclass to this simulator, namely the decoy duck.
1. Start by creating decoy duck subclass below, following the following steps:

<ul><ul>
   <li> Name the class <i>DecoyDuck</i>
    <li> The description is "a plastic decoy duck"
    <li> It is silent, thus it says '...'
</ul></ul>

a. Create both a decoy_duck.h and decoy_duck.cc file in your favorite editor (e.g. `atom& decoy_duck.h`).<br/>
b. Define the class as a subclass of _Duck_<br/>
c. Declare the needed methods in the .h file as described in the specification.<br/>
d. Define the needed methods in the .cc file. <br/>
e. Modify _main.cc_ to include a DecoyDuck in the simulation.

>Note that you do not need to recompile any of the other files. It is only the linking process that must be redone. This makes compilation far more efficient, which doesn't seem like much of a time savings in our little program, but imagine a project in which the compilation takes hours!

2. Compile your new duck and link it all together.

### Step 2 : Add MysteryDuck class.

Do the following:

<ol type="a">
   <li> Currently, Duck does not have any members, but it makes sense to hold the description and quacking sound in the duck class. In the Duck class, make variables of type string in which to save the description and sound. Don't forget to hide your members from objects outside the class, but make them visible to subclasses (i.e. use _protected:_).<br>
<li> Modify the Duck class to initialize both variables.<br>
<li> Create _MysteryDuck_ class that inherits from _Duck_.<br/>
<li> For _MysteryDuck_, create a constructor that takes 2 parameters -- the description and sound. **The description should be the first parameter and the sound the second.** You can choose how to describe mystery duck and what sound it makes. Use these to initialize the class variables.c. Add this to _main.cc_.<br/>
<li> Add MysteryDuck to _main.cc_.<br>
<li> Compile and link as before. <br>
</ol>

### Step 3 : Push to the repository

```
git add *
git commit -m “adding decoy and mystery duck classes”
git push
```
Great! You finished the lab :)
