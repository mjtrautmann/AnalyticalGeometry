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

#include "Geometry.h"

#ifndef GEOMETRY_COORDINATE_H
#define GEOMETRY_COORDINATE_H


namespace analyticalgeom
{
		
	class Coordinate
	{
		public:
		
			Coordinate() :_x(0.), _y(0.), _z(0.) {};
			Coordinate(const double & x, const double & y, const double & z) : _x(x), _y(y), _z(z) {};
			
			
			const auto & x() const								{return _x;}
			const auto & y() const								{return _y;}
			const auto & z() const								{return _z;}
			auto ex() const										{return _x / std::max(length(), 1e-50);}
			auto ey() const										{return _y / std::max(length(), 1e-50);}
			auto ez() const										{return _z / std::max(length(), 1e-50);}
			double length() const								{return std::sqrt(_x*_x + _y*_y + _z*_z);}
			
			void setCoord(const double & x, const double & y, const double & z);
			void setx(const double & x)							{_x = x;}
			void sety(const double & y)							{_y = y;}
			void setz(const double & z)							{_z = z;}
			
			Coordinate rotateX(double alpha) const;
			Coordinate rotateY(double alpha) const;
			Coordinate rotateZ(double alpha) const;
			
			
			Coordinate & operator = (const Coordinate &a);
			Coordinate & operator = (const double a);
			
			double operator * (const Coordinate &b) const;
			Coordinate friend operator * (const double alpha, const Coordinate &a);
			Coordinate operator * (const double & alpha) const;
			Coordinate operator / (const double & alpha) const;
			
			Coordinate operator + (const Coordinate &b) const;
			Coordinate operator - (const Coordinate &b) const;
			Coordinate friend operator + (const Coordinate &a);
			Coordinate friend operator - (const Coordinate &a);
			Coordinate & operator += (const Coordinate& b);
			Coordinate & operator -= (const Coordinate& b);
			
			double friend dot(const double & d1, const double & d2, const double & d3, const Coordinate & c) {return d1 * c._x + d2 * c._y + d3 * c._z;}
			
			bool operator < (const Coordinate &b) const;
			bool operator > (const Coordinate &b) const;
			
			Coordinate friend pointwiseamulb(const Coordinate &a, const Coordinate &b);
			Coordinate friend pointwiseadivb(const Coordinate &a, const Coordinate &b);
			Coordinate friend acrossb(const Coordinate &a, const Coordinate&b);
			
		
		private:

			double _x;
			double _y;
			double _z;
	};

}

#include "Coordinate.hpp"

#endif // GEOMETRY_COORDINATE_H
