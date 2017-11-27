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

void MarcheAleatoire::ecrireFichier(const char *name) {
    std::ofstream ecrire_fichier(name);
    if(ecrire_fichier){
        for ( auto elem : solution.getSolution() ) {
            ecrire_fichier << elem;
        }
        ecrire_fichier << std::endl;
    }else{
        std::cerr <<"Impossible d'ouvrir le fichier ! "<<std::endl;
    }
    ecrire_fichier.close();
}

void MarcheAleatoire::enteteFichier() {

}