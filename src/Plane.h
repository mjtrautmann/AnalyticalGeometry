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



#include "AnalyticalGeometry.h"

#ifndef GEOMETRY_PLANE_H
#define GEOMETRY_PLANE_H

namespace analyticalgeom
{
		
	class Plane
	{
		public:
		
			Plane();
			Plane(const Coordinate& a, const Coordinate& b, const Coordinate& c);
			Plane(const Coordinate& x, const Coordinate& n);

			std::string print() const;
		
			const Coordinate& n() const			{return _n;}
			const double& d() const				{return _d;}
		
		
		
		protected:
		
			Coordinate _n;
			double _d;
	};


	std::ostream& operator<< (std::ostream& stream, const analyticalgeom::Plane& p)
	{
		stream << p.print();
		return stream;
	}
}



#include "Plane.hpp"

#endif // GEOMETRY_PLANE_H




