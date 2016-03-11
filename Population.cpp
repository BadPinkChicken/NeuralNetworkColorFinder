#include "Population.hpp"


Population::Population(int size, double mut_prob)
{
  this->mut_prob = mut_prob;

  for (int i = 0; i < size; i++)
    {
      NeuralNetwork	newOne(3, 2, 4, 0);
      this->pop.push_back(newOne);
    }
  this->current_gen = 0;
}

NeuralNetwork	Population::Mutate(NeuralNetwork & p1, NeuralNetwork & p2)
{
  std::vector<float>	newWeights;
    for (int i = 0; i < 20; i++) {
      float	tmp;
      tmp = (rand()%2) == 1 ? p1.weights[i] : p2.weights[i]; // 50/50 genes heritage
      if (rand()%1000 == 5)  //0,05 % chance of mutation of EACH gene
	    tmp = ((float)(rand()%11) /10);
            newWeights.push_back(tmp);
    }
  return NeuralNetwork(3, 2, 4, this->current_gen + 1, newWeights);
}

NeuralNetwork Population::FindNewChild()
{
  int	a1 = 0;
  int	a2 = 0;
  int	a3 = 0;
  int	a = 0;

  while (a1 == a2 || a1 == a3 || a2 == a3)
    {
      a1 = rand()% this->pop.size();
      a2 = rand()% this->pop.size();
      a3 = rand()% this->pop.size();
    }
  NeuralNetwork child(this->Mutate(pop[a2], pop[a3]));
    if (pop[a1].fitness > pop[a2].fitness && pop[a2].fitness > pop[a3].fitness) {
      NeuralNetwork child(this->Mutate(pop[a2], pop[a3]));
      pop[a1] = child;
    }
    else if (pop[a2].fitness > pop[a1].fitness && pop[a2].fitness > pop[a3].fitness)  {
      NeuralNetwork child(this->Mutate(pop[a1], pop[a3]));
      pop[a2] = child;
    }
    else   {
      NeuralNetwork child(this->Mutate(pop[a1], pop[a2]));
      pop[a3] = child;
    }
  for (std::vector<NeuralNetwork>::iterator it = this->pop.begin(); it != this->pop.end(); it++)
    a+= it->fitness;
  this->average_fit = a / this->pop.size();
  for (std::vector<NeuralNetwork>::iterator it = this->pop.begin(); it != this->pop.end(); it++)
    {
      if (this->current_gen == it->generation)
	return child;
    }
  this->current_gen++;
  return child;
}
