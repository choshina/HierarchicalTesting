# HierarchicalTesting

## A quick start
1. go to src/

2. compile the program by "make"

3. run "./exe"

## Code structure
1. CMAES library
	* cmaes_interface.h
	* cmaes.h
	* cmaes.c
	* boundary_transformation.h
	* boundary_transformation.c
	* my_cmaes.h
	* my_cmaes.c
2. Optimizer
	* Range.h
		- ContinuousRange.h
		- DiscreteRange.h
	* InputVariable.h
	* SearchSpace.h
	* SearchSpace.cpp
	* Node.h
	* Node.cpp
	* MCTS.h
	* MCTS.cpp
3. Others
	* Parser.h
	* Parser.cpp
	* main.cpp

