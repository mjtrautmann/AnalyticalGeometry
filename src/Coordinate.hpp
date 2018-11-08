//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//																													//
//	author: 		Marcus Trautmann, marcus.trautmann@outlook.com													//
//																													//
//	date:			24.03.2015																						//
//																													//
//	description: 	Coordinate class for geometric algebra															//
//																													//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


#include "Coordinate.h"

#ifndef ALGEBRA_COORDINATE_CPP
#define ALGEBRA_COORDINATE_CPP

namespace geomalg
{

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Setter
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





#endif // ALGEBRA_COORDINATE_CPP







