#include "Sacados.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector> 
using namespace std;

int main(int argc, char ** argv){
	if (argc!=4)
	{
		cout<<" nom_prog <nom du fichier> <nbEvals> <graineAlea>"<<endl;
        return -1;
    }
    srand (atoi(argv[3]));
    //srand (time(NULL));

    Sacados sac(argv[1]);
    int nbEvals =atoi(argv[2]);
    //vector<bool> v={false,false,true,true,false};
    //sac.calculBeta();
	 //cout<<"Eval : "<<sac.fonctionEval(v)<<endl;
	// sac.creerFichierRechercheAlea();
	//for (int i=0; i<100; i++){
		//double bestEval=sac.aleatoireSolution(nbEvals);
	//	double bestEval=sac.hillClimberBest(nbEvals);
		//std::cout <<bestEval << std::endl;
		
    return 0;
}
