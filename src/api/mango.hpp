// Copyright 2019, University of Maryland and the MANGO development team.
//
// This file is part of MANGO.
//
// MANGO is free software: you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// MANGO is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with MANGO.  If not, see
// <https://www.gnu.org/licenses/>.


#ifndef MANGO_H
#define MANGO_H

#include <mpi.h>
#include <string>

namespace mango {

  typedef enum {
    // <packages>
    // This section was automatically generated by ./update_algorithms
    PACKAGE_HOPSPACK,
    PACKAGE_NLOPT,
    PACKAGE_GSL,
    PACKAGE_PETSC,
    // </packages>
    NUM_PACKAGES // Not an actual package, just counting.
  } package_type;

  const double NUMBER_FOR_FAILED = 1.0e+12;

  //////////////////////////////////////////////////////////////////////////////////////
  // Items related to algorithms:

  typedef struct {
    std::string name;
    package_type package;
    bool least_squares;
    bool uses_derivatives;
    bool parallel;
    bool allows_bound_constraints;
    bool requires_bound_constraints;
  } algorithm_properties;

  /** /brief A list of the algorithms mango can potentially use.
   * 
   * Each algorithm in this list is only available if MANGO is built with the corresponding package.
   */

  typedef enum {
    // <enum>
    // This section was automatically generated by ./update_algorithms
    PETSC_NM,
    PETSC_POUNDERS,
    PETSC_BRGN,
    NLOPT_GN_DIRECT,
    NLOPT_GN_DIRECT_L,
    NLOPT_GN_DIRECT_L_RAND,
    NLOPT_GN_DIRECT_NOSCAL,
    NLOPT_GN_DIRECT_L_NOSCAL,
    NLOPT_GN_DIRECT_L_RAND_NOSCAL,
    NLOPT_GN_ORIG_DIRECT,
    NLOPT_GN_ORIG_DIRECT_L,
    NLOPT_GN_CRS2_LM,
    NLOPT_LN_COBYLA,
    NLOPT_LN_BOBYQA,
    NLOPT_LN_PRAXIS,
    NLOPT_LN_NELDERMEAD,
    NLOPT_LN_SBPLX,
    NLOPT_LD_MMA,
    NLOPT_LD_CCSAQ,
    NLOPT_LD_SLSQP,
    NLOPT_LD_LBFGS,
    NLOPT_LD_TNEWTON_PRECOND_RESTART,
    NLOPT_LD_TNEWTON_PRECOND,
    NLOPT_LD_TNEWTON_RESTART,
    NLOPT_LD_TNEWTON,
    NLOPT_LD_VAR1,
    NLOPT_LD_VAR2,
    HOPSPACK,
    GSL_LM,
    GSL_DOGLEG,
    GSL_DDOGLEG,
    GSL_SUBSPACE2D,
    GSL_CONJUGATE_FR,
    GSL_CONJUGATE_PR,
    GSL_BFGS,
    GSL_NM,
    // </enum>
    NUM_ALGORITHMS  // Not an actual algorithm, just counting.
  } algorithm_type;
  
  const algorithm_properties algorithms[NUM_ALGORITHMS] = {
    // <database>
    // This section was automatically generated by ./update_algorithms
    // name,                            package,         least_squares, uses_derivatives, parallel, allows_bound_constraints, requires_bound_constraints
    {"petsc_nm",                        PACKAGE_PETSC,   false,         false,            false,    false,                    false},
    {"petsc_pounders",                  PACKAGE_PETSC,   true,          false,            false,    true,                     false},
    {"petsc_brgn",                      PACKAGE_PETSC,   true,          true,             true,     true,                     false},
    {"nlopt_gn_direct",                 PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_gn_direct_l",               PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_gn_direct_l_rand",          PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_gn_direct_noscal",          PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_gn_direct_l_noscal",        PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_gn_direct_l_rand_noscal",   PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_gn_orig_direct",            PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_gn_orig_direct_l",          PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_gn_crs2_lm",                PACKAGE_NLOPT,   false,         false,            false,    true,                     true },
    {"nlopt_ln_cobyla",                 PACKAGE_NLOPT,   false,         false,            false,    true,                     false},
    {"nlopt_ln_bobyqa",                 PACKAGE_NLOPT,   false,         false,            false,    true,                     false},
    {"nlopt_ln_praxis",                 PACKAGE_NLOPT,   false,         false,            false,    true,                     false},
    {"nlopt_ln_neldermead",             PACKAGE_NLOPT,   false,         false,            false,    true,                     false},
    {"nlopt_ln_sbplx",                  PACKAGE_NLOPT,   false,         false,            false,    true,                     false},
    {"nlopt_ld_mma",                    PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_ccsaq",                  PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_slsqp",                  PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_lbfgs",                  PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_tnewton_precond_restart",PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_tnewton_precond",        PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_tnewton_restart",        PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_tnewton",                PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_var1",                   PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"nlopt_ld_var2",                   PACKAGE_NLOPT,   false,         true,             true,     true,                     false},
    {"hopspack",                        PACKAGE_HOPSPACK,false,         false,            true,     true,                     false},
    {"gsl_lm",                          PACKAGE_GSL,     true,          true,             true,     false,                    false},
    {"gsl_dogleg",                      PACKAGE_GSL,     true,          true,             true,     false,                    false},
    {"gsl_ddogleg",                     PACKAGE_GSL,     true,          true,             true,     false,                    false},
    {"gsl_subspace2d",                  PACKAGE_GSL,     true,          true,             true,     false,                    false},
    {"gsl_conjugate_fr",                PACKAGE_GSL,     false,         true,             true,     false,                    false},
    {"gsl_conjugate_pr",                PACKAGE_GSL,     false,         true,             true,     false,                    false},
    {"gsl_bfgs",                        PACKAGE_GSL,     false,         true,             true,     false,                    false},
    {"gsl_nm",                          PACKAGE_GSL,     false,         false,            false,    false,                    false}
    // </database>
  };

