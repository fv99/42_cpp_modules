#include "base.hpp"
#include "a.hpp"
#include "b.hpp"
#include "c.hpp"

Base ::~Base(void) {}

Base *generate(void)
{
	int _rand;
	srand(time(0));
	_rand = rand() % 3;
	if (_rand == 0)
		return new A;
	else if (_rand == 1)
		return new B;
	else if (_rand == 2)
		return new C;
	else
		return NULL;
}

void identify(Base *p)
{
	if (p == NULL)
	{
		std::cout << "no pointer received" << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type C" << std::endl;
	else
		std::cout << "cannot identify type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Type A" << std::endl;
        (void)a;
    }
    catch (...)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            std::cout << "Type B" << std::endl;
            (void)b;
        }
        catch (...)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                std::cout << "Type C" << std::endl;
                (void)c;
            }
            catch (...)
            {
                std::cout << "Cannot identify type" << std::endl;
            }
        }
    }
}
