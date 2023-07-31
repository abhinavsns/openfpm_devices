#include "cudify_hardware_cpu.hpp"
#ifdef HAVE_BOOST_CONTEXT
#include <boost/context/continuation.hpp>
#endif
#include <vector>
#include "config.h"

#ifdef HAVE_ALPAKA
#include "alpala/cudify_hardware_alpaka.hpp"

alpa_base_structs __alpa_base__;
#endif

#if defined(CUDIFY_USE_SEQUENTIAL) || defined(CUDIFY_USE_OPENMP)

thread_local dim3 threadIdx;
thread_local dim3 blockIdx;

unsigned int * tid_x[OPENMP_MAX_NUM_THREADS];
unsigned int * tid_y[OPENMP_MAX_NUM_THREADS];
unsigned int * tid_z[OPENMP_MAX_NUM_THREADS];

dim3 blockDim;
dim3 gridDim;

#endif

bool init_wrappers_call = false;

thread_local int vct_atomic_add;
thread_local int vct_atomic_rem;

size_t n_workers = 1;

#ifdef HAVE_BOOST_CONTEXT
std::vector<void *> mem_stack;

std::vector<boost::context::detail::fcontext_t> contexts;
thread_local void * par_glob;
thread_local boost::context::detail::fcontext_t main_ctx;
#endif
