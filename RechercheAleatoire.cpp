#include "RechercheAleatoire.hpp"

void RechercheAleatoire::run(){
	for (int iEval = 0; iEval < nbEval; iEval++){
		for (int index = 0, index < solutionX.size(); index++){
			int aleaIndex = rand() % 2;
			solutionX[i] = aleaIndex;
		}
		
		double solutionEval = fonctionEval(sac);
		
		if (solutionEval > solution.fitness)
			solution.fitness = solutionEval;
	}
}
//~ double Sacados::aleatoireSolution(int nbEval){
	 //~ double meilleureSolution =0;
	  //~ std::vector<bool> x(n);
	  //~ for(int iEval = 0; iEval< nbEval; iEval++){
		  //~ for(int i=0; i<n; i++){
			 //~ int aleaIndex = rand() % 2;
			//~ x[i]=aleaIndex;
		  //~ }
		 //~ double solutionEval = fonctionEval(x);
		 //~ if ( solutionEval > meilleureSolution)
			//~ meilleureSolution = solutionEval;
	  //~ }
	  //~ return meilleureSolution;
//~ }
