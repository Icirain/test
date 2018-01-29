//
//  mallard_duck.h
//  CSCI3081-Lab2
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#ifndef LAB02_MALLARD_DUCK_H_
#define LAB02_MALLARD_DUCK_H_

#include <string>
#include "duck.h"

class MallardDuck : public Duck {
public:
    MallardDuck();
    std::string get_description();
};

#endif
