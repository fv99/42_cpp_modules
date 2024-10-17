/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:58:51 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/17 16:01:07 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <stdint.h>

typedef struct s_Data
{
	std::string _str;
	int	_val;
}	Data;

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
