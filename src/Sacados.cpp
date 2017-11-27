#include "Sacados.hpp"

Sacados::Sacados(const char* argName){
	std::fstream lire_fichier(argName);	
	beta=0;
	 if(lire_fichier){
		 lire_fichier >> n;
		 
		 profits.resize(n);
	     poids.resize(n);
	     
	    for (int i = 0; i < n; i++)
		{
			lire_fichier >> profits[i];
		}
		for (int i = 0; i < n; i++)
		{
			lire_fichier >> poids[i];
		}
		
		lire_fichier >> coeff;
		 
	 }else{
		 std::cerr <<"Impossible d'ouvrir le fichier ! "<<std::endl;
     }
     lire_fichier.close();
}

int Sacados::getN(){
	return n;
}
void Sacados::calculBeta(){
	for (int i = 0; i < n; i++)
	{
		if ( beta < ((float)profits[i]/poids[i]))
			beta = (float)profits[i]/poids[i];
	}
}

double Sacados::fonctionEval(Solution & solutionAEvaluer){
	int poids_sac = 0;
    int somme_profits = 0;
    double retour_Eval = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (solutionAEvaluer.getSolution()[i]) {
			poids_sac   += poids[i];
            retour_Eval += profits[i];
		}
	}
	if (poids_sac <= coeff)
        return retour_Eval;
    else
		return (retour_Eval - beta * (poids_sac-coeff));
}