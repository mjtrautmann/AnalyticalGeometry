//	
//	author: 		Marcus Trautmann
//	date:			16.11.2018
//	description: 	Plane class for analytical geometry operations
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

#ifndef GEOMETRY_PLANE_HPP
#define GEOMETRY_PLANE_HPP

#include "Plane.h"

namespace analyticalgeom
{
	
	inline Plane::Plane() {}

	inline Plane::Plane
	(
		const Coordinate& a,
		const Coordinate& b,
		const Coordinate& c
	)
	{
		_n = acrossb(b-a, c-a);
		_n = _n / _n.length();
		_d = _n*a;
	}


	inline Plane::Plane
	(
		const Coordinate& x,
		const Coordinate& n
	){
		_n = n/n.length();
		_d = _n*x;
	}


	inline std::string Plane::print() const
	{
		std::stringstream stream;
		stream << "(x*(" << _n.x() << ',' << _n.y() << ',' << _n.z() << ')' << '=' << _d;
		return stream.str();
	}

}


#endif // GEOMETRY_PLANE_CPP









