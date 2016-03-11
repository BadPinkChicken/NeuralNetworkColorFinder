#include "Neural_Network.h"

NeuralNetwork::NeuralNetwork(double in, double out, double hid, int generation, std::vector<float> wei)
{
  this->InputLayer = in;
  this->OutputLayer = out;
  this->HiddenLayer = hid;
  this->nb_synaps = (in + out) * hid;
  this->generation = generation;
  if (wei.size() < 1)
    {
	for (int i = 0; i < this->nb_synaps; i++)
	this->weights.push_back((float)(rand() % 101) / 100);// For this case tuning is from 0 to 1 with 0.01 steps
    }
  else
    this->weights = wei;


  std::vector<sf::Color> v;
  for (int i = 0; i < 4; i++)
    v.push_back(sf::Color(255*this->weights[i], 255*this->weights[i+2], 255*this->weights[i+3]));

  sf::Color tmp = add_Tricolor(v[0], v[1], v[2], v[3], this->weights[12], this->weights[14], this->weights[16], this->weights[18]);

t_color c1 = {tmp.r, tmp.g, tmp.b};
  tmp = add_Tricolor(v[0], v[1], v[2], v[3], this->weights[13], this->weights[15], this->weights[17], this->weights[19]);

t_color c2 = {tmp.r, tmp.g, tmp.b};
  this->o1 = c1;
  this->o2 = c2;

t_color	goal1 = {200, 67, 123};
t_color	goal2 = {123, 200, 94};
  this->FindFitness(goal1, goal2);
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork & old)
{
  this->InputLayer = old.InputLayer;
  this->OutputLayer = old.OutputLayer;
  this->HiddenLayer = old.HiddenLayer;
  this->nb_synaps = old.nb_synaps;
  this->fitness = old.fitness;
  this->weights = old.weights;
  this->generation = old.generation;
}

void	NeuralNetwork::FindFitness(t_color a, t_color b)
{
  int	a1 = colorDiff(this->o1, a);
  int	a2 = colorDiff(this->o2, b);
  this->fitness = (a1 + a2) / 2;
}
