//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//																													//
//	author: 		Marcus Trautmann, marcus.trautmann@outlook.com													//
//																													//
//	date:			24.03.2015																						//
//																													//
//	description: 	Plane class for geometric algebra																//
//																													//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


#include "Algebra.h"

#ifndef ALGEBRA_PLANE_H
#define ALGEBRA_PLANE_H

namespace geomalg
{
		
	class Plane
	{
		public:
		
			Plane();
			Plane(const Coordinate& a, const Coordinate& b, const Coordinate& c);
			Plane(const Coordinate& x, const Coordinate& n);
		
			const Coordinate& n() const			{return _n;}
			const double& d() const				{return _d;}
		
		
		
		protected:
		
			Coordinate _n;
			double _d;
	};

}



#include "Plane.hpp"

#endif // ALGEBRA_PLANE_H




