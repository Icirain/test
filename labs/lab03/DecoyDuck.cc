//
//  DecoyDuck.cpp
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "DecoyDuck.h"

#include <iostream>
#include <string>

#include "MuteQuack.h"

using std::cout;
using std::endl;
using std::string;

DecoyDuck::DecoyDuck() {
    setQuackBehavior(new MuteQuack());
}

DecoyDuck::~DecoyDuck() {
}

string DecoyDuck::getDescription() {
    string descriptionText = "a plastic decoy duck";
    return descriptionText;
}
