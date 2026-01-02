/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:53:48 by yuliano           #+#    #+#             */
/*   Updated: 2026/01/02 23:14:34 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <ostream>

class Fixed
{
	private:
	
	int Raw;
	const static int bits = 8;
	
	public:
	
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &_Fixed);
	Fixed &operator =(const Fixed& other);
	bool	operator ==(const Fixed& other) const;
	bool	operator >(const Fixed& other) const;
	bool	operator <(const Fixed& other) const;
	bool	operator >=(const Fixed& other) const;
	bool	operator <=(const Fixed& other) const;
	bool	operator !=(const Fixed& other) const;
	Fixed	operator +(const Fixed& other) const;
	Fixed	operator -(const Fixed& other) const;
	Fixed	operator /(const Fixed& other) const;
	Fixed	operator *(const Fixed& other) const;
	Fixed	operator++(int);
	Fixed&	operator++(void);
	Fixed	operator--(int);
	Fixed&	operator--(void);
	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
};

std::ostream& operator<<(std::ostream& out, const Fixed& _Fixed);
#endif