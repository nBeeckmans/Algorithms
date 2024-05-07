#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        std::cerr << "Please add an argument" << std::endl;
        std::exit(1);
    }

    std::string argument(argv[1]);
    std::vector<char> *characters = new std::vector<char>();

    for (char letter : argument)
    {
        if (std::find(characters->begin(), characters->end(), letter) != characters->end()) {
           std::cout<<"characters are not unique" << std::endl; 
           delete characters;
           std::exit(-1);
       } 
        characters->push_back(letter);
    }
     
    std::cout << "characters are unique" << std::endl;
    delete characters;
    return 0; 
}
