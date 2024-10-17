#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <typeinfo>


class Base
{
	public:
		virtual ~Base(void);
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);
