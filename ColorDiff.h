#ifndef COLORDIFF_H_
# define COLORDIFF_H_

#include <cmath>

typedef	struct	s_color{

  double	red;
  double	green;
  double	blue;
}		t_color;

double	colorDiff(t_color c_1, t_color c_2);
double	Distance(double a, double b);

#endif
