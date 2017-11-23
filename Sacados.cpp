#include "Sacados.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <time.h> 

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

void Sacados::calculBeta(){
	for (int i = 0; i < n; i++)
	{
		if ( beta < ((float)profits[i]/poids[i]))
			beta = (float)profits[i]/poids[i];
	}
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

//~ void Sacados::solutionInitiale(std::vector<bool> & solutionInit){
	 //~ for(int i=0; i<n; i++){
	    //~ int aleaIndex = rand() % 2;
		//~ solutionInit[i]=aleaIndex;
	  //~ }
//~ }
//~ 
//~ double Sacados::evalSolutionInitiale(std::vector<bool> & solutionInit){
	//~ return fonctionEval(solutionInit);
//~ }
//~ double Sacados::marcheAleatoire(int nbEval){
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
//~ }
//~ 
//~ double Sacados::hillClimberBest(int nbEval){
	 //~ std::vector<bool> solutionInit(n);
	 //~ std::vector<bool> substit(n);
	 //~ int iBest=0;	
	 //~ double evaluationCourante = 0;
	 //~ 
	 //~ 
	 //~ solutionInitiale(solutionInit);
	 //~ evaluationCourante = evalSolutionInitiale(solutionInit);
	 //~ substit=solutionInit;
//~ 
		 //~ for (int i = 0; i  < nbEval; i++) {		  
			 //~ double evaluationMax = 0;
			 //~ double evaluationVoisins = 0;
			 //~ 
			 //~ for( int j = 0; j < n; j++) {
				  //~ substit[j] = !substit[j];
				  //~ evaluationVoisins = fonctionEval(substit);
				   //~ 
				  //~ if (evaluationVoisins > evaluationMax){
						//~ evaluationMax = evaluationVoisins;
						//~ iBest = j;
				  //~ } 
				   //~ substit[j] = !substit[j];
			 //~ }
			 //~ if (evaluationCourante < evaluationMax) {
				//~ evaluationCourante = evaluationMax;
				//~ substit[iBest] = !substit[iBest];
			 //~ } 	
			 //~ else{
				//~ break;
			 //~ }
		//~ }
//~ 
	 //~ return evaluationCourante;
//~ }

void Sacados::fonctionEval(Solution & solutionAEvaluer){
	int poids_sac      = 0;
	for (int i = 0; i < n; i++)
	{
		if (solutionAEvaluer.solutionX[i]) {
			poids_sac   += poids[i];
			solutionAEvaluer.fitness += profits[i];
		}
	}
	if (poids_sac > coeff)
		solutionAEvaluer.fitness = solutionAEvaluer.fitness - beta * (poids_sac-coeff);
}
//~ double Sacados::fonctionEval(std::vector<bool> &x){
	//~ int poids_sac      = 0;
	//~ double retour_Eval = 0.0;
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ if (x[i]) {
			//~ poids_sac   += poids[i];
			//~ retour_Eval += profits[i];
		//~ }
	//~ }
	//~ if (poids_sac <= coeff)
		//~ return retour_Eval;
	//~ else
		//~ return (retour_Eval - beta * (poids_sac-coeff));
//~ }
