#include <iostream>
#include <string>
#include <omp.h>
#include "lorenz.h"

#define OPENMP true

using namespace std;

void swap_rho(float* rho, int n)
{
    // Default parameters for sig and beta
    float sig  = 10;
    float beta = 8/3;
    // Default parameters for n_iter and dt
    int n_iter = 2000;
    float dt   = 1e-2;

    // Run over rhos in parallel
    #pragma omp parallel for
    for(int i=0; i<100; i++)
    {
        // Instantiate class pointing to null
        lorenz l   = lorenz(sig,beta,rho[i],n_iter,dt);
        // Run simulation
        l.run();
        // Saving the results
        string s = "data/results"+to_string(i)+".txt";
        const char* filename = s.c_str();
        // filename = srtcat("data/results",atoa(i));
        // filename = strcat(filename,".txt");
        l.save(filename);
    }
}

int main() 
{
    // If OPENMP is false runs for one value of rho
    if(OPENMP==false)
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
        l.save("results.txt");
    } 
    // Else it runs the model for several rhos in parallel using MPI
    else 
    {
        float* rhos = (float*) calloc(100, sizeof(float));
        for(auto i=0; i<100;i++) 
        {
            rhos[i] = 20 +i*0.1;
        }

        swap_rho(rhos,100);
    }

    return 1;
}
