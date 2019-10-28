#include <stdio.h>

#include "cmaes.h"
#include "mycmaes.h"
#include "boundary_transformation.h"

double fitfun(double const *x, unsigned long N) { /* function "cigtab" */
  unsigned i;
  double sum = 1e4*x[0]*x[0] + 1e-4*x[1]*x[1];
  for(i = 2; i < N; ++i)  
    sum += x[i]*x[i]; 
  return sum;
}

int main()
{
	double lb[] = {1};
	double rb[] = {3};
	mycmaes mc;
	mc.my_fitfun = &fitfun;
	call_cmaes(&mc, lb, rb);
	return 0;
}
