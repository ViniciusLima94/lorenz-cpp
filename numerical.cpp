#include "numerical.h"

namespace numerical
{
    float euler(float f_x, float x, float dt) {
        /*
         * Compute the next value of x (x_{t+1}) using the Euler method.
         * x_{t+1} = x_{t} + dt * f(x_t)
         * - Inputs
         *   f_x |
         *   The current value of f_x
         *   x   | Float
         *   The current value of x
         * - dt  | float
         *   Integration time-step
         */
        return x + dt * f_x;
    }
}
