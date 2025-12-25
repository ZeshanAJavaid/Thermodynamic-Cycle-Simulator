#include "heat_rejection.h"
#include "../tools/gas.h"



HeatRejection::HeatRejection(bool isBrayton) : isBrayton(isBrayton) {}


void HeatRejection::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    State expansion_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1); // Get expansion state
    State initial_state =  state.get_ThermodynamicStates().at(0); // Get initial state

    // Calculate p5 using formula 5.1 in the readme
    double pressure = initial_state.pressure;
    // Calculate T5 using formula 5.2 in the readme
    double temperature = initial_state.temperature;
    // Calculate v5 using formula 5.3 in the readme
    double specific_vol = initial_state.specific_vol;
    // Calculate h5 using formula 5.4 in the readme
    double enthalpy = initial_state.enthalpy;
    // Calculate u5 using formula 5.5 in the readme
    double internal_energy =  initial_state.internal_energy;
    // Calculate s5 using formula 5.6 in the readme
    double entropy = initial_state.entropy;

    if(this->isBrayton)
    {
        // Calculate Q_out using formula 5.7.1 in the readme
        this->heat = expansion_state.enthalpy - initial_state.enthalpy;
    }
    else
    {
        // Calculate Q_out using formula 5.7.2 in the readme
        this->heat = expansion_state.internal_energy - initial_state.internal_energy;
    }

    // Add heat rejection state to the object, state.
    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy);
}

// Getters
double HeatRejection::get_heat() {return this->heat;}

bool HeatRejection::get_isBrayton() {return this->isBrayton;}



// Setters
void HeatRejection::set_heat(double heat) {this->heat = heat;}

void HeatRejection::set_isBrayton(bool isBrayton) {this->isBrayton = isBrayton;}