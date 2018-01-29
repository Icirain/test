//
//  duck.cc
//  CSCI3081-Lab2
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include <iostream>
#include "duck.h"

using std::cout;
using std::endl;

Duck::Duck() {
  description_text_ = "a plain duck";
  sound_ = "Quack";
}

void Duck::PerformQuack() {
    cout << sound_ << endl;
}

std::string Duck::get_description() {
  return description_text_;
}
