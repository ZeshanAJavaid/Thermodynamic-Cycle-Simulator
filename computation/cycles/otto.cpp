#include "otto.h"


Otto::Otto(double p, double T, double squeeze_efficiency, double ratio, double bang_efficiency ) : 
    initial_pressure(p), initial_temperature(T), squeeze_efficiency(squeeze_efficiency), compression_ratio(ratio), bang_efficiency(bang_efficiency), 
    squeeze(Compression(ratio,squeeze_efficiency,false)), spark(HeatAddition(heating_val, true, true)),
    bang(Expansion(bang_efficiency,false)), blow(HeatRejection(false)), performance_of_cycle() {}


void Otto::compute()
{
    double initial_specific_vol = AIR.get_R() * this->initial_temperature / this->initial_pressure, initial_enthalpy = AIR.get_enthalpy(this->initial_temperature), initial_internal_energy = AIR.get_internal_energy(this->initial_temperature), initial_entropy = AIR.get_entropy(this->initial_temperature);

    cycle.add_ThermodynamicStates(initial_pressure, initial_temperature, initial_specific_vol, initial_enthalpy, initial_internal_energy, initial_entropy);

    squeeze.compute(cycle, AIR);

    spark.compute(cycle, AIR);

    bang.compute(cycle, AIR);

    blow.compute(cycle, AIR);

    performance_of_cycle.compute(squeeze, spark, bang, blow);

    cycle.output_csv("otto_cycle.csv");
    performance_of_cycle.output_csv("otto_performance.csv");
}

double Otto::get_squeeze_efficiency() { return this->squeeze_efficiency; }
double Otto::get_initial_pressure() { return this->initial_pressure; }
double Otto::get_initial_temperature() { return this->initial_temperature; }
double Otto::get_compression_ratio() { return this->compression_ratio; }
double Otto::get_bang_efficiency() { return this->bang_efficiency; }

