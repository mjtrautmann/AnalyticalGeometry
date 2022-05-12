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



#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include "coordinate.h"

namespace analyticalgeom
{

	inline std::string Coordinate::print() const
	{
		std::stringstream stream;
		stream << '(' << m_x << ',' << m_y << ',' << m_z << ')';
		return stream.str();
	}



	constexpr void Coordinate::setCoord(floattype x, floattype y, floattype z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
		
	inline Coordinate Coordinate::rotateX(floattype alpha) const
	{
		Coordinate c;
		floattype alpharad = alpha * analyticalgeom::pi() / 180.;
		
		c.m_x = m_x;
		c.m_y = cos(alpharad) * m_y - sin(alpharad) * m_z;
		c.m_z = sin(alpharad) * m_y + cos(alpharad) * m_z;
		
		return c;
	}

	inline Coordinate Coordinate::rotateY(floattype alpha) const
	{
		Coordinate c;
		floattype alpharad = alpha * analyticalgeom::pi() / static_cast<floattype>(180.);
		
		c.m_x = cos(alpharad) * m_x + sin(alpharad) * m_z;
		c.m_y = m_y;
		c.m_z = - sin(alpharad) * m_x + cos(alpharad) * m_z;
		
		return c;
	}

	inline Coordinate Coordinate::rotateZ(floattype alpha) const
	{
		Coordinate c;
		floattype alpharad = alpha * analyticalgeom::pi() / 180.;
		
		c.m_x = cos(alpharad) * m_x - sin(alpharad) * m_y;
		c.m_y = sin(alpharad) * m_x + cos(alpharad) * m_y;
		c.m_z = m_z;
		
		return c;
	}

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Operators

	constexpr Coordinate &Coordinate::operator = (const Coordinate &a)
	{
		m_x = a.x();
		m_y = a.y();
		m_z = a.z();
		
		return *this;
	}

	constexpr Coordinate &Coordinate::operator = (const floattype a)
	{
		m_x = a;
		m_y = a;
		m_z = a;
		
		return *this;
	}

	constexpr floattype Coordinate::operator *
	(
		const Coordinate &b
	) const
	{
		return (m_x * b.x() + m_y * b.y() + m_z * b.z());
	}

	constexpr Coordinate operator *
	(
		floattype alpha,
		const Coordinate &a
	)
	{
		return Coordinate(alpha * a.x(), alpha * a.y(), alpha * a.z());
	}

	constexpr Coordinate Coordinate::operator * 
	(
		floattype alpha
	) const
	{
		return Coordinate(alpha * m_x, alpha * m_y, alpha * m_z);
	}

	constexpr Coordinate Coordinate::operator / 
	(
		floattype alpha
	) const
	{
		return Coordinate(m_x / alpha, m_y / alpha, m_z / alpha);
	}

	constexpr Coordinate Coordinate::operator + 
	(
		const Coordinate &b
	) const
	{
		return Coordinate(m_x + b.x(), m_y + b.y(), m_z + b.z());
	}

	constexpr Coordinate Coordinate::operator - 
	(
		const Coordinate &b
	) const
	{
		return Coordinate(m_x - b.x(), m_y - b.y(), m_z - b.z());
	}

	constexpr Coordinate & Coordinate::operator +=
	(
		const Coordinate &b
	)
	{
		m_x += b.x();
		m_y += b.y();
		m_z += b.z();
		return *this;
	}

	constexpr Coordinate & Coordinate::operator -=
	(
		const Coordinate &b
	)
	{
		m_x -= b.x();
		m_y -= b.y();
		m_z -= b.z();
		return *this;
	}

	constexpr Coordinate operator +
	(
		const Coordinate &a
	)
	{
		return a;
	}

	constexpr Coordinate operator -
	(
		const Coordinate &a
	)
	{
		return Coordinate(-a.x(), -a.y(), -a.z());
	}

	const bool Coordinate::operator <
	(
		const Coordinate &b
	) const
	{
		return (length() < b.length()) ?true:false;
	}

	const bool Coordinate::operator >
	(
		const Coordinate &b
	) const
	{
		return (length() > b.length()) ?true:false;
	}

	constexpr floattype dot(floattype d1, floattype d2, floattype d3, const Coordinate & c)
	{
		return d1 * c.x() + d2 * c.y() + d3 * c.z();
	}

	constexpr Coordinate pointwiseamulb(const Coordinate &a, const Coordinate &b)
	{
		auto x = a.x() * b.x();
		auto y = a.y() * b.y();
		auto z = a.z() * b.z();
		return Coordinate(x, y, z);
	}

	constexpr Coordinate pointwiseadivb(const Coordinate &a, const Coordinate &b)
	{
		auto x = a.x() / b.x();
		auto y = a.y() / b.y();
		auto z = a.z() / b.z();
		
		return Coordinate(x, y, z);
	}

	constexpr Coordinate acrossb(const Coordinate &a, const Coordinate&b)
	{
		auto x = a.y() * b.z() - a.z() * b.y();
		auto y = a.z() * b.x() - a.x() * b.z();
		auto z = a.x() * b.y() - a.y() * b.x();
		
		return Coordinate(x, y, z);
	}

}





#endif // COORDINATE_HPP







