#ifndef MYCMAES_H
#define MYCMAES_H

typedef struct{
		

		double (*my_fitfun) (const double *,  double* m);
} mycmaes;

int is_feasible(double const*, unsigned long);
void call_cmaes(mycmaes* mc, double* lbounds, double* ubounds, double* consts);

#endif
