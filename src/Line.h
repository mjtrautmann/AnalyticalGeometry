//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//																													//
//	author: 		Marcus Trautmann, marcus.trautmann@outlook.com													//
//																													//
//	date:			24.03.2015																						//
//																													//
//	description: 	Line class for geometric algebra																//
//																													//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


#include "Algebra.h"

#ifndef ALGEBRA_LINE_H
#define ALGEBRA_LINE_H

namespace geomalg
{
	
	class Line
	{
		public:
		
			Line();
			Line(const Coordinate& a, const Coordinate& b);
		
			const Coordinate& spawn() const			{return _spawn;}
			const Coordinate& direction() const		{return _direction;}
		
			void setSpawn(const Coordinate& a)		{_spawn = a;}
			void setDirection(const Coordinate& a)	{_direction = a;}
			void setPoints(const Coordinate& a, const Coordinate& b);
		
		protected:
		
			Coordinate _spawn, _direction;
	};
	
	
}


#include "Line.hpp"

#endif // ALGEBRA_LINE_H






