/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:28:24 by vgejno            #+#    #+#             */
/*   Updated: 2023/06/29 17:23:47 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//scope resolution operator
Fixed::Fixed() : _numFixedPoint(0) {

	std::cout << "Default constructor called" << std::endl;
	// this->_numFixedPoint = 0;
}

//copy constructor
Fixed::Fixed( const Fixed& copy) {

	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

//overload operator
Fixed& Fixed::operator = ( const Fixed& fixed ) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	if( this != &fixed) {
		this->_numFixedPoint = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return this->_numFixedPoint;
}	
	
void Fixed::setRawBits( int const raw ) {

	this->_numFixedPoint = raw;
}