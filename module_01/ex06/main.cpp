#include <iostream>
#include <string>
#include "Harl.hpp"

int opuskatel(char *argv)
{
    std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level[i] == argv)
            return (i);
    }
    return (-1);
}

void ebloid_switcher(char *argv, Eblan & a)
{
    switch(opuskatel(argv))
    {
        case 0:
            a.cry("DEBUG");
            break;
        case 1:
            a.cry("INFO");
            break;
        case 2:
            a.cry("WARNING");
            break;
        case 3:
            a.cry("ERROR");
            break;
        default:
            std::cout << "i am quiet" << std::endl;
    }
}


int main(int argc, char **argv)
{
    Eblan a;

    if (argc != 2)
        std::cout << "i am quiet" << std::endl;
    else
        ebloid_switcher(argv[1], a);
    return 0;
}
