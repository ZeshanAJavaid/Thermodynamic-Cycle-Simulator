#pragma once
#include "../algorithms/compression.h"
#include "../algorithms/heat_addition.h"
#include "../algorithms/expansion.h"
#include "../algorithms/heat_rejection.h"
#include "../algorithms/overall_performance.h"
#include "../algorithms/thermo_state.h"
#include "../tools/gas.h"

class Brayton
{
    private:
    
        double initial_pressure, initial_temperature; 
        double compressor_efficiency, pressure_ratio, turbine_efficiency;
        const double heating_val = 4310; 
        const AirProperties AIR;

        Compression compressor;
        HeatAddition combustion_chamber;
        Expansion turbine;
        HeatRejection atmosphere;
        Performance performance_of_cycle;
        ThermodynamicCycle cycle;

    public:

    Brayton(double, double, double, double, double);
    void compute();
    double get_initial_pressure();
    double get_initial_temperature();
    double get_compressor_eff();
    double get_pressure_ratio();
    double get_turbine_efficiency();

};