#include "./cycles/brayton.h"
#include "./cycles/otto.h"
#include "./cycles/diesel.h"
#include "exception"

enum Cycles
{
    BRAYTON,
    OTTO,
    DIESEL
};

class Computation
{
    private:

        Cycles cycle_type;
        
        double initial_pressure, initial_temperature, ratio, compression_efficiency, expansion_efficiency;


    public:

    Computation(Cycles, double, double, double, double, double);

    void compute();


};