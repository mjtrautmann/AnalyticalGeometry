//	
//	author: 		Marcus Trautmann
//	date:			16.11.2018
//	description: 	Analytical geometry class for analytical geometry operations
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



#ifndef GEOMETRY_H
#define GEOMETRY_H


#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <sstream>

#include "Coordinate.h"
#include "Line.h"
#include "Plane.h"

namespace analyticalgeom
{

	constexpr double pi() { return 3.141592653589793; }
	
	class AnalyticalGeometry
	{
	
		public:
			static double angle(const Coordinate& a, const Coordinate& b);
			static double angleDeg(const Coordinate& a, const Coordinate& b);

			static Coordinate projection(const Line& a, const Coordinate& b);
			static Coordinate projection(const Plane& a, const Coordinate& b);

			static double distance(const Coordinate& a, const Coordinate& b);
			static double distance(const Line& a, const Coordinate& b);
			static double distance(const Line& a, const Line& b);
			static double distance(const Plane& a, const Coordinate& b);
			
			static bool isParallel(const Plane & p, const Line & l);
			static bool isParallel(const Line & a, const Line & b);
			static Coordinate cut(const Plane & p, const Line & l);

	};

}

#include "AnalyticalGeometry.hpp"


#endif // GEOMETRY_H


