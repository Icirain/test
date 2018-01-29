#include <iostream>
#include <string>
#include "mystery_duck.h"

using std::count;
using std::endl;
using std::string;

MysteryDuck::MysteryDuck(std::string description , std::string sound){
  description_text_ = description;
  sound_ = sound;
}

std::string MysteryDuck::get_description(){
  return description_text_;
}
