/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:49:44 by yuliano           #+#    #+#             */
/*   Updated: 2026/01/02 13:41:49 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed():Raw(0)
{
	std::cout<<"Default constructor\n";
}

//num << bits ≡ num * (2^bits)
Fixed::Fixed(const int num)
{
	std::cout<<"int constructor called\n";
	Raw = num << bits;
}


Fixed::Fixed(const float num)
{
	Raw = roundf(num * (1 << bits));
}


Fixed::Fixed(const Fixed& _Fixed):Raw(_Fixed.Raw)
{
	std::cout<<"copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& _Fixed)
{
	if(this != &_Fixed)
	{
		Raw = _Fixed.Raw;
	}
	std::cout<<"copy assignmet operator called\n";
	return (*this);
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called\n";
	return (Raw);
}

void Fixed::setRawBits(const int raw)
{
	std::cout<<"setRawBits member function called\n";
	Raw = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(Raw) / static_cast<float>(1 << bits));
}

int Fixed::toInt(void) const
{
	return (Raw >> bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& _Fixed)
{
	out << _Fixed.toFloat();
	return out;
}
