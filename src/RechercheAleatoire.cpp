#include "RechercheAleatoire.hpp"

void RechercheAleatoire::run(){
    double meilleureSolution = 0;

	for (int iEval = 0; iEval < nbEval; iEval++){
		for (unsigned index = 0; index < solution.getSolution().size(); index++){
			int aleaIndex = rand() % 2;
			solution.setSolution(index, aleaIndex);
		}
		solution.setFitness(sac.fonctionEval(solution));
		if ( solution.getFitness() > meilleureSolution)
			meilleureSolution = solution.getFitness();
	}
    solution.setFitness(meilleureSolution);
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
