//
//  rubber_duck.h
//  CSCI3081-Lab2
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef LAB02_RUBBER_DUCK_H_
#define LAB02_RUBBER_DUCK_H_

#include <string>
#include "duck.h"

class RubberDuck : public Duck {
public:
    RubberDuck();
    std::string get_description();
    void PerformQuack();
};

#endif
