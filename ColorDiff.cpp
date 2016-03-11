#include <iostream>
#include "ColorDiff.h"

double		Distance(double a, double b)
{
  return ((a - b) * (a - b));
}

double		colorDiff(t_color c_1, t_color c_2) {
  double		Diff;

  Diff = Distance(c_1.red, c_2.red) + Distance(c_1.green, c_2.green) + Distance(c_1.blue, c_2.blue);
//  std::cout << "R" << sqrt(Distance(c_1.red, c_2.red)) << "  G" <<  sqrt(Distance(c_1.green, c_2.green)) << "  B" << sqrt(Distance(c_1.blue, c_2.blue)) << std::endl;
  return sqrt(Diff);
}
