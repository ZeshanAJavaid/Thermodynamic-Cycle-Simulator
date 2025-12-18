#include "thermo_state.h"

ThermodynamicCycle::ThermodynamicCycle() {}

State::State(double pressure, double temperature, double specific_vol, double enthalpy, double internal_energy, double entropy) : pressure(pressure), temperature(temperature), specific_vol(specific_vol), enthalpy(enthalpy), internal_energy(internal_energy), entropy(entropy) {}

vector<State> ThermodynamicCycle::get_ThermodynamicStates() {return this->ThermodynamicStates;}

void ThermodynamicCycle::add_ThermodynamicStates(double& pressure, double& temp, double& specific_vol, double& enthalpy, double& internal_energy, double& entropy)
{
    this->ThermodynamicStates.push_back(State(pressure,temp,specific_vol,enthalpy,internal_energy,entropy));
}

void ThermodynamicCycle::output_csv(string file_name)
{
    ofstream ofs("./output/"+file_name);

    for(auto state: this->ThermodynamicStates)
    {
        ofs << state.pressure << ",";
        ofs << state.temperature << ",";
        ofs << state.specific_vol << ",";
        ofs << state.enthalpy << ",";
        ofs << state.internal_energy << ",";
        ofs << state.entropy << ",";
        ofs << "\n";
    }
}