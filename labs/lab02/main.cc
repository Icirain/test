//
//  main.cc
//  CSCI3081-Lab2
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include <iostream>
#include "mallard_duck.h"
#include "rubber_duck.h"
#include "decoy_duck.h"
#include "mystery_duck.h"

using std::cout;
using std::endl;

int main() {

    // Create Ducks
    Duck jane;
    MallardDuck maloy;
    RubberDuck lemon;
    DecoyDuck Damon;
    MysteryDuck Mason;

    cout << endl;

    // Introduce a generic duck
    cout << "This" << " is " << jane.get_description() << " who says ";
    jane.PerformQuack();
    cout << endl;

    // Introduce a mallard duck
    cout << "This" << " is " << maloy.get_description() << " who says " ;
    maloy.PerformQuack();
    cout << endl;

    // Introduce a rubber duck
    cout << "This" << " is " << lemon.get_description() << " who says " ;
    lemon.PerformQuack();
    cout << endl;

    // Introduce a decoy duck
    cout << "This" << " is " << Damon.get_description() << " who says " ;
    Damon.PerformQuack();
    cout << endl;

    // Introduce a mystery duck
    cout << "This" << " is " << Mason.get_description() << " who says " ;
    Mason.PerformQuack();
    cout << endl;



    // I had to type the same thing over and over.
    // I think I can do better by wrapping it in a loop!
    // BUT WAIT, look at the output - it doesn't work! More on this later ...
    Duck ducks[5];
    ducks[0] = jane;
    ducks[1] = maloy;
    ducks[2] = lemon;
    ducks[3] = Damon;
    ducks[4] = Mason;
    for (int i=0;i<5;i++) {
      cout << "This is " << ducks[i].get_description() << " who says ";
      ducks[i].PerformQuack();
    }
    cout << endl;

    return 0;
}
