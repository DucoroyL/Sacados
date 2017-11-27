#ifndef SACADOS_MARCHEALEATOIRE_HPP
#define SACADOS_MARCHEALEATOIRE_HPP

#include "RechercheLocale.hpp"

class MarcheAleatoire : public RechercheLocale{
    public:
        MarcheAleatoire(Sacados & _sc, Solution & _solution, int _nbEval) : RechercheLocale(_sc, _solution, _nbEval) {};
        virtual void run();
        virtual void ecrireFichier(const char* name);
        virtual void enteteFichier();
};

#endif
