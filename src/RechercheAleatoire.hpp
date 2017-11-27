#ifndef RECHERCHEALEATOIRE_HPP
#define RECHERCHEALEATOIRE_HPP

#include "RechercheLocale.hpp"
class RechercheAleatoire :  public RechercheLocale {
	public :
		RechercheAleatoire(Sacados & _sc, Solution & _solution, int _nbEval) : RechercheLocale(_sc, _solution, _nbEval) {};
		virtual void run();
};


#endif
