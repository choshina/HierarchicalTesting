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
4. Configurations
	* cmaes_initials.par
	* cmaes_signals.par
	* input.config

## Usage:
1. Set the dimension of variables by modifying 13th line of cmaes_initials.par
2. Specify the details of variables in input.config.
3. Specify the objective function in main.cpp "fitfun"
	- 1st argument is a list of continuous variables
	- 2nd argument is a list of discrete variables
4. Specify parameters for the optimizer in main.cpp line 24
	- 1st argument (0.2): a scalar for balancing exploration and exploitation
	- 2nd argument (100): a global budget, how many times to visit the tree
	- 3nd argument (30): a local budget, how many simulations for a local search
	- 4th argument (ss): no need to touch
	- 5th argument (&fitfun): no need to touch

## Misc:
