#ifndef LAB02_DECOY_DUCK_H_
#define LAB02_DECOY_DUCK_H_

#include <string>
#include "duck.h"

class DecoyDuck : public Duck {
public:
     DecoyDuck();
     std::string get_description();

};

#endif
