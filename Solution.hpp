#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector> 
#include <string>
#include "Sacados.hpp"


class Solution{	
	public : 
		std::vector<bool> solutionX;
		double fitness;
		
		Solution() {
			solutionX.resize(0);
			fitness=0;
		}
		
		Solution(unsigned _n) {
			solutionX.resize(_n);
			fitness=0;
		}
		
		void reset() {
			for (auto element : solutionX)
				element = 0;
		}
		
		void print() {
			for (auto element : solutionX)
				std::cout<<element;
		}
};


#endif
