#include "heat_addition.h"
#include "../tools/gas.h"


HeatAddition::HeatAddition(double heating_val, bool isOtto) : heating_value(heating_val), isOtto(isOtto) {}


void HeatAddition::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{

    State compression_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1);;

    double pressure, temperature, specific_vol, enthalpy, internal_energy, entropy;

    if(isOtto)
    {
        specific_vol = compression_state.specific_vol;

        internal_energy = this->heating_value + compression_state.internal_energy;

        temperature = internal_energy / AIR.get_cv(compression_state.temperature);

        pressure = AIR.get_R() * temperature / specific_vol;

        enthalpy = AIR.get_enthalpy(temperature);

        entropy = AIR.get_entropy(temperature);
    }
    else
    {
        pressure = compression_state.pressure;

        enthalpy = this->heating_value - compression_state.enthalpy;

        temperature = enthalpy / AIR.get_cp(compression_state.temperature);

        specific_vol = AIR.get_R() * temperature / pressure;

        internal_energy = AIR.get_internal_energy(temperature);

        entropy = AIR.get_entropy(temperature);
    }

    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy);
}