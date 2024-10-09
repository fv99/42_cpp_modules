/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:56:09 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/09 17:47:51 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const size_t _gsign;
		const size_t _gexec;
		bool _signed;

	public:
		// constructors
		Form(void);
		Form(std::string const &name, size_t const &gsign, size_t const &gexec);
		Form(Form const &copy);

		// destructor
		~Form(void);

		// overloaded =
		Form const &operator=(const Form &copy);

		// signer
		void beSigned(Bureaucrat &bureaucrat);

		// getters
		const std::string getName(void)const;
		size_t getSignGrade(void)const;
		size_t getExecGrade(void)const;
		bool getSigned(void)const;

		// exceptions
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &ret, Form const &form);
