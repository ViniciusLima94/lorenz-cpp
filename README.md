# Implementation of the Lorenz's attractors in C++

The Lorenz's attractors are definded by the following set of equations:

\frac{dx}{dt} = \sigma*(y-x)

\frac{dy}{dt} = x(\rho-z)-y

\frac{dz}{dt} = xy-\beta z

### Compile and run

- To compile use: g++ numerical.cpp lorenz.cpp simulate.cpp -o simulate
- To run: ./simulate
- To visualize the results: python plotting.py


