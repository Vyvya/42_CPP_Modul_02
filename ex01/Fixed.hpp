/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:27:25 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/07 21:38:54 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

	private:
		int _value;
		static const int _fractionBits = 8;

	public:
		Fixed();
		//polymorphism == function overload
		Fixed( const int num );
		//copy constructor
		Fixed( const float num );
		//overload operator
		Fixed( const Fixed &other );
		~Fixed();
		
		Fixed &operator = ( const Fixed &other );
		
		void setRawBits( int const raw );
		int getRawBits( void ) const; //returns raw value of the fixed_point value
		
		float toFloat( void ) const; //converts the fixed-point value to a floating-point value
		int toInt( void ) const; //converts the fixed-point value to an integer value

		float getFloatRepresentation() const; // Public member function to retrieve the floating-point representation
};

std::ostream &operator << ( std::ostream &str, Fixed const &rhs );

#endif