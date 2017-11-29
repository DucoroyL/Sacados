#ifndef SACADOS_HILLFIRST_HPP
#define SACADOS_HILLFIRST_HPP

#include "RechercheLocale.hpp"

class HillFirst : public RechercheLocale{
	private :
		std::vector<int> tirageSansRemise;
		int rangBestSolution;
    public:
        HillFirst(Sacados & _sc, Solution & _solution, int _nbEval) : RechercheLocale(_sc, _solution, _nbEval), tirageSansRemise(solution.getSizeSolution()), rangBestSolution(0) {};
        virtual void run();
        virtual void ecrireFichier(const char* name);
};
#endif
