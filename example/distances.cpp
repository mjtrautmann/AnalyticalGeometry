//	
//	author: 		Marcus Trautmann
//	date:			16.11.2018
//	description: 	Simple examples for the analytical geometry library
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
//


#include "..\src\AnalyticalGeometry.h"
#include <iostream>
#include <cstdlib>



int main()
{
	std::cout << "Exmples for Analytical Geometry Library" << std::endl;



	analyticalgeom::Coordinate p0(0, 1, 0);
	analyticalgeom::Coordinate p1(2, 1, 0);
	analyticalgeom::Coordinate p2(1, 2, 1);
	analyticalgeom::Coordinate p3(1, 2, 1.0000001);


	std::cout << "The distance between " << p0 << " and " << p1 << " is " << (p1 - p0).length() << std::endl;
	std::cout << "The distance between " << p0 << " and " << p2 << " is " << (p2-p0).length() << std::endl << std::endl;

	analyticalgeom::Line line(p0, p1);
	std::cout << "The line through point " << p0 << " and " << p1 << " is " << line << std::endl;
	std::cout << "The projection of point " << p2 << " on line " << line << " is point " << analyticalgeom::AnalyticalGeometry::projection(line, p2) << std::endl;
	std::cout << "The shortest distance between line " << line << " and point " << p2 << " is " << analyticalgeom::AnalyticalGeometry::distance(line, p2) << std::endl << std::endl;

	analyticalgeom::Plane plane(p0, p1, p2);
	std::cout << "The points " << p0 << ", " << p1 << " and " << p2 << " form the plane " << plane << std::endl;
	std::cout << "The projection of " << p3 << " on the plane " << plane << " is " << analyticalgeom::AnalyticalGeometry::projection(plane, p3) << std::endl;
	std::cout << "The distance between point " << p3 << " and plane " << plane << " is " << analyticalgeom::AnalyticalGeometry::distance(plane, p3) << std::endl << std::endl;

	analyticalgeom::Plane plane2(p0 + plane.n(), plane.n());
	std::cout << "The plane " << plane << " shifted in normal direction by 1 unit produces the plane " << plane2 << std::endl;
	std::cout << "The planes are " << (analyticalgeom::AnalyticalGeometry::isParallel(plane, plane2) ? std::string("parallel") : std::string("not parallel")) << std::endl;

	analyticalgeom::Plane plane3(p0, p1, p3);
	std::cout << plane.n() * plane3.n() << std::endl;
	std::cout << "The planes " << plane << " and " << plane3 << " are " << (analyticalgeom::AnalyticalGeometry::isParallel(plane, plane3) ? std::string("parallel") : std::string("not parallel")) << std::endl;

	return 0;
}