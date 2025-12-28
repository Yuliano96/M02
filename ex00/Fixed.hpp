/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:53:48 by yuliano           #+#    #+#             */
/*   Updated: 2025/12/28 19:58:40 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
	
	int Raw;
	const static int bits = 8;
	
	public:
	
	Fixed();
	Fixed(const Fixed &_Fixed);
	Fixed &operator = (const Fixed& _Fixed);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	
};

#endif