#ifndef RECHERCHELOCALE_HPP
#define RECHERCHELOCALE_HPP

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector> 
#include <string>
#include "Sacados.hpp"
#include "Solution.hpp"


class RechercheLocale {
	public : 
	    Sacados & sac;
	    Solution & solution;
	    int nbEval;
	    int nbEvalCourante;
	    
		RechercheLocale(Sacados & _sc, Solution & _solution, int _nbEval) : sac(_sc), solution(_solution), nbEval(_nbEval), nbEvalCourante(0) { } ;
		virtual void run() = 0;
		virtual void ecrireFichier(const char* name) = 0;
};


#endif
