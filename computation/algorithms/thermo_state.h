#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;


struct State
{   
    /*
        UNITS:
            PRESSURE (kPa)
            TEMPERATURE (K)
            SPECIFIC VOLUME (m^3 / kg)
            ENTHALPY (kJ / kg)
            INTERNAL ENERGY (kJ / kg)
            ENTROPY (kJ /  K * kg)
    */
   
    double pressure, temperature, specific_vol, enthalpy, internal_energy, entropy;

    State(double,double,double,double,double,double);
};


class ThermodynamicCycle 
{
    private:
        vector<State> ThermodynamicStates;
    public:
        ThermodynamicCycle();
        vector<State> get_ThermodynamicStates();
        void add_ThermodynamicStates(double&, double&, double&, double&, double&, double&);
        void output_csv(string);
        
};  