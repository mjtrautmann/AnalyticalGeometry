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



#pragma once

#include "Coordinate2D.h"

namespace analyticalgeom
{

	inline std::string Coordinate2D::print() const
	{
		std::stringstream stream;
		stream << '(' << m_x << ',' << m_y << ')';
		return stream.str();
	}



	constexpr void Coordinate2D::setCoord(floattype x, floattype y)
	{
		m_x = x;
		m_y = y;
	}
	

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Operators

	constexpr Coordinate2D &Coordinate2D::operator = (const Coordinate2D &a)
	{
		m_x = a.x();
		m_y = a.y();
		
		return *this;
	}

	constexpr Coordinate2D &Coordinate2D::operator = (const floattype a)
	{
		m_x = a;
		m_y = a;
		
		return *this;
	}

	constexpr floattype Coordinate2D::operator *
	(
		const Coordinate2D &b
	) const
	{
		return (m_x * b.x() + m_y * b.y());
	}

	constexpr Coordinate2D operator *
	(
		floattype alpha,
		const Coordinate2D &a
	)
	{
		return Coordinate2D(alpha * a.x(), alpha * a.y());
	}

	constexpr Coordinate2D Coordinate2D::operator * 
	(
		floattype alpha
	) const
	{
		return Coordinate2D(alpha * m_x, alpha * m_y);
	}

	constexpr Coordinate2D Coordinate2D::operator / 
	(
		floattype alpha
	) const
	{
		return Coordinate2D(m_x / alpha, m_y / alpha);
	}

	constexpr Coordinate2D Coordinate2D::operator + 
	(
		const Coordinate2D &b
	) const
	{
		return Coordinate2D(m_x + b.x(), m_y + b.y());
	}

	constexpr Coordinate2D Coordinate2D::operator - 
	(
		const Coordinate2D &b
	) const
	{
		return Coordinate2D(m_x - b.x(), m_y - b.y());
	}

	constexpr Coordinate2D & Coordinate2D::operator +=
	(
		const Coordinate2D &b
	)
	{
		m_x += b.x();
		m_y += b.y();
		return *this;
	}

	constexpr Coordinate2D & Coordinate2D::operator -=
	(
		const Coordinate2D &b
	)
	{
		m_x -= b.x();
		m_y -= b.y();
		return *this;
	}

	constexpr Coordinate2D operator +
	(
		const Coordinate2D &a
	)
	{
		return a;
	}

	constexpr Coordinate2D operator -
	(
		const Coordinate2D &a
	)
	{
		return Coordinate2D(-a.x(), -a.y());
	}

	inline bool Coordinate2D::operator ==
	(
		const Coordinate2D &b
	)
	{
		return std::abs(this->x()-b.x()) < analyticalgeom::epsilon()
			&& std::abs(this->y()-b.y()) < analyticalgeom::epsilon();
	}

	constexpr floattype dot(floattype d1, floattype d2, const Coordinate2D & c)
	{
		return d1 * c.x() + d2 * c.y();
	}

	constexpr Coordinate2D pointwiseamulb(const Coordinate2D &a, const Coordinate2D &b)
	{
		auto x = a.x() * b.x();
		auto y = a.y() * b.y();
		return Coordinate2D(x, y);
	}

	constexpr Coordinate2D pointwiseadivb(const Coordinate2D &a, const Coordinate2D &b)
	{
		auto x = a.x() / b.x();
		auto y = a.y() / b.y();
		
		return Coordinate2D(x, y);
	}

	constexpr floattype acrossb(const Coordinate2D &a, const Coordinate2D&b)
	{
		auto z = a.x() * b.y() - a.y() * b.x();
		return z;
	}
}









