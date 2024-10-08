/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:47:43 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/09 17:24:20 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat github("github", 151);
			std::cout << github << std::endl;
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
			Bureaucrat stack("stackoverflow", 0);
			std::cout << stack << std::endl;
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
			Bureaucrat gpt("chatgpt", 3);
			std::cout << gpt << std::endl;
			gpt.incrementGrade();
			std::cout << gpt << std::endl;
			gpt.incrementGrade();
			std::cout << gpt << std::endl;
			gpt.incrementGrade();
			std::cout << gpt << std::endl;
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
			Bureaucrat googl("google", 148);
			std::cout << googl << std::endl;
			googl.decrementGrade();
			std::cout << googl << std::endl;
			googl.decrementGrade();
			std::cout << googl << std::endl;
			googl.decrementGrade();
			std::cout << googl << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
