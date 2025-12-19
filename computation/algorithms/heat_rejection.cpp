#include "heat_rejection.h"
#include "../tools/gas.h"



HeatRejection::HeatRejection(bool isBrayton) : isBrayton(isBrayton) {}


void HeatRejection::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    State expansion_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1);
    State initial_state =  state.get_ThermodynamicStates().at(0);
    double pressure = initial_state.pressure, temperature = initial_state.temperature, specific_vol = initial_state.specific_vol, enthalpy = initial_state.enthalpy, internal_energy =  initial_state.internal_energy, entropy = initial_state.entropy;

    if(this->isBrayton)
    {
        this->heat = expansion_state.enthalpy - initial_state.enthalpy;
    }
    else
    {
        this->heat = expansion_state.internal_energy - initial_state.internal_energy;
    }

    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy);
}
