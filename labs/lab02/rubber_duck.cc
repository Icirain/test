//
//  rubber_duck.cc
//  CSCI3081-Lab2
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include "rubber_duck.h"

using std::cout;
using std::endl;
using std::string;

RubberDuck::RubberDuck() {
  description_text_ = "a yellow rubber ducky";
  sound_ = "SQUEAK!!";
}

string RubberDuck::get_description() {
    return description_text_;
}

void RubberDuck::PerformQuack() {
    cout << sound_ << endl;
}
