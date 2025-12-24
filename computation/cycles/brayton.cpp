#include "brayton.h"


Brayton::Brayton(double p, double T, double compres_eff, double ratio, double turbine_eff ) : 
    initial_pressure(p), initial_temperature(T), compressor_efficiency(compres_eff), pressure_ratio(ratio), turbine_efficiency(turbine_eff), 
    compressor(Compression(pressure_ratio,compres_eff,true)), combustion_chamber(HeatAddition(this->heating_val, false, false)),
    turbine(Expansion(turbine_eff,true)), atmosphere(HeatRejection(true)), performance_of_cycle() {}


void Brayton::compute()
{
    double initial_specific_vol = AIR.get_R() * this->initial_temperature / this->initial_pressure, initial_enthalpy = AIR.get_enthalpy(this->initial_temperature), initial_internal_energy = AIR.get_internal_energy(this->initial_temperature), initial_entropy = AIR.get_entropy(this->initial_temperature);

    cycle.add_ThermodynamicStates(initial_pressure, initial_temperature, initial_specific_vol, initial_enthalpy, initial_internal_energy, initial_entropy);

    compressor.compute(cycle, AIR);

    combustion_chamber.compute(cycle, AIR);

    turbine.compute(cycle, AIR);

    atmosphere.compute(cycle, AIR);

    performance_of_cycle.compute(compressor, combustion_chamber, turbine, atmosphere);

    cycle.output_csv("cycle.csv");
    
    performance_of_cycle.output_csv("performance.csv");
}

double Brayton::get_compressor_eff() { return this->compressor_efficiency; }
double Brayton::get_initial_pressure() { return this->initial_pressure; }
double Brayton::get_initial_temperature() { return this->initial_temperature; }
double Brayton::get_pressure_ratio() { return this->pressure_ratio; }
double Brayton::get_turbine_efficiency() { return this->turbine_efficiency; }