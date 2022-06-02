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

#pragma once

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <sstream>

namespace analyticalgeom
{
	typedef float floattype;
	class Coordinate;
	class Line;
	class Plane;
	class Coordinate2D;
	class Line2D;
	
	constexpr floattype pi() { return static_cast<floattype>(3.141592653589793); }
	constexpr floattype epsilon() { return static_cast<floattype>(1e-6); }
	
	class AnalyticalGeometry
	{
	
		public:
			static floattype angle(const Coordinate& a, const Coordinate& b);
			static floattype angleDeg(const Coordinate& a, const Coordinate& b);

			static Coordinate projection(const Line& a, const Coordinate& b);
			static Coordinate projection(const Plane& a, const Coordinate& b);

			static floattype distance(const Coordinate& a, const Coordinate& b);
			static floattype distance(const Line& a, const Coordinate& b);
			static floattype distance(const Line& a, const Line& b);
			static floattype distance(const Plane& a, const Coordinate& b);

			static bool isParallel(const Plane & p1, const Plane & p2);
			static bool isParallel(const Plane & p, const Line & l);
			static bool isParallel(const Line & a, const Line & b);
			static Coordinate cut(const Plane & p, const Line & l);
			

			static floattype angle(const Coordinate2D& a, const Coordinate2D& b);
			static floattype angleDeg(const Coordinate2D& a, const Coordinate2D& b);

			static Coordinate2D projection(const Line2D& a, const Coordinate2D& b);

			static floattype distance(const Coordinate2D& a, const Coordinate2D& b);
			static floattype distance(const Line2D& a, const Coordinate2D& b);
			static floattype distance(const Line2D& a, const Line2D& b);
			static floattype distance(const Plane& a, const Coordinate2D& b);

			static bool isParallel(const Line2D & a, const Line2D & b);
			static Coordinate2D cut(const Line2D & p, const Line2D & l);

	};

}


#include "Coordinate.h"
#include "Line.h"
#include "Plane.h"
#include "Coordinate2D.h"
#include "Line2D.h"
#include "AnalyticalGeometry.hpp"




