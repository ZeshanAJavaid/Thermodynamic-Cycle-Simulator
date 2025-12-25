#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class HeatAddition {
    private:

        // Define important variables
        bool isOtto;
        double heating_value, work_done;
        bool isClosedSystem;

    public:

        /**
         * @brief Constructor
         * @param heating_value Q_in with the units (kJ / kg)
         * @param isOtto bool value that describes if its otto cycle or not
         * @param isClosedSystem bool value that describes heat addition does work to the control volume
         */
        HeatAddition(double heating_value, bool, bool); 

        /**
         * @brief Computes the Thermodynamic Properties after Heat Addition
         * @param state -> Thermodynamic Object Reference to add the Heat Addition Thermodynamic Properties to
         * @param AIR -> AirProperties Object Reference to use the ideal gas properties and formulas
         * @return none 
         */
        void compute(ThermodynamicCycle& state, const AirProperties& AIR);
        
        /**
         * @brief Getter for Heating Value
         * @return heating value (Q_in)
         */
        double get_heating_value();

        /**
         * @brief Getter for Work
         * @return Work Done
         */
        double get_work();

        /**
         * @brief Setter for Heating Value
         * @param heating_value (Q_in)
         */
        void set_heating_value(double heating_value);

        /**
         * @brief Setter for Work
         * @param work (work_done)
         */
        void set_work(double work);
};
