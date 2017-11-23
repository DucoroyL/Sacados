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
	    int nbEval;
	    
		RechercheLocale(Sacados & _sc) : sac(_sc), nbEval(_nbEval) { } ;
		virtual void run(Solution &) = 0;
};


#endif
