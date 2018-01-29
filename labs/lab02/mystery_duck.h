#ifndef LAB02_MYSTERY_DUCK_H_
#define LAB02_MYSTERY_DUCK_H_

#include <string>
#include "duck.h"

class MysteryDuck : public Duck {
public:
     MysteryDuck(std::string description = "I am a mystery duck", std::string sound = "mystery quack!");
     std::string get_description();

};

#endif
