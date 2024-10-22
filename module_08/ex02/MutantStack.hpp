

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {}
    ~MutantStack() {}

    MutantStack<T> &operator=(const MutantStack<T> &src)
    {
        if (this != &src)
            std::stack<T>::operator=(src);
        return *this;
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};
