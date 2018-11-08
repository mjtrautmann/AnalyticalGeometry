//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//																													//
//	author: 		Marcus Trautmann, marcus.trautmann@outlook.com													//
//																													//
//	date:			13.02.2015																						//
//																													//
//	description: 	Geometric Algebra class to hold functions for calculations										//
//																													//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


#ifndef ALGEBRA_CPP
#define ALGEBRA_CPP

#include "Algebra.h"
#include <cmath>

namespace geomalg
{

	inline double Algebra::angle
	(
		const Coordinate & a,
		const Coordinate & b
	)
	{
		return std::acos(a*b / (a.length()*b.length() + 1e-50));
	}

	inline double Algebra::angleDeg
	(
		const Coordinate & a,
		const Coordinate & b
	)
	{
		return std::acos(a*b / (a.length()*b.length() + 1e-50)) * 180 / 3.14159265359;
	}

	inline double Algebra::distance
	(
		const Plane& a,
		const Coordinate& b
	)
	{
		return std::abs(a.n()*b - a.d()) / a.n().length();
	}

	inline Coordinate Algebra::projection
	(
		const Line& a,
		const Coordinate& b
	)
	{
		return Algebra::cut(Plane(b, a.direction()), a);
	}


	inline double Algebra::distance
	(
		const Coordinate& a,
		const Coordinate& b
	)
	{
		return (a - b).length();
	}


	inline double Algebra::distance
	(
		const Line& a,
		const Coordinate& b
	)
	{
		return (Algebra::projection(a, b) - b).length();
	}


	inline double Algebra::distance
	(
		const Line& a,
		const Line& b
	)
	{
		if (Algebra::isParallel(a, b))
			return Algebra::distance(a, b.spawn());
		Plane plane(a.spawn(), acrossb(a.direction(), b.direction()));
		return Algebra::distance(plane, b.spawn());
	}


	inline bool Algebra::isParallel
	(
		const Line & a,
		const Line & b
	)
	{
		auto ndotn = std::abs(a.direction()*b.direction());
		auto nn = a.direction().length() * b.direction().length();
		return ndotn > (1 - 1e-10)*nn;
	}

	inline bool Algebra::isParallel
	(
		const Plane & p,
		const Line & l
	)
	{
		double nb;
		nb = p.n() * l.direction();
		// check for singularity and return
		if (std::abs(nb) < 1e-50)
			return true;
		else
			return false;
	}



	inline Coordinate Algebra::cut
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

#endif // ALGEBRA_CPP









