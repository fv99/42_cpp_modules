#include "hurl.hpp"

Eblan::Eblan(void)
{
    std::cout << "я еблан" << std::endl;
}

Eblan::~Eblan(void)
{
    std::cout << "мне пизда" << std::endl;
}

void Eblan::debug(void)
{
    std::cout << "[DEBUG]: ох шит им сорри" << std::endl;
}

void Eblan::info(void)
{
    std::cout << "[INFO]: сорри фор вот" << std::endl;
}

void Eblan::warning(void)
{
    std::cout << "[WARN]: я бы выебал тебя в рот " << std::endl;
}

void Eblan::error(void)
{
    std::cout << "[ERROR]: ну я просто ебаный бот " << std::endl;
}

void Eblan::cry(std::string lvl)
{
    void (Eblan::*cry_ptr[4])(void) = {&Eblan::debug, &Eblan::info, &Eblan::warning, &Eblan::error};
    std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level[i] == lvl)
        {
            (this->*cry_ptr[i])();
            break;
        }
    }
}