#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include "mycmaes.h"
#include "cmaes.h"
#include "boundary_transformation.h"
#include "cmaes_interface.h"

int is_feasible(double const *x, unsigned long N)
{
	N = (long) x[0];
	return 1;
}

void call_cmaes(mycmaes* mc, double* lbounds, double* ubounds, double* consts)
{
	cmaes_t evo; /* an CMA-ES type struct or "object" */
  cmaes_boundary_transformation_t boundaries;
  double *arFunvals, *x_in_bounds, *const*pop;
  //double lowerBounds[] = {1.0, DBL_MAX / -1e2}; /* last number is recycled for all remaining coordinates */
  //double upperBounds[] = {3, 2e22};

  double* lowerBounds = lbounds;
  double* upperBounds = ubounds;

  int nb_bounds = 1; /* numbers used from lower and upperBounds */
  unsigned long dimension;
  int i; 

  /* initialize boundaries, be sure that initialSigma is smaller than upper minus lower bound */
  cmaes_boundary_transformation_init(&boundaries, lowerBounds, upperBounds, nb_bounds);
  /* Initialize everything into the struct evo, 0 means default */
  arFunvals = cmaes_init(&evo, 0, NULL, NULL, 0, 0, "cmaes_initials.par");
  dimension = (unsigned long)cmaes_Get(&evo, "dimension");

  printf("%s\n", cmaes_SayHello(&evo));

  x_in_bounds = cmaes_NewDouble(dimension); /* calloc another vector */
  cmaes_ReadSignals(&evo, "cmaes_signals.par");  /* write header and initial values */
	
	int counteval = 0;
  /* Iterate until stop criterion holds */
  while(!cmaes_TestForTermination(&evo))
    { 
	
	  
      /* generate lambda new search points, sample population */
      pop = cmaes_SamplePopulation(&evo); /* do not change content of pop */

      /* transform into bounds and evaluate the new search points */
      for (i = 0; i < cmaes_Get(&evo, "lambda"); ++i) {
        cmaes_boundary_transformation(&boundaries, pop[i], x_in_bounds, dimension);
        /* this loop can be omitted if is_feasible is invariably true */
        while(!is_feasible(x_in_bounds, dimension)) { /* is_feasible needs to be user-defined, in case, and can change/repair x */
            cmaes_ReSampleSingle(&evo, i); 
            cmaes_boundary_transformation(&boundaries, pop[i], x_in_bounds, dimension);
        }
        arFunvals[i] = mc->my_fitfun(x_in_bounds, consts); /* evaluate */
		counteval ++;
      }

      /* update the search distribution used for cmaes_SampleDistribution() */
      cmaes_UpdateDistribution(&evo, arFunvals);  /* assumes that pop[i] has not been modified */

      /* read instructions for printing output or changing termination conditions */ 
      cmaes_ReadSignals(&evo, "cmaes_signals.par");
      fflush(stdout); /* useful in MinGW */
    }
  printf("Stop:\n%s\n",  cmaes_TestForTermination(&evo)); /* print termination reason */
  cmaes_WriteToFile(&evo, "all", "allcmaes.dat");         /* write final results */

  /* get best estimator for the optimum, xmean */
  cmaes_boundary_transformation(&boundaries,
		  (double const *) cmaes_GetPtr(&evo, "xmean"), /* "xbestever" might be used as well */
		  x_in_bounds, dimension);

  /* do something with final solution x_in_bounds */

  /* ... */

  /* and finally release memory */
  cmaes_exit(&evo); /* release memory */
  cmaes_boundary_transformation_exit(&boundaries); /* release memory */
  free(x_in_bounds);


}

