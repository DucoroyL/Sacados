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

void RechercheAleatoire::ecrireFichier(const char *name) {
    std::ofstream ecrire_fichier(name, std::ios::app);
    if(ecrire_fichier){
        ecrire_fichier << nbEval << solution.getFitness();
    }else{
        std::cerr <<"Impossible d'ouvrir le fichier ! "<<std::endl;
    }
    ecrire_fichier.close();
}
