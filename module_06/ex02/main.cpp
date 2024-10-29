#include "base.hpp"
#include "a.hpp"
#include "b.hpp"
#include "c.hpp"

int main()
{
    Base* p = generate();

    std::cout << "Identifying using pointer:" << std::endl;
    identify(p);

    std::cout << "Identifying using reference:" << std::endl;
    identify(*p);

    delete p;

    return 0;
}
