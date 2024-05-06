#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        std::stderr << "Please add an argument" << std::endl;
        return 1; 
    }

    std::string argument = new std::string(argv[1]);
    std::vector<char> characters = new std::vector();

    for (char &&letter : argument)
    {

    }
     
    

    delete argument;
    return 0; 
}
