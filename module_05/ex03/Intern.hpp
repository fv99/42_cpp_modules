/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:54:48 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/14 15:48:59 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



class Intern
{
	public:
		Intern();
		Intern(const Intern &src);

		~Intern();

		Intern &operator=(const Intern &src);
		Form *makeForm(const std::string name, const std::string target);
};
