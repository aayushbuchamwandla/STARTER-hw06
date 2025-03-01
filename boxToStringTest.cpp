#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"




int main() {

  struct Box b1,b2;

  initBox(&b1,3.0,4.0, 5.0, 6.0);  
  assertEquals("ul=(3,4),w=5,h=6", boxToString(b1, 0), "boxToString(b1,0)");
  assertEquals("ul=(3.00,4.00),w=5.00,h=6.00", boxToString(b1, 2), "boxToString(b1,2)");
  assertEquals("ul=(3.000,4.000),w=5.000,h=6.000", boxToString(b1, 3), "boxToString(b1,3)");
  
  initBox(&b2, 1.2345, -2.3456, 7.89, 12.345);
  assertEquals("ul=(1.23,-2.35),w=7.89,h=12.35", boxToString(b2, 2), "boxToString(b2,2)");
  assertEquals("ul=(1.2,-2.3),w=7.9,h=12.3", boxToString(b2, 1), "boxToString(b2,1)");
  assertEquals("ul=(1,-2),w=8,h=12", boxToString(b2, 0), "boxToString(b2,0)");
		   
  return 0;
}
