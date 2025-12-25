#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class HeatRejection {
    private:

        // Define Variables needed
        bool isBrayton;
        double heat;

    public:

        /**
         * @brief Constructor
         * @param isBrayton bool value that indicates if cycle is Brayton
         */
        HeatRejection(bool isBrayton);

        /**
         * @brief Computes the Thermodynamic Properties after Heat Rejection
         * @param state -> Thermodynamic Object Reference to add the Heat Rejection Thermodynamic Properties to
         * @param AIR -> AirProperties Object Reference to use the ideal gas properties and formulas
         */
        void compute(ThermodynamicCycle& state, const AirProperties& AIR);

        /**
         * @brief Getter for Heat
         * @return heat rejected (Q_out)
         */
        double get_heat();

        /**
         * @brief Getter for isBrayton
         * @return isBrayton bool value
         */
        bool get_isBrayton();

        /**
         * @brief Setter for Heat
         * @param heat heat_rejected (Q_out)
         */
        void set_heat(double heat);

        /**
         * @brief Setter for isBrayton
         * @param isBrayton true if cycle  is a brayton cycle
         */
        void set_isBrayton(bool isBrayton);

};
