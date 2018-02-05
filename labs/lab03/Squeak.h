//
//  Squeak.h
//
//  Created by Seth Johnson on 2/5/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef SQUEAK_H_
#define SQUEAK_H_

#include "QuackBehavior.h"

class Squeak : public QuackBehavior {
 public:
    Squeak();
    ~Squeak();

    void quack();
};

#endif  // SQUEAK_H_
