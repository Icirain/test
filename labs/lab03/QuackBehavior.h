//
//  QuackBehavior.h
//
//  Created by Seth Johnson on 2/4/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef QUACKBEHAVIOR_H_
#define QUACKBEHAVIOR_H_

#include <stdio.h>

class QuackBehavior {
 public:
    QuackBehavior();
    virtual ~QuackBehavior() {}
    virtual void quack() = 0;
};

#endif  // QUACKBEHAVIOR_H_
