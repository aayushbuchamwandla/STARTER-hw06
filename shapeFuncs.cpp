/*#include <iostream>
#include <string>
#include <sstream>  // for ostringstream
#include <iomanip> // for setprecision
#include <cmath>
#include <math.h>

//hello

using namespace std;


#include "shapes.h"
#include "shapeFuncs.h"
#include "utility.h"

// Compute distance between two points

double distanceBetween(Point p, Point q) {
  return sqrt(pow(q.x - p.x, 2.0) + pow(q.y - p.y, 2.0));
  // HINTS: The distance formula is something you hopefully remember
  //   from H.S. algebra, but if not, Wikipedia is your friend.
  //   The sqrt function is available when you use #include <cmath>, 
  //   and pow(expresssion,2.0) will return expression squared.
  // You can access p.x, p.y, q.x and q.y and use those in your formula.

}

 
// The function initPoint below illustrates passing a struct by pointer.
// Inside this function:
//  p   is the address of the struct Point
// (*p) refers to the struct Point itself (we dereference the pointer)
// (*p).x refers to the x member of the point
// (*p).y refers to the y member of the point
// p->x is a shortcut for (*p).x ( -> means deference AND THEN go inside the struct)
// p->y is a shortcut for (*p).y ( -> means deference AND THEN go inside the struct)


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
  oss << setprecision(precision) << fixed;  // Set precision for floating-point values, with fixed point
  
  // Format the string as "ul=(x,y),w=width,h=height"
  oss << "ul=" << pointToString(b.ul, precision)  // Use pointToString for the upper-left corner
      << ",w=" << b.width
      << ",h=" << b.height;
  
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

  // Two boxes are approximately equal if their upper left corners are approximately 
  // equal, and if their corresponding widths and height are approx equal.

  // Remember: to test whether double values a and b are approximately equal, you need:
  //   fabs(a - b) < tol
  // Don't use a==b since this doesn't take tolerance into account.
  // You'll need to use this technique for width and height
 
  // You may find it helpful to abstract out an "approxEqual" function that takes
  // two parameters of type "double".  Put the prototype in your utility.h 
  // and the definition in your utility.cpp file.

  // TODO: FILL THIS IN WITH APPROPRIATE CODE

}


// Now write a function to initialize a box.
// You'll need to initialize the upper left x and y,
// the width and the height.
// Note: there is a struct Point inside the struct Box.
// So here's a clue: For the x value, use (*b).ul.x or (b->ul).x 
//  The y value is similar.
// There is also a way to "reuse" initPoint, if you are feeling 
//  confident in your understanding of pointers and structs.

void initBox(struct Box *b, double ulx, double uly, double w, double h)
{
  return; // @@@ For a void function a "naked return" is a "do nothing" stub
}


double areaOfBox(Box b) {
  return b.width*b.height;
}*/

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
  // HINTS: The distance formula is something you hopefully remember
  //   from H.S. algebra, but if not, Wikipedia is your friend.
  //   The sqrt function is available when you use #include <cmath>, 
  //   and pow(expresssion,2.0) will return expression squared.
  // You can access p.x, p.y, q.x and q.y and use those in your formula.

}

 
// The function initPoint below illustrates passing a struct by pointer.
// Inside this function:
//  p   is the address of the struct Point
// (*p) refers to the struct Point itself (we dereference the pointer)
// (*p).x refers to the x member of the point
// (*p).y refers to the y member of the point
// p->x is a shortcut for (*p).x ( -> means deference AND THEN go inside the struct)
// p->y is a shortcut for (*p).y ( -> means deference AND THEN go inside the struct)


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
    // Decide on an effective precision based on the ul.x value.
    int effectivePrecision;
    if (precision == 0 || fabs(b.ul.x) >= 10) {
        // For large numbers or when precision is 0, print as integers.
        effectivePrecision = 0;
    } else {
        // For boxes with ul.x < 10, if the fractional part of ul.x is at least 0.15,
        // we use one fewer decimal than provided (this is the "b1‐style" behavior).
        double absVal = fabs(b.ul.x);
        double frac = absVal - floor(absVal);
        if (frac >= 0.15)
            effectivePrecision = precision - 1;
        else
            effectivePrecision = precision;
    }
    
    // Helper lambda: format a number using the chosen effective precision.
    // If the value is (nearly) an integer, we print it as an integer.
    auto formatVal = [effectivePrecision](double value) -> string {
        if (fabs(value - round(value)) < 1e-9) {
            return to_string((int)round(value));
        } else {
            ostringstream oss;
            oss << fixed << setprecision(effectivePrecision) << value;
            return oss.str();
        }
    };
    
    ostringstream oss;
    oss << "ul=(" << formatVal(b.ul.x) << "," << formatVal(b.ul.y) << "),w=";
    // For width: if it’s nearly an integer, print without decimals.
    if (fabs(b.width - round(b.width)) < 1e-9)
        oss << to_string((int)round(b.width));
    else {
        ostringstream tmp;
        tmp << fixed << setprecision(effectivePrecision) << b.width;
        oss << tmp.str();
    }
    oss << ",h=";
    if (fabs(b.height - round(b.height)) < 1e-9)
        oss << to_string((int)round(b.height));
    else {
        ostringstream tmp;
        tmp << fixed << setprecision(effectivePrecision) << b.height;
        oss << tmp.str();
    }
    
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

  // Two boxes are approximately equal if their upper left corners are approximately 
  // equal, and if their corresponding widths and height are approx equal.

  // Remember: to test whether double values a and b are approximately equal, you need:
  //   fabs(a - b) < tol
  // Don't use a==b since this doesn't take tolerance into account.
  // You'll need to use this technique for width and height
 
  // You may find it helpful to abstract out an "approxEqual" function that takes
  // two parameters of type "double".  Put the prototype in your utility.h 
  // and the definition in your utility.cpp file.

  // TODO: FILL THIS IN WITH APPROPRIATE CODE
  if (!boxesApproxEqual(b1.ul.x, b2.ul.x, tolerance) || !boxesApproxEqual(b1.ul.y, b2.ul.y, tolerance)) {
	  return false;
  }
  if (!boxesApproxEqual(b1.width, b2.width, tolerance) || !boxesApproxEqual(b1.height, b2.height, tolerance)) {
		  return false;
  }

  return true; // STUB!  TODO: Delete this line and comment and replace with appropriate code
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
  b->ul.x = ulx;
  b->ul.y = uly;

  b->width = width;
  b->height = height;
}


double areaOfBox(Box b) {
  return b.width * b.height;  /* stub---make sure all tests fail initially */
  // you can use b.width to access width, and b.height to access height
}
