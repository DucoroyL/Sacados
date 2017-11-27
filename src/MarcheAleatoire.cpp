#include "MarcheAleatoire.hpp"

void MarcheAleatoire::run() {
	ecrireFichier("stat_marche_Aleatoire.csv");
    for (int index = 0; index < nbEval ; index++) {
        int aleaIndex = rand() % solution.getSizeSolution();
        solution.setSolution(aleaIndex, !solution.getValSolution(aleaIndex));
        ecrireFichier("stat_marche_Aleatoire.csv");
    }
     std::ofstream ecrire_fichier("stat_marche_Aleatoire.csv", std::ios::app);
     if(ecrire_fichier){
        ecrire_fichier << "Nouvelle exécution : " << std::endl;
     }else{
        std::cerr <<"Impossible d'ouvrir le fichier ! "<<std::endl;
     }
     ecrire_fichier.close();
}

void MarcheAleatoire::ecrireFichier(const char *name) {
    std::ofstream ecrire_fichier(name, std::ios::app);
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
