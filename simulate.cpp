#include <iostream>
#include "lorenz.h"

using namespace std;

int main() 
{
    // Defining model parameters
    float sig  = 10;
    float beta = 8/3;
    float rho  = 28;
    // Defining simulation parameters
    int n_iter = 10000;
    float dt   = 0.01;

    // Create lorenz's attractor object
    lorenz l = lorenz(sig, beta, rho, n_iter, dt);

    // Run simulation
    l.run();

    // Saving the results
    l.save();
    
    return 1;
}
