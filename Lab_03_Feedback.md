### Feedback for Lab 03

Run on February 05, 14:56:50 PM.


#### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab03" exists.

+ Pass: Change into directory "labs/lab03".

+ Pass: Check that file "Makefile" exists.


#### .gitignore configured properly

+ Pass: Check that file/directory "lab03.out" does not exist.

+ Pass: Check that no files with extension ".o" exist in directory "."


#### Specific Target - Duck.o

+ Pass: make 'Duck.o' in directory '.': expect result=Duck.o, timeout=500

    make successful.
    Check Duck.o exists...OK: result Duck.o found

+ Pass: make 'Squeak.o' in directory '.': expect result=Squeak.o, timeout=500

    make successful.
    Check Squeak.o exists...OK: result Squeak.o found

+ Pass: make 'QuackBehavior.o' in directory '.': expect result=QuackBehavior.o, timeout=500

    make successful.
    Check QuackBehavior.o exists...OK: result QuackBehavior.o found

+ Pass: make 'RubberDuck.o' in directory '.': expect result=RubberDuck.o, timeout=500

    make successful.
    Check RubberDuck.o exists...OK: result RubberDuck.o found

+ Pass: make 'MallardDuck.o' in directory '.': expect result=MallardDuck.o, timeout=500

    make successful.
    Check MallardDuck.o exists...OK: result MallardDuck.o found

+ Pass: make 'DecoyDuck.o' in directory '.': expect result=DecoyDuck.o, timeout=500

    make successful.
    Check DecoyDuck.o exists...OK: result DecoyDuck.o found

+ Pass: make 'Quack.o' in directory '.': expect result=Quack.o, timeout=500

    make successful.
    Check Quack.o exists...OK: result Quack.o found

+ Pass: make 'MuteQuack.o' in directory '.': expect result=MuteQuack.o, timeout=500

    make successful.
    Check MuteQuack.o exists...OK: result MuteQuack.o found


#### make all functional

+ Pass: make 'all' in directory '.': expect result=lab03.out, timeout=500

    make successful.
    Check lab03.out exists...OK: result lab03.out found


#### make clean functional

+ Pass: make 'clean' in directory '.': expect result=Makefile, timeout=500

    make successful.
    Check Makefile exists...OK: result Makefile found


#### Variables used in Makefile

+ Pass: Check $( exists in Makefile.

