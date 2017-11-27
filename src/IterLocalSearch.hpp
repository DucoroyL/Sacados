#ifndef SACADOS_ITERLOCALSEARCH_HPP
#define SACADOS_ITERLOCALSEARCH_HPP

#include "RechercheLocale.hpp"

class IterLocalSearch : public RechercheLocale{
	private:
    public:
        IterLocalSearch(Sacados & _sc, Solution & _solution, int _nbEval) : RechercheLocale(_sc, _solution, _nbEval), tempInit(10), alpha(0.95), palier(1) {};
        virtual void run();
        virtual void ecrireFichier(const char* name);
};
#endif
