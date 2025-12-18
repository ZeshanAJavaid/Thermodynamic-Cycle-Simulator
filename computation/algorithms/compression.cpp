#include "compression.h"

Compression::Compression(double pressure_ratio, double eff, bool isBrayton) : pressure_ratio(pressure_ratio), isentropic_efficiency(eff), isBrayton(isBrayton) {}

double Compression::get_work()
{
    return this->work;
}

void Compression::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    double pressure_ideal, pressure, temperature_ideal, temperature, specific_vol, enthalpy, internal_energy, entropy;
    State initial_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1);

    
    if(this->isBrayton)
    {
        pressure = initial_state.pressure * this->pressure_ratio; 

        if(this->isentropic_efficiency == 100)
        {
            temperature = initial_state.temperature * pow(this->pressure_ratio,((AIR.get_gamma(initial_state.temperature) - 1) / AIR.get_gamma(initial_state.temperature)));

            specific_vol = AIR.get_R() * temperature / pressure;

            this->work = (AIR.get_enthalpy(temperature) - initial_state.enthalpy);

            enthalpy = AIR.get_enthalpy(temperature);

            internal_energy = AIR.get_internal_energy(temperature);

            entropy = initial_state.entropy;
        }
        else
        {
            temperature_ideal = initial_state.temperature * pow(this->pressure_ratio,((AIR.get_gamma(initial_state.temperature) - 1) / AIR.get_gamma(initial_state.temperature)));

            this->work = (AIR.get_enthalpy(temperature_ideal) - initial_state.enthalpy) / this->isentropic_efficiency * 100;

            enthalpy = initial_state.enthalpy +  this->work;
            
            temperature = AIR.get_temperature_from_enthalpy(enthalpy);

            specific_vol = AIR.get_R() * temperature / pressure;

            internal_energy = AIR.get_internal_energy(temperature);
            
            entropy = initial_state.entropy + AIR.get_entropy(temperature_ideal) - AIR.get_entropy(initial_state.temperature) - AIR.get_R() * log(pressure_ratio);
        }   
    }
    
    else
    {
        specific_vol = initial_state.specific_vol / this->pressure_ratio;

        if(this->isentropic_efficiency == 100)
        {
            pressure = initial_state.pressure * pow(pressure_ratio,AIR.get_gamma(initial_state.temperature));

            temperature = pressure * specific_vol / AIR.get_R();

            this->work = (AIR.get_internal_energy(temperature) - initial_state.internal_energy);

            internal_energy = AIR.get_internal_energy(temperature);

            enthalpy = AIR.get_enthalpy(temperature);

            entropy = initial_state.entropy;
        }
        else
        {
            temperature_ideal = initial_state.temperature * pow(this->pressure_ratio, AIR.get_gamma(initial_state.temperature) - 1);

            this->work = (AIR.get_internal_energy(temperature_ideal) - initial_state.internal_energy) / this->isentropic_efficiency * 100;

            internal_energy = initial_state.internal_energy + this->work;

            temperature = AIR.get_temperature_from_internal_energy(internal_energy);

            pressure = AIR.get_R() * temperature / specific_vol;

            enthalpy = AIR.get_enthalpy(temperature);

            entropy = initial_state.entropy + AIR.get_entropy(temperature_ideal) - AIR.get_entropy(initial_state.temperature) + AIR.get_R() * log(1 / pressure_ratio);
        }
    }

    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy);
}