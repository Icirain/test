#include <iostream>
#include <string>
#include "decoy_duck.h"

using std::cout;
using std::endl;
using std::string;

DecoyDuck :: DecoyDuck(){
  description_text_ = "a plastic decoy duck";
  sound_ = "...";
}

string DecoyDuck::get_description(){
   return description_text_;
}
