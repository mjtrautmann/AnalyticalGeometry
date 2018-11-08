//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//																													//
//	author: 		Marcus Trautmann, marcus.trautmann@outlook.com													//
//																													//
//	date:			24.03.2015																						//
//																													//
//	description: 	Line class for geometric algebra																//
//																													//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


#include "Line.h"

#ifndef ALGEBRA_LINE_CPP
#define ALGEBRA_LINE_CPP

namespace geomalg
{

	inline Line::Line(){}

	inline Line::Line(const Coordinate& a, const Coordinate& b)
	{
		_spawn = a;
		_direction = (b-a) / (b-a).length();
	}

	inline void Line::setPoints(const Coordinate& a, const Coordinate& b)
	{
		_spawn = a;
		_direction = (b-a) / (b-a).length();
	}

}


#endif // ALGEBRA_LINE_CPP














