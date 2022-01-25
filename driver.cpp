#include <iostream>
#include <string>
#include <sstream>
#include "Calculator.h"

int main (int argc, char * argv [])
{
    bool quit = false;

    Calculator myCalculator;

    std::string input;

    while(!quit)
    {
        std::getline(std::cin, input);
        
        if(input == "QUIT")
        {
            quit = true;
            break;
        }

        try
        {
            std::cout << myCalculator.calculate(input) << std::endl;
        }
        catch (const char * e_msg)
        {
            std::cout << e_msg << std::endl;
        }
    }
}
