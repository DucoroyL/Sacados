#include "HillBest.hpp"

void HillBest::run() {
    double evaluationCourante = sac.fonctionEval(solution);
    int iBest = 0;

    for (int index = 0; index < nbEval; index++) {
        double evaluationMax = 0;
        double evaluationVoisins = 0;

        for (int indexSolution = 0; indexSolution < solution.getSizeSolution(); indexSolution++) {
            solution.setSolution(indexSolution, !solution.getValSolution(indexSolution));
            evaluationVoisins = sac.fonctionEval(solution);
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
            rangBestSolution = index;
            break;
        }
    }
    solution.setFitness(evaluationCourante);
}