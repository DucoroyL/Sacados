#ifndef SACADOS_HILLWORST_HPP
#define SACADOS_HILLWORST_HPP

#include "RechercheLocale.hpp"

class HillWorst : public RechercheLocale{
    public:
        HillWorst(Sacados & _sc, Solution & _solution, int _nbEval) : RechercheLocale(_sc, _solution, _nbEval) {};
        virtual void run();
};
#endif
