//	
//	author: 		Marcus Trautmann
//	date:			16.11.2018
//	description: 	Coordinate class for analytical geometry operations
//	
//	
//	MIT License
//	
//	Copyright (c) 2018 mjtrautmann
//	
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//	
//	The above copyright notice and this permission notice shall be included in all
//	copies or substantial portions of the Software.
//	
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//	SOFTWARE.
//	



#ifndef GEOMETRY_COORDINATE_HPP
#define GEOMETRY_COORDINATE_HPP

#include "Coordinate.h"

namespace analyticalgeom
{

	std::string Coordinate::print() const
	{
		std::stringstream stream;
		stream << '(' << _x << ',' << _y << ',' << _z << ')';
		return stream.str();
	}



	inline void Coordinate::setCoord(const double & x, const double & y, const double & z)
	{
		_x = x;
		_y = y;
		_z = z;
	}
		
	inline Coordinate Coordinate::rotateX(double alpha) const
	{
		Coordinate c;
		double alpharad = alpha * PI / 180.;
		
		c._x = _x;
		c._y = cos(alpharad) * _y - sin(alpharad) * _z;
		c._z = sin(alpharad) * _y + cos(alpharad) * _z;
		
		return c;
	}

	inline Coordinate Coordinate::rotateY(double alpha) const
	{
		Coordinate c;
		double alpharad = alpha * PI / 180.;
		
		c._x = cos(alpharad) * _x + sin(alpharad) * _z;
		c._y = _y;
		c._z = - sin(alpharad) * _x + cos(alpharad) * _z;
		
		return c;
	}

	inline Coordinate Coordinate::rotateZ(double alpha) const
	{
		Coordinate c;
		double alpharad = alpha * PI / 180.;
		
		c._x = cos(alpharad) * _x - sin(alpharad) * _y;
		c._y = sin(alpharad) * _x + cos(alpharad) * _y;
		c._z = _z;
		
		return c;
	}

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Operators

	inline Coordinate &Coordinate::operator = (const Coordinate &a)
	{
		this->_x = a._x;
		this->_y = a._y;
		this->_z = a._z;
		
		return *this;
	}

	inline Coordinate &Coordinate::operator = (const double a)
	{
		this->_x = a;
		this->_y = a;
		this->_z = a;
		
		return *this;
	}

	inline double Coordinate::operator *
	(
		const Coordinate &b
	) const
	{
		return (_x * b._x + _y * b._y + _z * b._z);
	}

	inline Coordinate operator *
	(
		const double alpha,
		const Coordinate &a
	)
	{
		return Coordinate(alpha * a.x(), alpha * a.y(), alpha * a.z());
	}

	inline Coordinate Coordinate::operator * 
	(
		const double & alpha
	) const
	{
		return Coordinate(alpha * _x, alpha * _y, alpha * _z);
	}

	inline Coordinate Coordinate::operator / 
	(
		const double & alpha
	) const
	{
		return Coordinate(_x / alpha, _y / alpha, _z / alpha);
	}

	inline Coordinate Coordinate::operator + 
	(
		const Coordinate &b
	) const
	{
		return Coordinate(_x + b._x, _y + b._y, _z + b._z);
	}

	inline Coordinate Coordinate::operator - 
	(
		const Coordinate &b
	) const
	{
		return Coordinate(_x - b._x, _y - b._y, _z - b._z);
	}

	inline Coordinate & Coordinate::operator +=
	(
		const Coordinate &b
	)
	{
		_x += b._x;
		_y += b._y;
		_z += b._z;
		return *this;
	}

	inline Coordinate & Coordinate::operator -=
	(
		const Coordinate &b
	)
	{
		_x -= b._x;
		_y -= b._y;
		_z -= b._z;
		return *this;
	}

	inline Coordinate operator +
	(
		const Coordinate &a
	)
	{
		return a;
	}

	inline Coordinate operator -
	(
		const Coordinate &a
	)
	{
		return Coordinate(-a._x, -a._y, -a._z);
	}

	inline bool Coordinate::operator <
	(
		const Coordinate &b
	) const
	{
		return (length() < b.length()) ?true:false;
	}

	inline bool Coordinate::operator >
	(
		const Coordinate &b
	) const
	{
		return (length() > b.length()) ?true:false;
	}

	inline Coordinate pointwiseamulb(const Coordinate &a, const Coordinate &b)
	{
		Coordinate c;
		
		c._x = a._x * b._x;
		c._y = a._y * b._y;
		c._z = a._z * b._z;
		
		return c;
	}

	inline Coordinate pointwiseadivb(const Coordinate &a, const Coordinate &b)
	{
		Coordinate c;
		
		c._x = a._x / b._x;
		c._y = a._y / b._y;
		c._z = a._z / b._z;
		
		return c;
	}

	inline Coordinate acrossb(const Coordinate &a, const Coordinate&b)
	{
		Coordinate c;
		c._x = a._y * b._z - a._z * b._y;
		c._y = a._z * b._x - a._x * b._z;
		c._z = a._x * b._y - a._y * b._x;
		
		return c;
	}

}





#endif // GEOMETRY_COORDINATE_CPP







