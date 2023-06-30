/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:27:25 by vgejno            #+#    #+#             */
/*   Updated: 2023/06/29 17:23:07 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

	private:
		int _numFixedPoint;
		static const int _fractionBits = 8;

	public:
		Fixed();
		~Fixed();
		//copy constructor
		Fixed( const Fixed& copy);
		//overload operator
		Fixed& operator = ( const Fixed& fixed);
		
		int getRawBits( void ) const; //returns raw value of the fixed_point value
		void setRawBits( int const raw );
			
};

#endif