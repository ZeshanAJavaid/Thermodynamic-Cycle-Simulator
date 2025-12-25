#include "expansion.h"
#include "../tools/gas.h"


Expansion::Expansion(double eff, bool isBrayton) : isentropic_efficiency(eff), isBrayton(isBrayton) {}

void Expansion::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    State heat_addition_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1); // Get previous state
    double ratio, pressure, temperature_ideal, temperature, specific_vol, enthalpy, internal_energy, entropy; // Define thermodynamic properties

    if(!this->isBrayton) 
    {
        // Calculate r_c using v1 / v3
        ratio = heat_addition_state.specific_vol / state.get_ThermodynamicStates().at(0).specific_vol;

        // Calculate v4 using formula 4.3 in the readme
        specific_vol = state.get_ThermodynamicStates().at(0).specific_vol;

        if(this->isentropic_efficiency == 100) // Isentropic Expansion
        {
            // Calculate T4 using formula 4.2.2.1 in the readme
            temperature = heat_addition_state.temperature * pow(ratio,AIR.get_gamma(heat_addition_state.temperature) - 1);

            // Calculate p4 using formula 4.2.1.1 in the readme
            pressure = AIR.get_R() * temperature / specific_vol;

            // Calculat h4 using formula 4.2.4 in the readme
            enthalpy = AIR.get_enthalpy(temperature);

            // Calculate u4 using formula 4.2.5.1 in the readme
            internal_energy = AIR.get_internal_energy(temperature);

            // Calculate Work_Power Stroke using formula 4.2.7 in the readme
            this->work = heat_addition_state.internal_energy - internal_energy;

            // Isentropic -> s4 = s3
            entropy = heat_addition_state.entropy;
        }
        else
        {
            // Calculate p4 using formula 4.2.1.2 in the readme
            pressure = heat_addition_state.pressure * pow(ratio,AIR.get_gamma(heat_addition_state.temperature));

            // Calculate T4s using formula 4.2.2.1 in the readme
            temperature_ideal = heat_addition_state.temperature * pow(ratio,AIR.get_gamma(heat_addition_state.temperature) - 1);

            // Calculate W_Power Stroke using formula 4.2.7 in the readme
            this->work = (heat_addition_state.internal_energy - AIR.get_internal_energy(temperature_ideal)) * this->isentropic_efficiency / 100;

            // Calculate u4 using formula 4.2.5.2 in the readme
            internal_energy = heat_addition_state.internal_energy - this->work;

            // Calculate T4 using formula 4.2.2.2 in the readme
            temperature = AIR.get_temperature_from_internal_energy(internal_energy);

            // Calculate h4 usinf formula 4.2.4 in the readme
            enthalpy = AIR.get_enthalpy(temperature);
            
            // Calculate s4 using formula 4.2.6 in the readme
            entropy = heat_addition_state.entropy + AIR.get_entropy(temperature_ideal) - AIR.get_entropy(heat_addition_state.temperature) + AIR.get_R() * log(1 / ratio);
        }
    }
    else
    {
        // Calculate pressure ratio using r_p = p1 / p3
        ratio = state.get_ThermodynamicStates().at(0).pressure / heat_addition_state.pressure; 
        
        // Calculate p4 using formula 4.1.1
        pressure = state.get_ThermodynamicStates().at(0).pressure;

        if(this->isentropic_efficiency == 100) // Isentropic Expansion
        {   
            // Calculate T4 using formula 4.1.2.1 in the readme
            temperature = heat_addition_state.temperature * pow(ratio,(AIR.get_gamma(heat_addition_state.temperature) - 1) / AIR.get_gamma(heat_addition_state.temperature));

            // Calculate v4 using formula 4.1.3
            specific_vol = AIR.get_R() * temperature / pressure;

            // Calculate h4 using formula 4.1.4.1 in the readme
            enthalpy = AIR.get_enthalpy(temperature);

            // Calculate Work_Turbine using formula 4.1.7 in the readme
            this->work = heat_addition_state.enthalpy - enthalpy;

            // Calculate u4 using formula 4.1.5 in the readme
            internal_energy = AIR.get_internal_energy(temperature);

            // Isentropic -> s4 = s3
            entropy = heat_addition_state.entropy;
        }
        else
        {
            // Calculate T4s using formula 4.1.2.1 in the readme
            temperature_ideal = heat_addition_state.temperature * pow(ratio,(AIR.get_gamma(heat_addition_state.temperature) - 1) / AIR.get_gamma(heat_addition_state.temperature));

            // Calculate Work_Turbine using formula 4.1.7 in the readme
            this->work = (heat_addition_state.enthalpy - AIR.get_enthalpy(temperature_ideal)) * this->isentropic_efficiency / 100;

            // Calculate h4 using formula 4.1.4.2 in the readme
            enthalpy = heat_addition_state.enthalpy - this->work;

            // Calculate T4 using formula 4.1.2.2 in the readme
            temperature = temperature = AIR.get_temperature_from_enthalpy(enthalpy);

            // Calculate v4 using formula 4.1.3 in the readme
            specific_vol = AIR.get_R() * temperature / pressure;

            // Calculate u4 using formula 4.1.5 in the readme
            internal_energy = AIR.get_internal_energy(temperature);

            // Calculate s4 using formula 4.1.6 in the readme
            entropy = heat_addition_state.entropy + AIR.get_entropy(temperature_ideal) - AIR.get_entropy(heat_addition_state.temperature) - AIR.get_R() * log(ratio);
        }
    }

    // Add expansion thermodynamic states into the state object.
    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy);
}


// Getters
double Expansion::get_work() {return this->work;}

double Expansion::get_isentropic_efficiency() {return this->isentropic_efficiency;}

bool Expansion::get_isBrayton() {return this->isBrayton;}


// Setters
void Expansion::set_work(double work) {this->work = work;}

void Expansion::set_isentropic_efficiency(double isentropic_efficiency) {this->isentropic_efficiency = isentropic_efficiency;}

void Expansion::set_isBrayton(bool isBrayton) {this->isBrayton = isBrayton;}