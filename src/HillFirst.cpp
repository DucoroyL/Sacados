#include "HillFirst.hpp"

void HillFirst::run() {
    double evaluationCourante = sac.fonctionEval(solution);
     std::cout << ": " << evaluationCourante << std::endl;
	 int iBest = 0;
	 
	do {
		double evaluationVoisins = 0;
		double evaluationMax = 0;
		
		for (unsigned indexSolution = 0; indexSolution < solution.getSizeSolution(); indexSolution++ ){
			int aleaIndex = rand() % solution.getSizeSolution();

			solution.setSolution(aleaIndex, !solution.getValSolution(aleaIndex));
			evaluationVoisins = sac.fonctionEval(solution);
			nbEvalCourante++;
			solution.setSolution(aleaIndex, !solution.getValSolution(aleaIndex));
			std::cout << "(" << aleaIndex << " " << evaluationVoisins << ") ";
			
			if ( evaluationVoisins > evaluationCourante){
				iBest = aleaIndex;
				evaluationMax = evaluationVoisins;
				break;
			}
		}
	     if ( evaluationCourante < evaluationMax){
            evaluationCourante = evaluationMax;
            solution.setSolution(iBest, !solution.getValSolution(iBest));
        } else {
            break;
        }
        std::cout << std::endl << iBest << ":" << evaluationCourante <<std::endl;
    } while (nbEvalCourante<nbEval);
    solution.setFitness(evaluationCourante);
}

void HillFirst::ecrireFichier(const char *name) {
    std::ofstream ecrire_fichier(name,std::ios::app);
    if(ecrire_fichier){
        ecrire_fichier << nbEval << " " << rangBestSolution << " " << solution.getFitness() << std::endl;
    }else{
        std::cerr <<"Impossible d'ouvrir le fichier ! "<<std::endl;
    }
    ecrire_fichier.close();
}

