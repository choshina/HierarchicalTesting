#ifndef MYCMAES_H
#define MYCMAES_H

typedef struct{
		

		double (*my_fitfun) (const double *, const double* m);
} mycmaes;

int is_feasible(double const*, unsigned long);
double call_cmaes(mycmaes* mc, double* lbounds, double* ubounds, double* consts, int budget);
#endif
