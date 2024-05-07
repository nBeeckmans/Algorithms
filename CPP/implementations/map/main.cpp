#include "main.hpp"
#include <string>
#include <iostream>

int main(void) 
{
  Map<std::string> *map = new Map<std::string>();
  map->addElement("I");
  map->addElement("ate");
  map->addElement("apples");
  if (map->addElement("apples")) // this implementation of map doesnt add already existing elements
  {
    std::cout << "apples already exists in map" << std::endl;
  }
  if (!map->hasElement("pears"))
  {
    std::cout << "pears doesnt exists in map" << std::endl;
  }
  if (!map->removeElement("cherry")) 
  {
    std::cout << "cherry doesnt exists in map" << std::endl;
  }
 
  return 0;
}
