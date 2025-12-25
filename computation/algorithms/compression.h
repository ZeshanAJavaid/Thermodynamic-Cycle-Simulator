#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class Compression {
    private:
        // Define Required Variables
        double work, pressure_or_compression_ratio, isentropic_efficiency;
        bool isBrayton;

    public:

        /**
         * @brief Default Constructor
         * @param pressure_or_compression_ratio -> Pressure Ratio (P2/P1) or Compression Ratio (V1/V2)
         * @param isentropic_efficiency -> Isentropic Efficiency (%) of compression process
         * @param isBrayton -> Defines if the type of cycle is Brayton or not; Brayton cycle uses pressure ratio whereas diesel and otto use compression ratio
         */ 
        Compression(double pressure_ratio, double isentropic_efficiency, bool isBrayton);

         /**
         * @brief Computes the Thermodynamic Properties after Compression
         * @param state -> Thermodynamic Object Reference to add the Compression Thermodynamic Properties to
         * @param AIR -> AirProperties Object Reference to use the ideal gas properties and formulas
         * @return none 
         */ 
        void compute(ThermodynamicCycle& state, const AirProperties& AIR);

        /// @brief  Getter for work
        /// @return work of compression/compressor, (kJ / kg)
        double get_work();

        /// @brief  Getter for pressure_or_compression_ratio
        /// @return pressure_or_compression_ratio 
        double get_pressure_or_compression_ratio ();

        /// @brief  Getter for isentropic_efficiency
        /// @return isentropic_efficiency, (%)
        double get_isentropic_efficiency();

        /// @brief  Getter for isBrayton
        /// @return isBrayton bool value
        bool get_isBrayton();

        /// @brief  Setter for work
        /// @return work of compression/compressor, (kJ / kg)
        void set_work(double work);

        /// @brief  Setter for pressure_or_compression_ratio
        /// @param pressure_or_compression_ratio 
        void set_pressure_or_compression_ratio(double pressure_or_compression_ratio);

        /// @brief  Setter for isentropic_efficiency
        /// @param isentropic_efficiency, (%)
        void set_isentropic_efficiency(double isentropic_efficiency);

        /// @brief  Setter for isBrayton
        /// @param isBrayton bool value
        void set_isBrayton(bool isBrayton);

};

