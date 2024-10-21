#pragma once

#include <iostream>
#include <cstdlib>

template <typename ARRAY>

class Array
{
	private:
		ARRAY *_arr;
		unsigned int _size;
	
	public:
		// no param constructor
		Array(): _size(0)
		{
			std::cout << "default constructor called for array of size 0" << std::endl;
			this->_arr = new ARRAY[this->_size];
		}

		// constructor with param
		Array(unsigned int size): _size(size)
		{
			std::cout << "constructor called for array of size " << size << std::endl;
			this->_arr = new ARRAY[this->_size];
		}

		// copy constructor
		Array(const Array &src): _size(src.size())
		{
			std::cout << "copy contructor called" << std::endl;
			this->_arr = NULL;
			*this = src;
		}

		// desctructor
		~Array()
		{
			if (this->_arr != NULL)
				delete[] this->_arr;
		}

		// overload =
		Array &operator=(const Array &src)
		{
			if (this->_arr != NULL)
				delete[] this->_arr;
			if (src.size() != 0)
			{
				this->_size = src.size();
				this->_arr = new ARRAY[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_arr[i] = src._arr[i];
			}
			return(*this);
		}

		// exception for [] overload
		class OutOfBoundsException: public std::exception		
		{
			public:
				virtual const char *what() const throw();
		};

		// overload for []
		ARRAY &operator[](unsigned int i)
		{
			if (i >= this->_size || this->_arr == NULL)
			{
				std::cout << "index: " << i << std::endl;
				throw Array<ARRAY>::OutOfBoundsException();
			}
			return (this->_arr[i]);
		}

		unsigned int size() const
		{
			return (this->_size);
		}

};

template <typename ARRAY>

const char *Array<ARRAY>::OutOfBoundsException::what() const throw()
{
	return ("Error: Index out of bounds");
}