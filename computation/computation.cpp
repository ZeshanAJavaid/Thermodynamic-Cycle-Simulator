#include "computation.h"

Computation::Computation(Cycles c, double initial_pressure, double initial_temperature, double ratio, double compression_efficiency, double expansion_efficiency) :
cycle_type(c), initial_pressure(initial_pressure), initial_temperature(initial_temperature), ratio(ratio), compression_efficiency(compression_efficiency), expansion_efficiency(expansion_efficiency) {}

void Computation::compute()
{
    if(this->cycle_type == 0)
    {
        Brayton brayton_cycle(initial_pressure,initial_temperature,compression_efficiency,ratio,expansion_efficiency);

        brayton_cycle.compute();

    }
    else if(this->cycle_type == 1)
    {
        Otto otto_cycle(initial_pressure,initial_temperature,compression_efficiency,ratio,expansion_efficiency);

        otto_cycle.compute();
    }
    else if(this->cycle_type == 2)
    {
        Diesel diesel_cycle(initial_pressure,initial_temperature,compression_efficiency,ratio,expansion_efficiency);

        diesel_cycle.compute();
    }   
    else
    {
        throw std::invalid_argument("Incorrect Input");
    }
}