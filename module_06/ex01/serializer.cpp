/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:01:17 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/17 16:13:36 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &) {}

Serializer &Serializer::operator=(const Serializer &)
{
    return *this;
}

Serializer::~Serializer() {}

// use reinterpret_cast to convert data* pointer into a uintptr_t integer
// uintptr now holds the adress of data object
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// use reinterpret_cast again to convert the pointer into the data struct
// should point to the same memory address
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
