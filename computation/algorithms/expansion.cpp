#include "expansion.h"
#include "../tools/gas.h"


Expansion::Expansion(double eff, bool isBrayton) : isentropic_efficiency(eff), isBrayton(isBrayton) {}

double Expansion::get_work() {return this->work;}

void Expansion::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    State heat_addition_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1);;
    double pressure_ratio;
    double pressure, temperature_ideal, temperature, specific_vol, enthalpy, internal_energy, entropy;

    if(!this->isBrayton)
    {
        pressure_ratio = heat_addition_state.specific_vol / state.get_ThermodynamicStates().at(0).specific_vol;

        specific_vol = state.get_ThermodynamicStates().at(0).specific_vol;

        if(this->isentropic_efficiency == 100)
        {
            pressure = heat_addition_state.pressure * pow(pressure_ratio,AIR.get_gamma(heat_addition_state.temperature));

            temperature = heat_addition_state.temperature * pow(pressure_ratio,AIR.get_gamma(heat_addition_state.temperature - 1));

            enthalpy = AIR.get_enthalpy(temperature);

            internal_energy = AIR.get_internal_energy(temperature);

            this->work = heat_addition_state.internal_energy - internal_energy;

            entropy = heat_addition_state.entropy;
        }
        else
        {
            pressure = heat_addition_state.pressure * pow(pressure_ratio,AIR.get_gamma(heat_addition_state.temperature));

            temperature_ideal = heat_addition_state.temperature * pow(pressure_ratio,AIR.get_gamma(heat_addition_state.temperature - 1));

            this->work = (heat_addition_state.internal_energy - AIR.get_internal_energy(temperature)) * this->isentropic_efficiency / 100;

            internal_energy = heat_addition_state.internal_energy - this->work;

            temperature = internal_energy / AIR.get_cv(temperature_ideal);

            enthalpy = AIR.get_enthalpy(temperature);
            
            entropy = heat_addition_state.entropy + AIR.get_cv(temperature) * log(temperature / heat_addition_state.temperature) + AIR.get_R() * log(1 / pressure_ratio);

        }
    }
    else
    {
        pressure_ratio = state.get_ThermodynamicStates().at(0).pressure / heat_addition_state.pressure;
        
        pressure = pressure_ratio * heat_addition_state.pressure;

        if(this->isentropic_efficiency == 100)
        {   

            temperature = heat_addition_state.temperature * pow(pressure_ratio,(AIR.get_gamma(heat_addition_state.temperature) - 1) / AIR.get_gamma(heat_addition_state.temperature));

            specific_vol = heat_addition_state.specific_vol * pow(pressure_ratio, 1 / AIR.get_gamma(temperature));

            enthalpy = AIR.get_enthalpy(temperature);

            this->work = heat_addition_state.enthalpy - enthalpy;

            internal_energy = AIR.get_internal_energy(temperature);

            entropy = heat_addition_state.entropy;
        }
        else
        {
            temperature_ideal = heat_addition_state.temperature * pow(pressure_ratio,(AIR.get_gamma(heat_addition_state.temperature) - 1) / AIR.get_gamma(heat_addition_state.temperature));

            this->work = (heat_addition_state.enthalpy - AIR.get_enthalpy(temperature_ideal)) * this->isentropic_efficiency / 100;

            enthalpy = heat_addition_state.enthalpy - this->work;

            temperature = enthalpy / AIR.get_cp(temperature_ideal);

            specific_vol = heat_addition_state.specific_vol * pow(pressure_ratio, 1 / AIR.get_gamma(temperature));

            internal_energy = AIR.get_internal_energy(temperature);

            entropy = heat_addition_state.entropy + AIR.get_cp(temperature) * log(temperature / heat_addition_state.temperature) - AIR.get_R() * log(pressure_ratio);
        }
    }

    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy);
    
}