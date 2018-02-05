//
//  Duck.h
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#ifndef DUCK_H_
#define DUCK_H_

#include <string>

class QuackBehavior;

class Duck {
 public:
    Duck();
    virtual ~Duck() {};
    virtual void performQuack();
    virtual std::string getDescription() = 0;
    std::string getName();
    void setName(std::string name);
    void setQuackBehavior(QuackBehavior * behavior);

 protected:
    std::string m_name;
    QuackBehavior * m_quackBehavior;
};

#endif  // DUCK_H_
