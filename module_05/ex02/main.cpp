/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:47:43 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/09 17:51:10 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		try
		{
			Form f0("2JZ-GTE", 0, 5);
			std::cout << f0 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n --------------------- \n\n";

	{
		try
		{
			Bureaucrat filip("Filip", 15);
			Form form("RB26DETT", 20, 45);
			std::cout << filip << std::endl;
			std::cout << form << std::endl;
			filip.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";

	{
		try
		{
			Bureaucrat hermes("Hermes", 35);
			Form form2("1UZ-FE", 20, 45);
			std::cout << hermes << std::endl;
			std::cout << form2 << std::endl;
			hermes.signForm(form2);
			std::cout << form2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
