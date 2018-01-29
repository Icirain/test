//
//  duck.h
//  CSCI3081-Lab2
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#ifndef LAB02_DUCK_H_
#define LAB02_DUCK_H_

#include <string>

class Duck {
public:
    Duck();
    virtual void PerformQuack();
    virtual std::string get_description();
protected:
    std::string description_text_;
    std::string sound_;
};

#endif
