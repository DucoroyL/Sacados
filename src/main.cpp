#include "Sacados.hpp"
#include "RechercheLocale.hpp"
#include "RechercheAleatoire.hpp"
#include "MarcheAleatoire.hpp"
#include "HillBest.hpp"
#include "HillWorst.hpp"
#include "HillFirst.hpp"


using namespace std;

int main(int argc, char ** argv){
	if (argc!=4)
	{
		cout<<" nom_prog <nom du fichier> <nbEvals> <graineAlea>"<<endl;
        return -1;
    }

    int nbEvals =atoi(argv[2]);
    srand (atoi(argv[3]));
    Sacados sac(argv[1]);
    Solution solutionInit (sac.getN());

    RechercheLocale *r_Locale = new HillBest(sac, solutionInit, nbEvals);
    sac.calculBeta();
    r_Locale->run();
    cout<<endl<<"Eval : "<<sac.fonctionEval(solutionInit)<<endl;

    return 0;
}
