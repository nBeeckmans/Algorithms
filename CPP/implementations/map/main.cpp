#include "map.hpp"
#include <string>
#include <iostream>

int main(void) 
{
  Map<char*, double> *map = new Map<char*, double>();
  map->addKeyValue("I", 0.05);

  map->addKeyValue("ate",0.022);
  map->addKeyValue("apples",1.123);
  if (map->addKeyValue("apples",1231515)) // this implementation of map doesnt add already existing elements
  {
    std::cout << "apples already exists in map" << std::endl;
  }
  if (!map->hasKey("pears"))
  {
    std::cout << "pears doesnt exists in map" << std::endl;
  }
  if (map->removeKey("cherry")->has_value()) 
  {
    std::cout << "cherry doesnt exists in map" << std::endl;
  }
  return 0;
}
