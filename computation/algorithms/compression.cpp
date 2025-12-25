#include "compression.h"

Compression::Compression(double pressure_or_compression_ratio, double eff, bool isBrayton) : work(0.0), pressure_or_compression_ratio(pressure_or_compression_ratio), isentropic_efficiency(eff), isBrayton(isBrayton) {}

void Compression::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    double pressure_ideal, pressure, temperature_ideal, temperature, specific_vol, enthalpy, internal_energy, entropy; // Define Thermodynamic States
    State initial_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1); // Get the Initial State

    if(this->isBrayton)
    {
        // Find P2 using formula 1.1.1 in the readme
        pressure = initial_state.pressure * this->pressure_or_compression_ratio; 

        if(this->isentropic_efficiency == 100) // Isentropic Proccess
        {
            // Find T2 using formula 1.1.2.1 in the readme
            temperature = initial_state.temperature * pow(this->pressure_or_compression_ratio,((AIR.get_gamma(initial_state.temperature) - 1) / AIR.get_gamma(initial_state.temperature))); 

            // Find v2 using formula 1.1.3 in the readme
            specific_vol = AIR.get_R() * temperature / pressure; 

            // Find W_compressor using formula 1.1.7 in the readme
            this->work = (AIR.get_enthalpy(temperature) - initial_state.enthalpy); 

            // Find h using formula 1.1.4.1 in the readme
            enthalpy = AIR.get_enthalpy(temperature);  

            // Find u using formula 1.1.5.1 in the readme
            internal_energy = AIR.get_internal_energy(temperature); 

            // Isentropic -> s2 = s1
            entropy = initial_state.entropy; 
        }
        else
        {
            // Find T2s using formula 1.1.2.1 in the readme
            temperature_ideal = initial_state.temperature * pow(this->pressure_or_compression_ratio,((AIR.get_gamma(initial_state.temperature) - 1) / AIR.get_gamma(initial_state.temperature))); 

            // Find W_compressor using formula 1.1.7 in the readme
            this->work = (AIR.get_enthalpy(temperature_ideal) - initial_state.enthalpy) / this->isentropic_efficiency * 100;

            // Find h using formula 1.1.4.2 in the readme
            enthalpy = initial_state.enthalpy +  this->work; 
            
            // Find T2 using formula 1.1.2.2 in the readme
            temperature = AIR.get_temperature_from_enthalpy(enthalpy);

            // Find v2 using formula 1.1.3 in the readme
            specific_vol = AIR.get_R() * temperature / pressure;

            // Find u2 using formula 1.1.5.1 in the readme
            internal_energy = AIR.get_internal_energy(temperature);
            
            // Find s2 using formula 1.1.6 in the readme
            entropy = initial_state.entropy + AIR.get_entropy(temperature_ideal) - AIR.get_entropy(initial_state.temperature) - AIR.get_R() * log(pressure_or_compression_ratio);
        }   
    }
    
    else
    {
        // Find V2 using formula 2.2.3 in the readme
        specific_vol = initial_state.specific_vol / this->pressure_or_compression_ratio; 

        if(this->isentropic_efficiency == 100) // Isentropic Proccess 
        {
            // Find p2 using formula 2.2.1.1 in the readme
            pressure = initial_state.pressure * pow(pressure_or_compression_ratio,AIR.get_gamma(initial_state.temperature)); 

            // Find T2 using formula 2.2.2.1 in the readme
            temperature = pressure * specific_vol / AIR.get_R();

            // Find Work_compression using formula 2.2.7 in the readme
            this->work = (AIR.get_internal_energy(temperature) - initial_state.internal_energy);

            // Find u2 using formula 2.2.5.1 in the readme
            internal_energy = AIR.get_internal_energy(temperature);

            // Find h2 using formula 2.2.4 in the readme
            enthalpy = AIR.get_enthalpy(temperature);

            // Isentropic -> s2 = s1
            entropy = initial_state.entropy;
        }
        else
        {
            // Find T2s using formula 2.2.2.2 in the readme
            temperature_ideal = initial_state.temperature * pow(this->pressure_or_compression_ratio, AIR.get_gamma(initial_state.temperature) - 1);

            // Find Work_compression stroke using formula 2.2.7 in the readme
            this->work = (AIR.get_internal_energy(temperature_ideal) - initial_state.internal_energy) / this->isentropic_efficiency * 100;

            // Find u2 using formula 2.2.5.2 in the readme
            internal_energy = initial_state.internal_energy + this->work;

            // Find T2 using formula 2.2.2.3 in the readme
            temperature = AIR.get_temperature_from_internal_energy(internal_energy);

            // Find p2 using formula 2.2.1.2 in the readme
            pressure = AIR.get_R() * temperature / specific_vol;

            // Find h2 using formula 2.2.4 in the readme
            enthalpy = AIR.get_enthalpy(temperature);

            // Find s2 using formula 2.2.6 in the readme
            entropy = initial_state.entropy + AIR.get_entropy(temperature_ideal) - AIR.get_entropy(initial_state.temperature) + AIR.get_R() * log(1 / pressure_or_compression_ratio);
        }
    }

    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy); // Add compression state to state object
}


// Getters
double Compression::get_work() {return this->work;}

double Compression::get_pressure_or_compression_ratio() {return this->pressure_or_compression_ratio;}

double Compression::get_isentropic_efficiency() {return this->isentropic_efficiency;}

bool Compression::get_isBrayton() {return this->isBrayton;}



// Setters
void Compression::set_work(double work) {this->work = work;}

void Compression::set_pressure_or_compression_ratio(double pressure_or_compression_ratio){this->pressure_or_compression_ratio = pressure_or_compression_ratio;}

void Compression::set_isentropic_efficiency(double isentropic_efficiency){this->isentropic_efficiency = isentropic_efficiency;}

void Compression::set_isBrayton(bool isBrayton){this->isBrayton = isBrayton;}