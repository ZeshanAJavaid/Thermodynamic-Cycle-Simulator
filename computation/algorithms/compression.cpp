#include "compression.h"

Compression::Compression(double pressure_ratio, double eff, bool isOtto) : pressure_ratio(pressure_ratio), isentropic_efficiency(eff), isOtto(isOtto) {}

double Compression::get_work()
{
    return this->work;
}

void Compression::compute(ThermodynamicCycle& state, const AirProperties& AIR)
{
    double pressure_ideal, pressure, temperature_ideal, temperature, specific_vol, enthalpy, internal_energy, entropy;
    State initial_state = state.get_ThermodynamicStates().at(state.get_ThermodynamicStates().size() - 1);;
    if(!this->isOtto)
    {
        pressure = initial_state.pressure * this->pressure_ratio; 

        if(this->isentropic_efficiency == 100)
        {
            temperature = initial_state.temperature * pow(this->pressure_ratio,((AIR.get_gamma(initial_state.temperature) - 1) / AIR.get_gamma(initial_state.temperature)));

            specific_vol = AIR.get_R() * pressure / temperature;

            this->work = (initial_state.enthalpy - AIR.get_enthalpy(temperature));

            enthalpy = AIR.get_enthalpy(temperature);

            internal_energy = AIR.get_internal_energy(temperature);

            entropy = initial_state.entropy;
        }
        else
        {
            temperature_ideal = initial_state.temperature * pow(this->pressure_ratio,((AIR.get_gamma(initial_state.temperature) - 1) / AIR.get_gamma(initial_state.temperature)));

            this->work = (initial_state.enthalpy - AIR.get_enthalpy(temperature_ideal)) / this->isentropic_efficiency * 100;

            enthalpy = initial_state.enthalpy -  this->work;
            
            temperature = enthalpy / AIR.get_cp(temperature_ideal);

            specific_vol = AIR.get_R() * temperature / pressure;

            internal_energy = AIR.get_internal_energy(temperature);
            
            entropy = initial_state.entropy + AIR.get_cp(temperature) * log(temperature / initial_state.temperature) - AIR.get_R() * log(pressure_ratio);
        }   
    }
    
    else
    {
        specific_vol = initial_state.specific_vol / this->pressure_ratio;

        if(this->isentropic_efficiency == 100)
        {
            pressure = initial_state.pressure * pow(pressure_ratio,AIR.get_gamma(initial_state.temperature));

            temperature = pressure * specific_vol / AIR.get_R();

            internal_energy = AIR.get_internal_energy(temperature);

            enthalpy = AIR.get_enthalpy(temperature);

            entropy = initial_state.entropy;
        }
        else
        {
            temperature_ideal = initial_state.temperature * pow(this->pressure_ratio, AIR.get_gamma(initial_state.temperature) - 1);

            this->work = (AIR.get_internal_energy(temperature_ideal) - initial_state.internal_energy) / this->isentropic_efficiency * 100;

            internal_energy = initial_state.internal_energy + this->work;

            temperature = internal_energy / AIR.get_cv(temperature_ideal);

            pressure = AIR.get_R() * temperature / specific_vol;

            enthalpy = AIR.get_enthalpy(temperature);

            entropy = initial_state.entropy + AIR.get_cv(temperature) * log(temperature / initial_state.temperature) + AIR.get_R() * log(1 / pressure_ratio);
        }
    }

    state.add_ThermodynamicStates(pressure,temperature,specific_vol,enthalpy,internal_energy,entropy);
}