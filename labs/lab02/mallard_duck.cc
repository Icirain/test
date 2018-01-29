//
//  mallard_duck.cc
//  CSCI3081-Lab2
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include <iostream>
#include <string>
#include "mallard_duck.h"

using std::cout;
using std::endl;
using std::string;

MallardDuck::MallardDuck() {
  description_text_ = "a mallard";
}

string MallardDuck::get_description() {
  return description_text_;
}
