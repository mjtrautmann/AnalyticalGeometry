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

#pragma once

#include "analyticalGeometry.h"

namespace analyticalgeom
{
		
	class Plane
	{
		public:
		
			constexpr Plane();
			constexpr explicit Plane(const Coordinate& a, const Coordinate& b, const Coordinate& c);
			constexpr explicit Plane(const Coordinate& x, const Coordinate& n);

			std::string print() const;
		
			constexpr const auto& n() const		{return _n;}
			constexpr const auto& d() const		{return _d;}
		
		
		
		protected:
		
			Coordinate _n;
			floattype _d {0};
	};


	inline std::ostream& operator<< (std::ostream& stream, const analyticalgeom::Plane& p)
	{
		stream << p.print();
		return stream;
	}
}



#include "Plane.hpp"



