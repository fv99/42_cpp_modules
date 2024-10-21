#pragma once

#include <iostream>
#include <exception>
#include <algorithm> // for std::find

class NotFoundException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Error: Value not found in container";
    }
};

template <typename T>
typename T::iterator easyfind(T &con, int i)
{
    typename T::iterator ret;

    ret = std::find(con.begin(), con.end(), i);
    if (ret == con.end())
    {
        throw NotFoundException();
    }
    return ret;
}
