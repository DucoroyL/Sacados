#ifndef SACADOS_HILLFIRST_HPP
#define SACADOS_HILLFIRST_HPP

#include "RechercheLocale.hpp"

class HillFirst : public RechercheLocale{
    public:
        HillFirst(Sacados & _sc, Solution & _solution, int _nbEval) : RechercheLocale(_sc, _solution, _nbEval) {};
        virtual void run();
};
#endif
