//
//  MallardDuck.cpp
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include "MallardDuck.h"

#include <iostream>
#include <string>

#include "Quack.h"

using std::cout;
using std::endl;
using std::string;

MallardDuck::MallardDuck() {
}

MallardDuck::~MallardDuck() {
}

string MallardDuck::getDescription() {
    string descriptionText = "a mallard duck";
    return descriptionText;
}
