#include <iostream>
#include <string>
#include <sstream>  // for ostringstream
#include <iomanip> // for setprecision
#include <cmath>

using namespace std;


#include "shapes.h"
#include "shapeFuncs.h"
#include "utility.h"

// Compute distance between two points
double distanceBetween(Point p, Point q) {
  double dist = sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2));
  return dist;

}




void initPoint(struct Point *p, double xVal, double yVal) {
  p->x = xVal;
  p->y = yVal;
}


string pointToString(Point p, int precision) {
  ostringstream oss;
  oss << setprecision(precision); // set precision to 3 decimal places
  oss << "(" << p.x << "," << p.y << ")";
  return oss.str();
}
string boxToString(Box b, int precision) {
    ostringstream oss;
    oss << setprecision(precision) << defaultfloat;
    oss << "ul=(" << b.ul.x << "," << b.ul.y << ")," << "w=" << b.width << ",h=" << b.height;
    return oss.str();
}
bool pointsApproxEqual(Point p1, 
		       Point p2, 
		       double tolerance) {
  // Two points are approximately equal if the distance between them
  // is less than our tolerance.  (If we want to test for 
  // exact equality, we can pass in a value of zero.)

  return distanceBetween(p1,p2) < tolerance;

}

bool boxesApproxEqual(Box b1, Box b2, double tolerance) {


  // TODO: FILL THIS IN WITH APPROPRIATE CODE
  if (!approxEqual(b1.ul.x, b2.ul.x, tolerance) || !approxEqual(b1.ul.y, b2.ul.y, tolerance)) {
	  return false;
  }
  if (!approxEqual(b1.width, b2.width, tolerance) || !approxEqual(b1.height, b2.height, tolerance)) {
		  return false;
  }

  else{
	return true;
  }
}


// Now write a function to initialize a box.
// You'll need to initialize the upper left x and y,
// the width and the height.
// Note: there is a struct Point inside the struct Box.
// So here's a clue: For the x value, use (*b).ul.x or (b->ul).x 
//  The y value is similar.
// There is also a way to "reuse" initPoint, if you are feeling 
//  confident in your understanding of pointers and structs.

void initBox(struct Box *b, double ulx, double uly, double width, double height)
{
  b ->ul.x = ulx;
  b -> ul.y = uly;

  b->width = width;
  b->height = height;
}


double areaOfBox(Box b) {
  return b.width * b.height;  /* stub---make sure all tests fail initially */
  // you can use b.width to access width, and b.height to access height
}
