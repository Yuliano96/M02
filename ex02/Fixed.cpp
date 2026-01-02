/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:49:44 by yuliano           #+#    #+#             */
/*   Updated: 2026/01/02 23:17:14 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed():Raw(0)
{
	std::cout<<"Default constructor\n";
}

//num << bits = num * (2^bits)
Fixed::Fixed(const int num)
{
	std::cout<<"int constructor called\n";
	Raw = num << bits;
}


Fixed::Fixed(const float num)
{
	std::cout<<"float contructor called\n";
	Raw = roundf(num * (1 << bits));
}


Fixed::Fixed(const Fixed& _Fixed):Raw(_Fixed.Raw)
{
	std::cout<<"copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if(this != &other)
	{
		Raw = other.Raw;
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

bool Fixed::operator==(const Fixed& other) const
{
	return (this->Raw == other.Raw);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->Raw > other.Raw);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->Raw < other.Raw);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->Raw >= other.Raw);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->Raw <= other.Raw);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->Raw != other.Raw);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed f;
	f.Raw = this->Raw + other.Raw;
	return (f);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed f;
	f.Raw = this->Raw - other.Raw;
	return (f);
}
/*>> bits equivale a dividir por 2^bits*/
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed		f;
	long long	aux;

	aux = (long long)this->Raw * (long long)other.Raw;
	f.Raw = (int)(aux >> bits);
	return (f);
}


/*<< bits equivale a multiplicar por 2^bits*/
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed		f;
	long long	aux;

	if (other.Raw == 0)
	{
		f.Raw = 0;
		return (f);
	}
	aux = ((long long)this->Raw << bits);
	f.Raw = (int)(aux / other.Raw);
	return (f);
}

Fixed Fixed::operator++(int)
{
	Fixed temp;
	temp = (*this);
	this->Raw += 1;
	return (temp);
	
}

Fixed& Fixed::operator++(void)
{
	this->Raw += 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->Raw -= 1;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	this->Raw -= 1;
	return (*this);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a < b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& _Fixed)
{
	out << _Fixed.toFloat();
	return out;
}
