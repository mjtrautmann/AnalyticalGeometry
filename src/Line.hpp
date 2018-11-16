//	
//	author: 		Marcus Trautmann
//	date:			16.11.2018
//	description: 	Line class for analytical geometry operations
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


#ifndef GEOMETRY_LINE_HPP
#define GEOMETRY_LINE_HPP

#include "Line.h"

namespace analyticalgeom
{

	inline Line::Line(){}

	inline Line::Line(const Coordinate& a, const Coordinate& b)
	{
		_spawn = a;
		_direction = (b-a) / (b-a).length();
	}

	std::string Line::print() const
	{
		std::stringstream stream;
		stream << '(' << _spawn.x() << ',' << _spawn.y() << ',' << _spawn.y() << ')';
		stream << "+t";
		stream << '(' << _direction.x() << ',' << _direction.y() << ',' << _direction.y() << ')';
		return stream.str();
	}

	inline void Line::setPoints(const Coordinate& a, const Coordinate& b)
	{
		_spawn = a;
		_direction = (b-a) / (b-a).length();
	}

}


#endif // GEOMETRY_LINE_CPP