  bool does_algorithm_exist(std::string);
  bool get_algorithm(std::string, algorithm_type*);

  //////////////////////////////////////////////////////////////////////////////////////
  // Items related to partitioning the processors into worker groups:

  /** \brief A class for dividing the set of MPI processes into worker groups.
   *
   * Each group works together on evaluations of the objective function.
   */

  class MPI_Partition {
  private:
    MPI_Comm comm_world;
    MPI_Comm comm_worker_groups;
    MPI_Comm comm_group_leaders;
    int N_procs_world;
    int rank_world;
    int N_procs_worker_groups;
    int rank_worker_groups;
    int N_procs_group_leaders;
    int rank_group_leaders;
    int worker_group;
    bool proc0_world;
    bool proc0_worker_groups;
    int N_worker_groups;
    bool initialized;

    void verify_initialized();
    void print();
    void write_line(std::ofstream&, int, std::string[], int[]);

  public:
    int verbose;

    MPI_Partition();
    ~MPI_Partition();

    void init(MPI_Comm);
    void set_custom(MPI_Comm, MPI_Comm, MPI_Comm);
    MPI_Comm get_comm_world();
    MPI_Comm get_comm_worker_groups();
    MPI_Comm get_comm_group_leaders();
    bool get_proc0_world();
    bool get_proc0_worker_groups();
    int get_rank_world();
    int get_rank_worker_groups();
    int get_rank_group_leaders();
    int get_N_procs_world();
    int get_N_procs_worker_groups();
    int get_N_procs_group_leaders();
    int get_worker_group();
    int get_N_worker_groups();
    void set_N_worker_groups(int);
    void write(std::string);

    void stop_workers();
    void mobilize_workers();
    bool continue_worker_loop();
  };

  //////////////////////////////////////////////////////////////////////////////////////
  // Items specific to an optimization problem

  class Problem;
  typedef void (*objective_function_type)(int*, const double*, double*, int*, mango::Problem*, void*);
  typedef void (*residual_function_type)(int*, const double*, int*, double*, int*, mango::Problem*, void*);

  class Solver;
  class Problem {
  protected:
    // Many implementation details are hidden in the Solver class, so users see only the interface provided by Problem.
    Solver* solver;

  public:
    MPI_Partition mpi_partition;

    Problem(int, double*, objective_function_type, int, char**); // For non-least-squares problems
    ~Problem();

    void mpi_init(MPI_Comm);
    void set_algorithm(algorithm_type);
    void set_algorithm(std::string);
    void read_input_file(std::string);
    void set_output_filename(std::string);
    void set_bound_constraints(double*, double*);
    double optimize();
    int get_N_parameters();
    int get_best_function_evaluation();
    int get_function_evaluations();
    double* get_state_vector();
    void set_centered_differences(bool);
    void set_finite_difference_step_size(double);
    void set_max_function_evaluations(int);
    void set_verbose(int);
    void set_output_filename(std::string&);
    void set_user_data(void*);
    void set_relative_bound_constraints(double, double, double, bool);
  };

  
  //////////////////////////////////////////////////////////////////////////////////////
  // A least-squares problem is a subclass of Problem

  class Least_squares_solver;
  class Least_squares_problem : public Problem {
  private:
    // Many implementation details are hidden in the Least_squares_solver class, so users see only the interface provided by Least_squares_problem.
    Least_squares_solver* least_squares_solver;

  public:
    Least_squares_problem(int, double*, int, double*, double*, double*, residual_function_type, int, char**); // For least-squares problems
    ~Least_squares_problem();

    //double optimize();
    int get_N_terms();
    void set_print_residuals_in_output_file(bool);
  };
}

#endif
