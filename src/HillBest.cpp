#include "HillBest.hpp"

void HillBest::run() {
    double evaluationCourante = sac.fonctionEval(solution);
    nbEvalCourante++;
    int iBest = 0;

    do {
        double evaluationMax = 0;
        double evaluationVoisins = 0;

			for (unsigned indexSolution = 0; indexSolution < solution.getSizeSolution(); indexSolution++) {
				solution.setSolution(indexSolution, !solution.getValSolution(indexSolution));
				evaluationVoisins = sac.fonctionEval(solution);
				nbEvalCourante++;
				
				if ( evaluationVoisins > evaluationMax){
					evaluationMax = evaluationVoisins;
					iBest = indexSolution;
				}
				solution.setSolution(indexSolution, !solution.getValSolution(indexSolution));
			}
			if ( evaluationCourante < evaluationMax){
				evaluationCourante = evaluationMax;
				solution.setSolution(iBest, !solution.getValSolution(iBest));
			} else {
				rangBestSolution = nbEvalCourante;
				break;
			}
	   }
	   while (nbEvalCourante < nbEval);
    solution.setFitness(evaluationCourante);
}

void HillBest::ecrireFichier(const char *name) {
    std::ofstream ecrire_fichier(name,std::ios::app);
    if(ecrire_fichier){
        ecrire_fichier << nbEval << " " << rangBestSolution << " " << solution.getFitness() << std::endl;
    }else{
        std::cerr <<"Impossible d'ouvrir le fichier ! "<<std::endl;
    }
    ecrire_fichier.close();
}
