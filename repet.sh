#!/bin/bash

listEval="100 500 1000 1500 2000 10000"

> stats.csv
	for e in $listEval
	do
			./main ks_1000.dat ${e} 0 >> stats.csv
	done	
	echo
