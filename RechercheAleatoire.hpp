#ifndef RECHERCHEALEATOIRE_HPP
#define RECHERCHEALEATOIRE_HPP

class RechercheAleatoire :  public RechercheLocale {	
	public :
		RechercheAleatoire(Sacados & _sc) : RechercheLocale(_sc) ;
		virtual void run(Solution &);
};


#endif
