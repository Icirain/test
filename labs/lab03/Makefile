CC = g++



all: main.o Duck.o DecoyDuck.o RubberDuck.o MallardDuck.o MuteQuack.o QuackBehavior.o Squeak.o Quack.o
	g++ -o lab03.out DecoyDuck.o RubberDuck.o MallardDuck.o Duck.o main.o MuteQuack.o QuackBehavior.o Squeak.o Quack.o

main.o:
	$(CC) -c -o main.o main.cc

Duck.o:
	g++ -c -o Duck.o Duck.cc

DecoyDuck.o:
	g++ -c -o DecoyDuck.o DecoyDuck.cc
RubberDuck.o:
	g++ -c -o RubberDuck.o RubberDuck.cc
MallardDuck.o:
	g++ -c -o MallardDuck.o MallardDuck.cc
MuteQuack.o:
	g++ -c -o MuteQuack.o MuteQuack.cc
QuackBehavior.o:
	g++ -c -o QuackBehavior.o QuackBehavior.cc
Squeak.o:
	g++ -c -o Squeak.o Squeak.cc
Quack.o:
	g++ -c -o Quack.o Quack.cc

clean:
	rm *.o *.out
