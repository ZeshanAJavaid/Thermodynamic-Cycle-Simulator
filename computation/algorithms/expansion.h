#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class Expansion{
    private:

        // Define required variables
        double work, isentropic_efficiency;
        bool isBrayton;

    public:

        /**
         * @brief Constructor
         * @param isentropic_efficiency -> Isentropic efficiency
         * @param isBrayton -> if Cycle is brayton cycle 
         */
        Expansion(double isentropic_efficiency,bool isBrayton);

         /**
         * @brief Computes the Thermodynamic Properties after Expansion
         * @param state -> Thermodynamic Object Reference to add the Expansion Thermodynamic Properties to
         * @param AIR -> AirProperties Object Reference to use the ideal gas properties and formulas
         * @return none 
         */
        void compute(ThermodynamicCycle&state , const AirProperties& AIR);

        /// @brief  Getter for work
        /// @return work of turbine/expansion, (kJ / kg)
        double get_work();

        /// @brief  Getter for isentropic efficiency
        /// @return isentropic efficiency, (%)
        double get_isentropic_efficiency();

        /// @brief  Getter for isBrayton
        /// @return a boolean value that indicates if cycle is brayton or not
        bool get_isBrayton();

        /// @brief  Setter for work
        /// @return work of turbine/expansion, (kJ / kg)
        void set_work(double work);

        /// @brief  Setter for isentropic_efficiency
        /// @return isentropic_efficiency, (%)
        void set_isentropic_efficiency(double isentropic_efficiency);

        /// @brief  Setter for isBrayton
        /// @return isBrayton bool value
        void set_isBrayton(bool isBrayton);
};

