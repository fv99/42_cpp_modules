/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:21:15 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/16 17:33:49 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    try
    {
        Convert converter(argv[1]);
        std::cout << converter;
    }
    catch (const Convert::ErrorThrow& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
