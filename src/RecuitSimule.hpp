#ifndef SACADOS_RECUITSIMULE_HPP
#define SACADOS_RECUITSIMULE_HPP

#include "RechercheLocale.hpp"
#include <cmath>

class RecuitSimule : public RechercheLocale{
	private:
		double tempInit;
		double alpha;
		int palier;
    public:
        RecuitSimule(Sacados & _sc, Solution & _solution, int _nbEval) : RechercheLocale(_sc, _solution, _nbEval), tempInit(10), alpha(0.95), palier(1) {};
        virtual void run();
        virtual void ecrireFichier(const char* name);
};
#endif
