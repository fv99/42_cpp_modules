#ifndef HURL_HPP
#define HURL_HPP

#include <iostream>

class Eblan
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        Eblan(void);
        ~Eblan();
        void cry(std::string lvl);
};

#endif
