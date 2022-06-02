//	MIT License
//	
//	Copyright (c) 2022 mjtrautmann
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

#include "analyticalGeometry.h"


namespace analyticalgeom
{
		
	class Coordinate
	{
		public:
		
			constexpr Coordinate() :m_x(0), m_y(0), m_z(0) {};
			constexpr explicit Coordinate(floattype x, floattype y, floattype z) : m_x(x), m_y(y), m_z(z) {};

			std::string print() const;
			
			constexpr auto & x() const			{return m_x;}
			constexpr auto & y() const			{return m_y;}
			constexpr auto & z() const			{return m_z;}
			const auto length() const			{return std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z);}
			const auto ex() const				{return m_x / std::max(length(), static_cast<floattype>(1e-50));}
			const auto ey() const				{return m_y / std::max(length(), static_cast<floattype>(1e-50));}
			const auto ez() const				{return m_z / std::max(length(), static_cast<floattype>(1e-50));}
			
			constexpr void setx(floattype x)			{m_x = x;}
			constexpr void sety(floattype y)			{m_y = y;}
			constexpr void setz(floattype z)			{m_z = z;}
			constexpr void setCoord(floattype x, floattype y, floattype z);
			
			Coordinate rotateX(floattype alpha) const;
			Coordinate rotateY(floattype alpha) const;
			Coordinate rotateZ(floattype alpha) const;
			
			
			constexpr Coordinate & operator = (const Coordinate &a);
			constexpr Coordinate & operator = (const floattype a);
			
			constexpr floattype operator * (const Coordinate &b) const;
			constexpr Coordinate friend operator * (floattype alpha, const Coordinate &a);
			constexpr Coordinate operator * (floattype alpha) const;
			constexpr Coordinate operator / (floattype alpha) const;
			
			constexpr Coordinate operator + (const Coordinate &b) const;
			constexpr Coordinate operator - (const Coordinate &b) const;
			constexpr Coordinate & operator += (const Coordinate& b);
			constexpr Coordinate & operator -= (const Coordinate& b);
			constexpr Coordinate friend operator + (const Coordinate &a);
			constexpr Coordinate friend operator - (const Coordinate &a);

			inline bool operator==(const Coordinate& b);
		
		private:

			floattype m_x;
			floattype m_y;
			floattype m_z;
	};

	inline std::ostream& operator<< (std::ostream& stream, const analyticalgeom::Coordinate& c)
	{
		stream << c.print();
		return stream;
	}
}

#include "Coordinate.hpp"
