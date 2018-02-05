#### Lab Session 3: Introduction to Makefiles

**Due date:** Mon, Feb 05 at 11:59 pm

-   Makefile

In this lab, you will write a Makefile in order to make compilation of our duck simulator convenient. Please follow the setup instructions below.

 ##### Getting Started and Words of Advice

The starting code base for this lab exercise is available in the class repository. You do not want to edit within the class repo or it will cause merge conflicts. Copy the code to your individual repo and work within that. Please follow the same directory structure such that lab03 is within the labs folder.

At each push, an automatic feedback file will be pushed to your repo.
> Don't forget to _pull_ the feedback before making more edits to your repo or you will cause merge conflicts.

The automated feedback encompasses a majority, if not all, the tests that will be used to grade your lab. Please make sure you review the feedback from your final submission to ensure it passes all the tests. Minor fixable errors can result in 0 points for the lab because automated grading fails. You are responsible for ensuring your code passes all tests in the feedback.

> We will not reconsider your lab grade after the due date if the feedback file gave you information that you ignored.


##### Step 0: Update Your Repositories


1. Open a terminal window.
3. Navigate to the directory of your 3081 class repo.
1. `git pull` to get lab03 base code
1. Copy the directory into your _labs_ directory in your individual class repo.

   ``` cp -R public-class-repo/lab03 <path_to_individual_repo>/labs/.```

1. Navigate into the lab03 directory in your individual repo:

#### Instructions

A Makefile is a build system. A makefile automates the process of compilation and linking and it is essential for large-scale projects. The main difference between a script file and a Makefile is that a Makefile keeps track of file modification timestamps. Some consider the Makefile to be a glorified script but to call it that makes it sound like it is simple to do. Makefiles can be quite complex.

You have already used a makefile perhaps without realizing it. In the first lab, you created an executable by typing 'make' at the command prompt. This was a call to the file named _makefile_ included in that directory. A 'make' command starts by searching for a makefile (named either _makefile_ or _Makefile_). If no argument is passed, it will try to create the first _target_ listed in the file, which is described below. If you entered 'make main.o', it would look for a _target_ with the name _main.o_ and follow the directions for creating that target, which happens to be a file, but that is not always the case. The targets _all_ and _clean_ are standard targets in makefiles that compile and link all files needed for the executable, and remove all object files and executable for a clean start, respectively.

There are directions below for creating a makefile for the included code. At the bottom of the file is a quick guide to makefile commands. You might also find the following resources helpful:

- http://mrbook.org/blog/tutorials/make/
- http://www.cs.umd.edu/class/fall2002/cmsc214/Tutorial/makefile.html
- https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
- https://www.cprogramming.com/tutorial/makefiles.html
- https://www.gnu.org/software/make/manual/make.html (this is massive and speaks to the complexity of the language)

##### Create Your Makefile with _all_ and _clean_ targets

1.  Create your Makefile.
2.  **emacs Makefile &** (you can use the editor of your choice)
3.  Write the <code>all</code> target, which will perform the linking to create the executable `lab03.out` (_see “Targets” section in Makefile Cheat Sheet below_). Do not create any dependencies at this time, thus you need only have _all:_ in the first line. On the next line, press a <code>TAB</code> !!**It must be a tab, not spaces**!! and the command to link everything together, which will start with 'g++'. Recall that '-o <file>' sends the results to the listed <file> and linking incorporates all the object files. Making visible compiler and linking warnings is a good idea! In all your commands for building and linking add the flag -Wall for viewing all warnings.
> Note: having _all_ target as the first target makes it the default one. When you <code>make</code> with no arguments, _all_ target is run.

> If you feel lost at this point, use the _makefile_ from Lab 01 as a reference, or ask the TA for help.

4.  Write the <code>clean</code> target in the same way as you did it for <code>all</code>. The <code>clean</code> target is used to remove all object files and the executable. (*See “Dummy Targets” section in Makefile Cheat Sheet below.*)
5. At the OS command prompt,
```
make clean
make
```
This will generate an error because the object files do not exist.

6. Create a target <code>file.o</code> for all relevant files in your directory. Try <code>make</code> again.  Still does not work! Keep going to fix ...

> If you want to make comments in your makefile, use the pound # symbol.

##### Adding Dependencies

The files listed after _target:_ are the dependencies, which are used in two ways. 1) The file has to exist, and if it does not exist, the makefile will search for a target of the same name to create it, and 2) If the file does exist, it will look at the timestamp to see if it has changed since the last creation of the _target_, and recreate the dependency if necessary.

Think about why you are still seeing an error when you make. If you don't know, ask a neighbor.

> Hint: In listing the targets, dependencies, and compiler actions, think carefully about the relationships among the classes. The dependencies are everything whose change requires recompiling the source code. That includes not only your #include-d headers, but also indirectly included headers.

1. Add dependencies to your _all_ target.
2. <code>make</code> and now your executable should be created. Pay attention to what is being echoed out to your shell, which will show you each of the commands in your makefile being executed. Try it out with <code>./lab03.out</code>
3. Modify one of the files in your dependencies for _all_ (any change will do).
4. <code>make</code> again and observe that this file, and only this file, is recompiled.
5. <code>make clean</code>. Observe that the object files and executable are now gone.
6. <code>make MallardDuck.o</code> and observe that it made that target, and only that target.
7. <code>make all</code> and observe that everything else is being compiled, and the executable is being created.

> Sometimes the dependencies are not listed correctly or do not work the way we think they should. If you make changes to a file, but it doesn't seem to be having any impact on the executable, <code>make</code> might not recognize that it needs to recompile. You can remedy this with <code>make clean</code> then <code>make</code> to force recompilation.

##### Improve Your Makefile

1.  First, copy your makefile so that you have a backup: cp Makefile MakefileOld
2.  Modify your Makefile to add a variable. For example, create a variable called CXX that defines the name of the compiler to use. Similarly, create a variable CXXFLAGS for compiler flags. Don't forget to include -Wall. Update the targets to use this variable.  Variables appear first in the makefile, before the _all_ target. (*See “Macros” section in Makefile Cheat Sheet below.*)
3.  If you wish to build using the old Makefile, you can do so by running: make -f MakefileOld

##### Build and Submit

1.  Clean and build your program with your Makefile
2.  Run your program
3.  ```./lab03.out```
4.  Commit and check in results:
5.  git add .
6.  git commit -m “finishing lab03”
7.  git push origin master


#### Makefile Cheat Sheet

##### Targets

A Makefile target works in this way:
```
target: dependencies
[tab] system command
```
A target is usually a file, but not always. This definition tells you to construct the target when the dependencies are newer than the target with the system command. For example, to compile our duck simulator you could enter the following in your Makefile:

```
Duck.o: Duck.h Duck.cc
    g++ -c Duck.cc
```

##### Dummy Targets

There are times when you do not want to create a target, but instead run a few commands. For example, you may want to “clean” your directory of files that come from the compilation process. This could be done with the following:
```
clean:
    rm *.o *.out
```

##### Macros

A macro is a “variable” can be defined in a Makefile. Macros are defined as = pairs and can be called by either \$(VARIABLE\_NAME) or \${VARIABLE\_NAME}. For example, we can define compiler and compiler flags macros:

```
CXX = g++
CXXFLAGS = -Wall -c -std=c++11
```

(Makefile conventions say variable names should consist of all caps and underscores)
