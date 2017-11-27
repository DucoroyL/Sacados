#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector> 
#include <string>
#include "Sacados.hpp"


class Solution{
        private:
		    std::vector<bool> solutionX;
		    double fitness;

        public :
            Solution() {
                solutionX.resize(0);
                fitness=0;
            }

            Solution(unsigned _n) {
                solutionX.resize(_n);
                fitness=0;
                for (unsigned index = 0; index < _n; index++) {
                    int aleaValeur = rand() % 2;
                    solutionX[index] = aleaValeur;
                }
            }

            unsigned getSizeSolution(){
                return solutionX.size();
            }
            std::vector<bool> & getSolution() {
                return solutionX;
            }

            bool getValSolution(int index){
                return solutionX[index];
            }
            void setSolution(int _index, bool _valeurIndex){
                solutionX[_index] = _valeurIndex;
            }

            double getFitness() {
                return fitness;
            }

            void setFitness(double _fitness){
                fitness = _fitness;
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
