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

    /**
     * @brief Constructor for State struct
     * @param pressure (kPa)
     * @param temperature (K)
     * @param specific_vol (m^3 / kg)
     * @param enthalpy (kJ / kg)
     * @param internal_energy (kJ / kg)
     * @param entropy (kJ / kg*K)
     */
    State(double pressure, double temperature, double specific_vol,
        double enthalpy, double internal_energy, double entropy);
};


class ThermodynamicCycle 
{
    private:

        // Required Variables to keep track of every process
        vector<State> ThermodynamicStates;
    public:

        /**
         * @brief Constructor for State struct
         * @param none
         */
        ThermodynamicCycle();

        /**
         * @brief Getter for ThermodynamicStates
         * @return vector<State> ThermodynamicStates
         */
        vector<State> get_ThermodynamicStates();

        /**
         * @brief Getter for ThermodynamicStates
         * @param pressure (kPa)
         * @param temperature (K)
         * @param specific_vol (m^3 / kg)
         * @param enthalpy (kJ / kg)
         * @param internal_energy (kJ / kg)
         * @param entropy (kJ / kg*K)
         */
        void add_ThermodynamicStates(double pressure, double temperature, double specific_vol, 
                                    double enthalpy, double internal_energy, double entropy);
        
        /**
         * @brief Outputs the Thermodynamic States of a Cycle as a csv file
         * @param fileName -> The output csv file name
         * @return none
         * @file outputs a csv file containing all thermodynamic states
         */
        void output_csv(string);
        
};  