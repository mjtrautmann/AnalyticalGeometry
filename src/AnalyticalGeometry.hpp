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


#ifndef ALGEBRA_HPP
#define ALGEBRA_HPP

#include "analyticalGeometry.h"
#include <cmath>

namespace analyticalgeom
{

	inline floattype AnalyticalGeometry::angle
	(
		const Coordinate & a,
		const Coordinate & b
	)
	{
		return std::acos(a*b / (a.length()*b.length() + static_cast<floattype>(1e-50)));
	}

	inline floattype AnalyticalGeometry::angleDeg
	(
		const Coordinate & a,
		const Coordinate & b
	)
	{
		return std::acos(a*b / (a.length()*b.length() + static_cast<floattype>(1e-50))) * static_cast<floattype>(180) / static_cast<floattype>(3.14159265359);
	}

	inline floattype AnalyticalGeometry::distance
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


	inline floattype AnalyticalGeometry::distance
	(
		const Coordinate& a,
		const Coordinate& b
	)
	{
		return (a - b).length();
	}


	inline floattype AnalyticalGeometry::distance
	(
		const Line& a,
		const Coordinate& b
	)
	{
		return (AnalyticalGeometry::projection(a, b) - b).length();
	}


	inline floattype AnalyticalGeometry::distance
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
		auto axb = acrossb(p1.n(), p2.n()).length();
		return (std::abs(axb) < analyticalgeom::epsilon());
	}

	inline bool AnalyticalGeometry::isParallel
	(
		const Line & a,
		const Line & b
	)
	{
		auto axb = acrossb(a.direction(), b.direction()).length();
		return (std::abs(axb) < analyticalgeom::epsilon());
	}

	inline bool AnalyticalGeometry::isParallel
	(
		const Plane & p,
		const Line & l
	)
	{
		floattype nb;
		nb = p.n() * l.direction();
		// check for singularity and return
		return (std::abs(nb) < analyticalgeom::epsilon());
	}



	inline Coordinate AnalyticalGeometry::cut
	(
		const Plane & p,
		const Line & l
	)
	{
		floattype na, nb, t;
		nb = p.n() * l.direction();
		// check for singularity
		if (std::abs(nb) < analyticalgeom::epsilon()) return Coordinate(0,0,0);
		na = p.n() * l.spawn();
		t = (p.d() - na) / nb;
		
		return (l.spawn() + t * l.direction());
	}

}

#endif // ALGEBRA_HPP









