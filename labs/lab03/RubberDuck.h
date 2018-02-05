//
//  RubberDuck.h
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef RUBBERDUCK_H_
#define RUBBERDUCK_H_

#include <string>

#include "Duck.h"

class RubberDuck : public Duck {
 public:
    RubberDuck();
    ~RubberDuck();

    std::string getDescription();
};

#endif  // RUBBERDUCK_H_
