#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

int main(int argc, char  **argv) 
{
    if (argc < 3) 
    {
        std::cerr << "plz add 2 arguments" << std::endl;
        std::exit(-1);
    }

    if (std::strlen(argv[1]) != std::strlen(argv[2])) 
    {
        std::cout << "both strings dont have the same size" << std::endl; 
        std::exit(0);
    }
    
    std::vector<char> *characters = new std::vector<char>();

    for (int i = 0; i < (int) std::strlen(argv[1]); i++) 
    {
        characters->push_back(argv[1][i]);       
    }

    for (int i = 0; i < (int) std::strlen(argv[2]); i++)
    {
        auto element = std::find(characters->begin(), characters->end(), argv[2][i]);
        if (element != characters->end()) 
        {
            characters->erase(element);
        }
        else 
        {
            std::cout << "the strings are not permutations" << std::endl;
            std::exit(-1);
        }
    }
    
    std::cout << "strings are permutations" << std::endl;

    delete characters;
    return 0;
}