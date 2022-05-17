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
	
	class Line2D
	{
		public:
		
			constexpr Line2D();
			explicit Line2D(const Coordinate2D& a, const Coordinate2D& b);

			std::string print() const;
		
			constexpr const Coordinate2D& spawn() const			{return _spawn;}
			constexpr const Coordinate2D& direction() const		{return _direction;}
		
			constexpr void setSpawn(const Coordinate2D& a)		{_spawn = a;}
			constexpr void setDirection(const Coordinate2D& a)	{_direction = a;}
			void setPoints(const Coordinate2D& a, const Coordinate2D& b);
		
		protected:
		
			Coordinate2D _spawn, _direction;
	};


	inline std::ostream& operator<< (std::ostream& stream, const analyticalgeom::Line2D& l)
	{
		stream << l.print();
		return stream;
	}
	
}


#include "Line2D.hpp"






