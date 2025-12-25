#include "heat_addition.h"
#include "../tools/gas.h"


HeatAddition::HeatAddition(double heating_val, bool isOtto, bool isClosed) 
    : heating_value(heating_val), isOtto(isOtto), isClosedSystem(isClosed), work_done(0.0) {}

void HeatAddition::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    State compression_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1); // Get previous state
    double pressure, temperature, specific_vol, enthalpy, internal_energy, entropy; // Define thermodynamic properties

    if(isOtto) // Constant specific volume (v2 = v3)
    {
        // Calculate v3 using formula 3.2.3 in the readme
        specific_vol = compression_state.specific_vol;
        
        // Calculate u3 using formula 3.2.5 in the readme 
        internal_energy = this->heating_value + compression_state.internal_energy;
        
        // Calculate T3 using formula 3.2.2 in the readme 
        temperature = AIR.get_temperature_from_internal_energy(internal_energy); 
        
        // Calculate p3 using formula 3.2.1 in the readme 
        pressure = AIR.get_R() * temperature / specific_vol;
        
        // Calculate h3 using formula 3.2.4 in the readme 
        enthalpy = AIR.get_enthalpy(temperature);

        // Calculate h3 using formula 3.2.6 in the readme 
        entropy = compression_state.entropy + AIR.get_entropy(temperature) - AIR.get_entropy(compression_state.temperature);
        
        // Calculate Work using formula 3.2.8 in the readme 
        this->work_done = 0.0; 
    }
    else // Constant pressure (p2 = p3)
    {
        // Calculate p3 using formula 3.1.1 in the readme
        pressure = compression_state.pressure;

        // Calculate h3 using formula 3.1.4 in the readme
        enthalpy = this->heating_value + compression_state.enthalpy;

        // Calculate T3 using formula 3.1.2 in the readme
        temperature = AIR.get_temperature_from_enthalpy(enthalpy);

        // Calculate v3 using formula 3.1.3 in the readme
        specific_vol = AIR.get_R() * temperature / pressure;

        // Calculate u3 using formula 3.1.4 in the readme
        internal_energy = AIR.get_internal_energy(temperature);

        // Calculate s3 using formula 3.1.6 in the readme
        entropy = compression_state.entropy + AIR.get_entropy(temperature) - AIR.get_entropy(compression_state.temperature);

        if(this->isClosedSystem) {
            // Calculate Work Done using formula 3.1.8 in the readme
            this->work_done = pressure * (specific_vol - compression_state.specific_vol);
        } else {
            this->work_done = 0.0;
        }
    }

    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy); // Add thermodynamic states of Heat Addition into the state object
}

// Getters
double HeatAddition::get_work() { return this->work_done; }

double HeatAddition::get_heating_value() { return this->heating_value; }



// Setters
void HeatAddition::set_work(double work) { this->work_done = work; }

void HeatAddition::set_heating_value(double heating_value) { this->heating_value = heating_value; }