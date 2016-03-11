#include <ctime>
#include <stdlib.h>
#include <cstdio>
#include <unistd.h>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Neural_Network.h"
#include "ColorDiff.h"
#include "NN_Color.hpp"
#include "Population.hpp"

std::vector<sf::CircleShape>	CreateLayers()
{
  std::vector<sf::CircleShape>	Layers;

  for (int i = 0; i < 9; i++)
    {
      sf::CircleShape	tmp(40);
      Layers.push_back(tmp);
    }
  Layers[0].setFillColor(sf::Color::Red);
  Layers[2].setFillColor(sf::Color::Blue);
  Layers[1].setFillColor(sf::Color::Green);
  Layers[0].setPosition(sf::Vector2f(20, 600/4 - 20));
  Layers[1].setPosition(sf::Vector2f(20, 600/4 * 2 - 20));
  Layers[3].setPosition(sf::Vector2f(800/2, 600/5 - 20));
  Layers[2].setPosition(sf::Vector2f(20, 600/4 * 3 - 20));
  Layers[4].setPosition(sf::Vector2f(800/2, 600/5 * 2 -20));
  Layers[5].setPosition(sf::Vector2f(800/2, 600/5 * 3 - 20));
  Layers[6].setPosition(sf::Vector2f(800/2, 600/5 * 4 - 20));
  Layers[7].setPosition(sf::Vector2f(800 - 100, 600 / 3 - 20));
  Layers[8].setPosition(sf::Vector2f(800 - 100, 600 / 3 * 2 - 20));
  return (Layers);
}

sf::Color	add_Tricolor(sf::Color a, sf::Color b, sf::Color c, sf::Color d, float aa, float ab, float ac, float ad)
{
  sf::Color	ret;

  ret.r = a.r*aa + b.r*ab + c.r*ac + d.r*ad;
  ret.g = a.g*aa + b.g*ab + c.g*ac + d.g*ac;
  ret.b = a.b*aa + b.b*ab + c.b*ac + d.b*ac;
  return ret;
}

int main(int ac, char **av)
{
  sf::RenderWindow	window(sf::VideoMode(800, 600), "Neuronal Network !");
  int	tab2[20] =
{3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6, 7, 7, 7, 7, 8, 8, 8, 8};
  int	tab1[20] =
{0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5, 6, 3, 4, 5, 6};
  std::vector<sf::CircleShape>	Layers;
  std::vector<sf::CircleShape>	goals;
  goals.push_back(sf::CircleShape(60));
  goals.push_back(sf::CircleShape(60));
  goals[0].setPosition(800-120, 600 /3 - 40);
  goals[1].setPosition(800-120, 600 /3 * 2 - 40);
  goals[0].setFillColor(sf::Color(200, 67, 123));
  goals[1].setFillColor(sf::Color(123, 200, 94));

  sf::Font	font;
  sf::Text	text;
  char		buff[296];

  font.loadFromFile("arial.ttf");

  text.setFont(font);
  text.setCharacterSize(20);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::White);


  srand(time(NULL));
  Population	pop(atoi(av[1]), 0.05);

  Layers = CreateLayers();
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
	    window.close();
	}

      window.clear(sf::Color::Black);
      NeuralNetwork	node(pop.FindNewChild());
      for (int i  = 0; i < 20; i++)
        {
          sf::RectangleShape	tmp = draw_line(Layers[tab1[i]].getPosition(), Layers[tab2[i]].getPosition(), node.weights[i]*10 + 1);
	  window.draw(tmp);
        }
      window.draw(goals[0]);
      window.draw(goals[1]);
      for (int i = 0; i < 4; i++)
	Layers[i+3].setFillColor(sf::Color(255*node.weights[i], 255*node.weights[i+2], 255*node.weights[i+3]));
      for (int i = 0; i < 2; i++)
	Layers[i+7].setFillColor(add_Tricolor(Layers[3].getFillColor(), Layers[4].getFillColor(), Layers[5].getFillColor(), Layers[6].getFillColor(), node.weights[i+12], node.weights[i+14], node.weights[i+16], node.weights[i+18]));
      for (std::vector<sf::CircleShape>::iterator it = Layers.begin(); it != Layers.end(); it++)
	window.draw(*it);
      sprintf(buff, "Generation : %d Average fitness : %0.f", pop.current_gen, pop.average_fit);
      text.setString(buff);
      window.draw(text);
      window.display();
    }
  return (0);
}
