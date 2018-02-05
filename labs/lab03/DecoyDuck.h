//
//  DecoyDuck.h
//
//  Created by Seth Johnson on 1/24/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef DECOYDUCK_H_
#define DECOYDUCK_H_

#include <string>

#include "Duck.h"

class DecoyDuck : public Duck {
 public:
    DecoyDuck();
    ~DecoyDuck();

    std::string getDescription();
};

#endif  // DECOYDUCK_H_
