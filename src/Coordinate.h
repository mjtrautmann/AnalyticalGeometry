//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//																													//
//	author: 		Marcus Trautmann, marcus.trautmann@outlook.com													//
//																													//
//	date:			24.03.2015																						//
//																													//
//	description: 	Coordinate class for geometric algebra															//
//																													//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


#include "Algebra.h"

#ifndef ALGEBRA_COORDINATE_H
#define ALGEBRA_COORDINATE_H


namespace geomalg
{
		
	class Coordinate
	{
		public:
			Coordinate() :_x(0.), _y(0.), _z(0.) {};
			Coordinate(const double & x, const double & y, const double & z) : _x(x), _y(y), _z(z) {};
			
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// Interface
			const auto & x() const								{return _x;}
			const auto & y() const								{return _y;}
			const auto & z() const								{return _z;}
			auto ex() const										{return _x / std::max(length(), 1e-50);}
			auto ey() const										{return _y / std::max(length(), 1e-50);}
			auto ez() const										{return _z / std::max(length(), 1e-50);}
			double length() const								{return std::sqrt(_x*_x + _y*_y + _z*_z);}
			
			void setCoord(const double & x, const double & y, const double & z);
			void setx(const double & x)							{_x = x;}
			void sety(const double & y)							{_y = y;}
			void setz(const double & z)							{_z = z;}
			
			Coordinate rotateX(double alpha) const;
			Coordinate rotateY(double alpha) const;
			Coordinate rotateZ(double alpha) const;
			
			
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// Operators and Calculation
			Coordinate & operator = (const Coordinate &a);
			Coordinate & operator = (const double a);
			
			double operator * (const Coordinate &b) const;
			Coordinate friend operator * (const double alpha, const Coordinate &a);
			Coordinate operator * (const double & alpha) const;
			Coordinate operator / (const double & alpha) const;
			
			Coordinate operator + (const Coordinate &b) const;
			Coordinate operator - (const Coordinate &b) const;
			Coordinate friend operator + (const Coordinate &a);
			Coordinate friend operator - (const Coordinate &a);
			Coordinate & operator += (const Coordinate& b);
			Coordinate & operator -= (const Coordinate& b);
			
			double friend dot(const double & d1, const double & d2, const double & d3, const Coordinate & c) {return d1 * c._x + d2 * c._y + d3 * c._z;}
			
			bool operator < (const Coordinate &b) const;
			bool operator > (const Coordinate &b) const;
			
			Coordinate friend pointwiseamulb(const Coordinate &a, const Coordinate &b);				// Pointwise c(i) = a(i) * b(i)
			Coordinate friend pointwiseadivb(const Coordinate &a, const Coordinate &b);	
			Coordinate friend acrossb(const Coordinate &a, const Coordinate&b);						// cross prodcut c = a X b
			
		
		private:

			double _x;
			double _y;
			double _z;
	};

}

#include "Coordinate.hpp"

#endif // ALGEBRA_COORDINATE_H
