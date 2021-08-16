#ifndef ADDR_H
#define ADDR_H

class lorenz
{
    /*
     * Class to implement Lorenz's attractor.
     * dxdt = sig*(y-x)
     * dydt = x*(rho-z)-y
     * dzdt = x*y - beta*z
     */
    private:
        // Model parameters
        float sig, beta, rho;
        // Number of iterations and time step
        int n_iter;
        float dt;

        // Allocate memory for 1D arrays that will store the LA variables (x,y,z)
        void allocate_arrays(int n);
        
        //_________________________________________ODE METHODS________________________________________//
        float dxdt(float x, float y); 
        float dydt(float x, float y, float z); 
        float dzdt(float x, float y, float z); 

    public:
        // Arrays to store the simulation results
        float *x;
        float *y;
        float *z;
        // Default constructor
        lorenz();
        // Constructor initializing the private varibles
        lorenz(float sig, float beta, float rho);
        lorenz(float sig, float beta, float rho, int n_iter, float dt);
        
        //_________________________________________RUN METHOD_________________________________________//
        void run();
        
        //_________________________________________GET METHODS________________________________________//
        float get_sig();
        float get_beta();
        float get_rho();
        float get_n_iter();
        float get_dt();
        
        //_________________________________________SET METHODS________________________________________//
        void set_sig(float sig);
        void set_beta(float beta);
        void set_rho(float rho);
        void set_n_iter(float n_iter);
        void set_dt(float dt);

        //_________________________________________ SAVE FILE ________________________________________//
        void save();
};

#endif
