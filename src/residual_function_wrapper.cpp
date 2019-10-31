#include<iostream>
#include<iomanip>
#include<cstring>
#include "mango.hpp"

void mango::problem::residual_function_wrapper(const double* x, double* f, bool* failed) {
  function_evaluations++;
  int failed_int;
  residual_function(&N_parameters, x, &N_terms, f, &failed_int, this);
  *failed = (failed_int != 0);

  std::cout << "Hello from residual_function_wrapper. Here comes x:\n";
  int j;
  for (j=0; j < N_parameters; j++) {
    std::cout << std::setw(24) << std::setprecision(15) << x[j];
  }
  std::cout << "\n";

  /*
  std::cout << "residual:";
  for (j=0; j < N_terms; j++) {
    std::cout << std::setw(24) << std::setprecision(15) << f[j];
  }
  std::cout << "\n" << std::flush;
  */

  double objective_value = write_least_squares_file_line(x, f);

  if (! *failed && (!at_least_one_success || objective_value < best_objective_function)) {
    at_least_one_success = true;
    best_objective_function = objective_value;
    best_function_evaluation = function_evaluations;
    memcpy(best_state_vector, x, N_parameters * sizeof(double));
    memcpy(best_residual_function, f, N_terms * sizeof(double)); 
  }

}



double mango::problem::write_least_squares_file_line(const double* x, double* residuals) {
  double total_objective_function, temp;
  int j;

  /* Combine the residuals into the total objective function. */
  total_objective_function = 0;
  for (j=0; j<N_terms; j++) {
    temp = (residuals[j] - targets[j]) / sigmas[j];
    total_objective_function += temp*temp;
  }

  /* Now actually write the line of the output file. */
  output_file << std::setw(6) << std::right << function_evaluations;
  for (j=0; j<N_parameters; j++) {
    output_file << "," << std::setw(26) << std::setprecision(16) << std::scientific << x[j];
  }
  output_file << "," << std::setw(26) << total_objective_function;
  for (j=0; j<N_terms; j++) {
    output_file << "," << std::setw(26) << std::setprecision(16) << std::scientific << residuals[j];
  }
  output_file << "\n" << std::flush;

  return(total_objective_function);
}