#include "MarcheAleatoire.hpp"

void MarcheAleatoire::run() {
    std::cout<<" Solution initiale : ";
    solution.print();
    std::cout<<std::endl;
    for (int index = 0; index < nbEval ; index++) {
        int aleaIndex = rand() % solution.getSizeSolution();
        solution.setSolution(aleaIndex, !solution.getValSolution(aleaIndex));
        std::cout<<" Solution voisine : ";
        solution.print();
        std::cout<<std::endl;
    }
}

//~ std::vector<bool> substit(n);
//~ std::vector<bool> solutionInit(n);
//~ double evaluationVoisins=0;
//~ solutionInitiale(solutionInit);
//~
//~ substit=solutionInit;
//~
//~ for (int i=0; i<nbEval; i++){
//~ int aleaIndex = rand() % n;
//~ substit[aleaIndex]=!substit[aleaIndex];
//~ evaluationVoisins= fonctionEval(substit);
//~ }
//~ return evaluationVoisins;