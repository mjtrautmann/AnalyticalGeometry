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

// Test
#include "analyticalGeometry.h"

#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H

namespace analyticalgeom
{
	
	class Line
	{
		public:
		
			constexpr Line();
			explicit Line(const Coordinate& a, const Coordinate& b);

			std::string print() const;
		
			constexpr const Coordinate& spawn() const			{return _spawn;}
			constexpr const Coordinate& direction() const		{return _direction;}
		
			constexpr void setSpawn(const Coordinate& a)		{_spawn = a;}
			constexpr void setDirection(const Coordinate& a)	{_direction = a;}
			void setPoints(const Coordinate& a, const Coordinate& b);
		
		protected:
		
			Coordinate _spawn, _direction;
	};


	inline std::ostream& operator<< (std::ostream& stream, const analyticalgeom::Line& l)
	{
		stream << l.print();
		return stream;
	}
	
}


#include "Line.hpp"

#endif // GEOMETRY_LINE_H






