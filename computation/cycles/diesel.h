#pragma once
#include "../algorithms/compression.h"
#include "../algorithms/heat_addition.h"
#include "../algorithms/expansion.h"
#include "../algorithms/heat_rejection.h"
#include "../algorithms/overall_performance.h"
#include "../algorithms/thermo_state.h"
#include "../tools/gas.h"

class Diesel
{
    private:
    
        double initial_pressure, initial_temperature; 
        double squeeze_efficiency, compression_ratio, bang_efficiency;
        const double heating_val = 4600; 
        const AirProperties AIR;

        Compression squeeze;
        HeatAddition spark;
        Expansion bang;
        HeatRejection blow;
        Performance performance_of_cycle;
        ThermodynamicCycle cycle;

    public:

    Diesel(double, double, double, double, double);
    void compute();
    double get_initial_pressure();
    double get_initial_temperature();
    double get_compression_ratio();
    double get_squeeze_efficiency();
    double get_bang_efficiency();

};