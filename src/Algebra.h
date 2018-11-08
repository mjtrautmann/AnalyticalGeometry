//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//																													//
//	author: 		Marcus Trautmann, marcus.trautmann@outlook.com													//
//																													//
//	date:			13.02.2015																						//
//																													//
//	description: 	Geometric Algebra class to hold functions for calculations										//
//																													//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//



#ifndef ALGEBRA_H
#define ALGEBRA_H

#define PI 3.141592653589793

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

#include "Coordinate.h"
#include "Line.h"
#include "Plane.h"

namespace geomalg
{

	class Algebra
	{
	
	public:
		static double angle(const Coordinate& a, const Coordinate& b);
		static double angleDeg(const Coordinate& a, const Coordinate& b);

		static Coordinate projection(const Line& a, const Coordinate& b);

		static double distance(const Coordinate& a, const Coordinate& b);
		static double distance(const Line& a, const Coordinate& b);
		static double distance(const Line& a, const Line& b);
		static double distance(const Plane& a, const Coordinate& b);
		
		static bool isParallel(const Plane & p, const Line & l);
		static bool isParallel(const Line & a, const Line & b);
		static Coordinate cut(const Plane & p, const Line & l);

	};

}

#include "Algebra.hpp"


#endif // ALGEBRA_H


