#pragma once
#include "thermo_state.h"
#include "compression.h"
#include "expansion.h"
#include "heat_addition.h"
#include "heat_rejection.h"
#include <fstream>
#include <string>

using namespace std;

class Performance
{
    private:

        // Define needed variables for this class
        double work_compres, heat_addition, work_expan, heat_rejection, work_cycle;
        double efficiency, max_efficiency;

    public:

        /**
         * @brief Constructor
         * @param  none
         */
        Performance();

        /**
         * @brief Computes the Thermodynamic Performance of a Cycle
         * @param compression -> The compressor object of the cycle
         * @param heat_addition -> The heat addition object of the cycle
         * @param expansion -> The expansion object of the cycle
         * @param heat_rejection -> The heat rejection object of the cycle
         * @return none
         */
        void compute(Compression& compression, HeatAddition& heat_addition, Expansion& expansion, HeatRejection& heat_rejection);
        
        /**
         * @brief Outputs the Thermodynamic Performance of a Cycle as a csv file
         * @param fileName -> The output csv file name
         * @return none
         * @file outputs a csv file containing all performance values of a Cycle
         */
        void output_csv(string fileName);

        /**
         * @brief Getter for Thermodynamic Efficiency
         * @return Thermodynamic Efficiency
         */
        double get_eff();

        /**
         * @brief Getter for Compressor/Compression Work
         * @return Compressor/Compression Work
         */
        double get_work_c();

        /**
         * @brief Getter for Turbine/Expansion Work
         * @return Turbine/Expansion Work
         */
        double get_work_expan();

        /**
         * @brief Getter for Work_Cycle
         * @return Work_Cycle
         */
        double get_work_cycle();

        /**
         * @brief Getter for Heat added
         * @return Q_in
         */
        double get_heat_add();

        /**
         * @brief Getter for Heat Rejected
         * @return Q_out
         */
        double get_heat_rej();

        /**
         * @brief Getter for Thermodynamic Efficiency
         * @param eff Thermodynamic Efficiency
         */
        void set_eff(double eff);

        /**
         * @brief Getter for Compressor/Compression Work
         * @param work_c Compressor/Compression Work
         */
        void set_work_c(double work_c);

        /**
         * @brief Getter for Turbine/Expansion Work
         * @param work_expan Turbine/Expansion Work
         */
        void set_work_expan(double work_expan);

        /**
         * @brief Getter for Work_Cycle
         * @param work_cycle Work_Cycle
         */
        void set_work_cycle(double work_cycle);

        /**
         * @brief Getter for Heat added
         * @param Q_in Heat Added
         */
        void set_heat_add(double Q_in);

        /**
         * @brief Getter for Heat Rejected
         * @param Q_out Heat Rejected
         */
        void set_heat_rej(double Q_out);
};