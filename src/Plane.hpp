//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//																													//
//	author: 		Marcus Trautmann, marcus.trautmann@outlook.com													//
//																													//
//	date:			24.03.2015																						//
//																													//
//	description: 	Plane class for geometric algebra																//
//																													//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

#include "Plane.h"

#ifndef ALGEBRA_PLANE_CPP
#define ALGEBRA_PLANE_CPP

namespace geomalg
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

}


#endif // ALGEBRA_PLANE_CPP









