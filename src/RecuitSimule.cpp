#include "RecuitSimule.hpp"

void RecuitSimule::run(){
		double fit;
		double delta;

	do{
		int aleaIndex = rand() % solution.getSizeSolution();
		fit = sac.fonctionEval(solution);
		nbEvalCourante++;
	
		solution.setSolution(aleaIndex, !solution.getValSolution(aleaIndex));
		delta = sac.fonctionEval(solution) - fit;
		nbEvalCourante++;
		if ( delta <= 0 ){
			solution.setSolution(aleaIndex, !solution.getValSolution(aleaIndex));
			double u = ((double)rand () / RAND_MAX);

			if ( u < exp (delta/tempInit) ) {
				solution.setSolution(aleaIndex, !solution.getValSolution(aleaIndex));
			}
		}
		if ( nbEvalCourante%palier == 0 ){
			tempInit*= alpha;
		}
	} while (nbEvalCourante < nbEval);
	solution.setFitness(sac.fonctionEval(solution));
}

void RecuitSimule::ecrireFichier(const char* name){
	std::ofstream ecrire_fichier(name,std::ios::app);
    if(ecrire_fichier){
        ecrire_fichier << nbEval << " " << solution.getFitness() << std::endl;
    }else{
        std::cerr <<"Impossible d'ouvrir le fichier ! "<<std::endl;
    }
    ecrire_fichier.close();
}
