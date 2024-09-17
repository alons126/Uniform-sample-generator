#include "Uniform_sample_generator.C"
#include "Uniform_sample_generator_e_tester.C"

#define independent_tester false

void CodeRun()
{
    // Uniform_sample_generator_e_tester(true, false, false);
    Uniform_sample_generator(true, false, false);
    Uniform_sample_generator(false, true, false);
    Uniform_sample_generator(false, false, true);
}
