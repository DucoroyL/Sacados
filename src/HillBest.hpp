#ifndef SACADOS_HILLBEST_HPP
#define SACADOS_HILLBEST_HPP

#include "RechercheLocale.hpp"

class HillBest : public RechercheLocale{
    private:
        int rangBestSolution;
    public:
        HillBest(Sacados & _sc, Solution & _solution, int _nbEval) : RechercheLocale(_sc, _solution, _nbEval), rangBestSolution(0) {};
        virtual void run();
        virtual void ecrireFichier(const char* name);
};
#endif
