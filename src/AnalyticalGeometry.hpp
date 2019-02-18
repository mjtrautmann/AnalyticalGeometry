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


#ifndef ALGEBRA_HCPP
#define ALGEBRA_HCPP

#include "AnalyticalGeometry.h"
#include <cmath>

namespace analyticalgeom
{

	inline double AnalyticalGeometry::angle
	(
		const Coordinate & a,
		const Coordinate & b
	)
	{
		return std::acos(a*b / (a.length()*b.length() + 1e-50));
	}

	inline double AnalyticalGeometry::angleDeg
	(
		const Coordinate & a,
		const Coordinate & b
	)
	{
		return std::acos(a*b / (a.length()*b.length() + 1e-50)) * 180 / 3.14159265359;
	}

	inline double AnalyticalGeometry::distance
	(
		const Plane& a,
		const Coordinate& b
	)
	{
		return std::abs(a.n()*b - a.d()) / a.n().length();
	}

	inline Coordinate AnalyticalGeometry::projection
	(
		const Line& a,
		const Coordinate& b
	)
	{
		return AnalyticalGeometry::cut(Plane(b, a.direction()), a);
	}

	inline Coordinate AnalyticalGeometry::projection
	(
		const Plane& a,
		const Coordinate& b
	)
	{
		return AnalyticalGeometry::cut(a, Line(b, b+a.n()));
	}


	inline double AnalyticalGeometry::distance
	(
		const Coordinate& a,
		const Coordinate& b
	)
	{
		return (a - b).length();
	}


	inline double AnalyticalGeometry::distance
	(
		const Line& a,
		const Coordinate& b
	)
	{
		return (AnalyticalGeometry::projection(a, b) - b).length();
	}


	inline double AnalyticalGeometry::distance
	(
		const Line& a,
		const Line& b
	)
	{
		if (AnalyticalGeometry::isParallel(a, b))
			return AnalyticalGeometry::distance(a, b.spawn());
		Plane plane(a.spawn(), acrossb(a.direction(), b.direction()));
		return AnalyticalGeometry::distance(plane, b.spawn());
	}


	inline bool AnalyticalGeometry::isParallel
	(
		const Plane & p1,
		const Plane & p2
	)
	{
		auto ndotn = std::abs(p1.n() * p2.n());
		return ndotn > (1 - 1e-10);
	}

	inline bool AnalyticalGeometry::isParallel
	(
		const Line & a,
		const Line & b
	)
	{
		auto ndotn = std::abs(a.direction()*b.direction());
		auto nn = a.direction().length() * b.direction().length();
		return ndotn > (1 - 1e-10)*nn;
	}

	inline bool AnalyticalGeometry::isParallel
	(
		const Plane & p,
		const Line & l
	)
	{
		double nb;
		nb = p.n() * l.direction();
		// check for singularity and return
		return (std::abs(nb) < 1e-10);
	}



	inline Coordinate AnalyticalGeometry::cut
	(
		const Plane & p,
		const Line & l
	)
	{
		double na, nb, t;
		nb = p.n() * l.direction();
		// check for singularity
		if (nb == 0) return Coordinate(0,0,0);
		na = p.n() * l.spawn();
		t = (p.d() - na) / nb;
		
		return (l.spawn() + t * l.direction());
	}

}

#endif // GEOMETRY_CPP









