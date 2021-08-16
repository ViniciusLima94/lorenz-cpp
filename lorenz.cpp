#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "lorenz.h"
#include "numerical.h"

using namespace numerical;

lorenz::lorenz()
{
    // If constructor is called with no inputs default values are set.
    this->sig  = 10;
    this->beta = 8/3;
    this->rho  = 28;
    // Default values for n_iter and dt
    this->n_iter = 1000;
    this->dt     = 0.1;
    // Allocate memory for x,y,z variables
    this->allocate_arrays(n_iter);
}

lorenz::lorenz(float sig, float beta, float rho) 
{
    // Input assertion
    assert(sig>0);
    assert(beta>0);
    assert(sig>0);
    // Instantiate class using the provided parameter values.
    this->sig  = sig;
    this->beta = beta;
    this->rho  = rho;
    // Default values for n_iter and dt
    this->n_iter = 1000;
    this->dt     = 0.1;
    // Allocate memory for x,y,z variables
    this->allocate_arrays(n_iter);
}

lorenz::lorenz(float sig, float beta, float rho, int n_iter, float dt) 
{
    // Input assertion
    assert(sig>0);
    assert(beta>0);
    assert(sig>0);
    // Instantiate class using the provided parameter values.
    this->sig  = sig;
    this->beta = beta;
    this->rho  = rho;
    this->n_iter = n_iter;
    this->dt     = dt;
    // Allocate memory for x,y,z variables
    this->allocate_arrays(n_iter);
}

void lorenz::allocate_arrays(int n)
{
    this->x = (float*) calloc(n, sizeof(float));
    this->y = (float*) calloc(n, sizeof(float));
    this->z = (float*) calloc(n, sizeof(float));
}

//_________________________________________ODE METHODS________________________________________//
float lorenz::dxdt(float x, float y) 
{
    return this->sig*(y-x);
}

float lorenz::dydt(float x, float y, float z)
{
    return x*(this->rho-z)-y;
}

float lorenz::dzdt(float x, float y, float z)
{
    return x*y-this->beta*z;
}
//_________________________________________RUN METHOD_________________________________________//
void lorenz::run()
{
    // Initialize random seed:
    srand (time(NULL));

    // Initialize values with a random number between 0 and 1
    this->x[0] = (float) rand()/RAND_MAX;
    this->y[0] = (float) rand()/RAND_MAX;
    this->z[0] = (float) rand()/RAND_MAX;

    // Temporary variables
    float f_x, f_y, f_z;
    // Simulation loop
    for(auto t=0; t<this->n_iter-1; t++)
    {
        // Compute current value of dxdt, dydt and dzdt
        f_x = dxdt(this->x[t], this->y[t]);
        f_y = dydt(this->x[t], this->y[t], this->z[t]);
        f_z = dzdt(this->x[t], this->y[t], this->z[t]);
        // Compute next values of x, y, z using Euler's method
        this->x[t+1] = euler(f_x, this->x[t], this->dt);
        this->y[t+1] = euler(f_y, this->y[t], this->dt);
        this->z[t+1] = euler(f_z, this->z[t], this->dt);
    }
}

//_________________________________________GET METHODS________________________________________//
float lorenz::get_sig()
{
    return this->sig;
}

float lorenz::get_beta()
{
    return this->beta;
}

float lorenz::get_rho()
{
    return this->rho;
}

float lorenz::get_n_iter()
{
    return this->n_iter;
}

float lorenz::get_dt()
{
    return this->dt;
}

//_________________________________________SET METHODS________________________________________//
void lorenz::set_sig(float rho) 
{
    this->rho = rho;
}

void lorenz::set_beta(float beta) 
{
    this->beta = beta;
}

void lorenz::set_rho(float rho) 
{
    this->rho = rho;
}

void lorenz::set_n_iter(float n_iter) 
{
    this->n_iter = n_iter;
}

void lorenz::set_dt(float dt) 
{
    this->dt = dt;
}
        
//_________________________________________ SAVE FILE ________________________________________//
void lorenz::save(const char* filename) 
{
    // Save results to file
    std::ofstream myfile;    
    myfile.open(filename);

    for(auto t=0; t<this->n_iter; t++)
    {
        myfile << this->x[t] << "," << this->y[t] << "," << this->z[t] << "\n";
    }
    myfile.close();
}

