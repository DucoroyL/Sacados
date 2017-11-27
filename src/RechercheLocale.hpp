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
	    
		RechercheLocale(Sacados & _sc, Solution & _solution, int _nbEval) : sac(_sc), solution(_solution), nbEval(_nbEval) { } ;
		virtual void run() = 0;
};


#endif
