#include "heat_addition.h"
#include "../tools/gas.h"


HeatAddition::HeatAddition(double heating_val, bool isOtto, bool isClosed) 
    : heating_value(heating_val), isOtto(isOtto), isClosedSystem(isClosed), work_done(0.0) {}

void HeatAddition::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    State compression_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1);
    double pressure, temperature, specific_vol, enthalpy, internal_energy, entropy;

    if(isOtto)
    {
        specific_vol = compression_state.specific_vol;
        internal_energy = this->heating_value + compression_state.internal_energy;
        temperature = AIR.get_temperature_from_internal_energy(internal_energy); 
        pressure = AIR.get_R() * temperature / specific_vol;
        enthalpy = AIR.get_enthalpy(temperature);
        entropy = compression_state.entropy + AIR.get_entropy(temperature) - AIR.get_entropy(compression_state.temperature);
        
        this->work_done = 0.0; 
    }
    else
    {
        pressure = compression_state.pressure;
        enthalpy = this->heating_value + compression_state.enthalpy;
        temperature = AIR.get_temperature_from_enthalpy(enthalpy);
        specific_vol = AIR.get_R() * temperature / pressure;
        internal_energy = AIR.get_internal_energy(temperature);
        entropy = compression_state.entropy + AIR.get_entropy(temperature) - AIR.get_entropy(compression_state.temperature);

        if(this->isClosedSystem) {

            this->work_done = pressure * (specific_vol - compression_state.specific_vol);
        } else {
            
            this->work_done = 0.0;
        }
    }

    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy);
}

double HeatAddition::get_work() { return this->work_done; }
double HeatAddition::get_heating_value() { return this->heating_value; }