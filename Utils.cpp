#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "ColorDiff.h"

sf::RectangleShape	draw_line(sf::Vector2f pos1, sf::Vector2f pos2, int t)
{
  sf::RectangleShape	tmp;
  int	v_deg = 180/M_PI;
  int pente = (atan((pos1.y-pos2.y)/(pos1.x-pos2.x))*v_deg*1000)/1000;
  int dist = sqrt(Distance(pos1.x, pos2.x) + Distance(pos2.y, pos2.y)) + abs(pente)*2.5;
  tmp.setSize(sf::Vector2f(dist, t));
  tmp.setPosition(sf::Vector2f(pos1.x+ 40, pos1.y + 40));
  tmp.rotate(pente);
  return (tmp);
}
