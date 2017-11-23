#ifndef SACADOS_HPP
#define SACADOS_HPP

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector> 
#include <string>
#include "Solution.hpp"


class Sacados{	
	private :
		int n;
		int coeff;
		std::vector<int> profits;
		std::vector<int> poids;
		double beta;
	
	public : 
		Sacados(const char* name);
		void calculBeta();
		int getN();
		double aleatoireSolution(int nbRepet);
		void fonctionEval(Solution & solutionAEvaluer);
		double marcheAleatoire(int nbEval);
		void solutionInitiale(std::vector<bool> & solutionIni);
		double evalSolutionInitiale(std::vector<bool> & solutionIni);
		double hillClimberBest(int nbEval);
};


#endif
