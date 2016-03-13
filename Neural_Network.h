#ifndef NEURAL_NETWORK_H_
# define NEURAL_NETWORK_H_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "ColorDiff.h"

class	NeuralNetwork{
public:
  double		InputLayer;
  double		OutputLayer;
  double		HiddenLayer;
  double		nb_synaps;
  int			generation;
  double		fitness;
  std::vector<float>	weights;
  t_color		o1, o2; //Need to move this out of the classe

  NeuralNetwork(double, double, double, int, std::vector<float> = std::vector<float>());
  NeuralNetwork(const NeuralNetwork&);
  void	FindFitness(t_color, t_color); //Need to move this out of the classe
};

sf::Color	add_Tricolor(sf::Color a, sf::Color b, sf::Color c, sf::Color d, float aa, float ab, float ac, float ad);

#endif /* !NEURAL_NETWORK_H_ */
