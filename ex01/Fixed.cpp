/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:28:24 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/07 22:09:40 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//scope resolution operator
Fixed::Fixed() : _value(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ) {

	this->_value = num << Fixed::_fractionBits;
	
	std::cout << "Int constructor called on ";
	std::cout << num << " << " << Fixed::_fractionBits;
	std::cout << " is " << this->_value << std::endl;
}

Fixed::Fixed( const float num ) {

	this->_value = roundf( num * ( 1 << Fixed::_fractionBits ));
	
	std::cout << "Float constructor called on ";
	std::cout << "roundf of " << num << "  * ( 1 <<  " << Fixed::_fractionBits << " ) ";
	std::cout << " is " << this->_value << std::endl;
}

//copy constructor
Fixed::Fixed( const Fixed& other) {

	*this = other;
	// this->_value = other._value;
	
	std::cout << "Copy constructor called" << std::endl;
}

//overload operator
Fixed& Fixed::operator = ( const Fixed& other) {
	
	if( this != &other) {
		this->_value = other.getRawBits();
		// this->_value = other._value;
	}
	
	std::cout << "Copy assignation operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	
	std::cout << "getRawBits member function called on ";
	std::cout << this->_value << std::endl;
	
	return this->_value;
}	
	
void Fixed::setRawBits( int const raw ) {

	this->_value = raw;

	std::cout << "setRawBits member function called to set ";
	std::cout << this->_value << std::endl;
}

float Fixed::toFloat( void ) const {

	float fnum;
	
	fnum = (float)this->_value / ( 1 << Fixed::_fractionBits );

	std::cout << "Fixed to Float conversion of ";
	std::cout << this->_value << " / ( 1 << " << Fixed::_fractionBits << " ) ";
	std::cout << " is " << fnum << std::endl;
	
	return fnum;
}

int Fixed::toInt( void ) const {

	int num;

	num = this->_value >> Fixed::_fractionBits;

	std::cout << "Fixed to Int conversion of ";
	std::cout << this->_value << " << " << Fixed::_fractionBits;
	std::cout << " is " << num << std::endl;

	return num;
}

std::ostream &operator<<( std::ostream& str, const Fixed& other_num ) { // Overload of the insertion operator (<<) using the public member function

	return (str << other_num.toFloat());
}	