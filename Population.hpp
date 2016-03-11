#ifndef POPULATION_H_
# define POPULATION_H_

#include "Neural_Network.h"

class	Population{
  protected:

  int				pop_size;
  int				mut_prob;

  public:
  double		average_fit;
  int				current_gen;
  std::vector<NeuralNetwork>	pop;
  Population(int, double);

  NeuralNetwork		FindNewChild();
  NeuralNetwork		Mutate(NeuralNetwork &, NeuralNetwork &);
};

#endif
