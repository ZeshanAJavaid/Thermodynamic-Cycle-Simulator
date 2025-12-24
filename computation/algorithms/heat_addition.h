#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class HeatAddition {
    private:
        bool isOtto;
        double heating_value, work_done;
        bool isClosedSystem;

    public:
        HeatAddition(double, bool, bool); 
        void compute(ThermodynamicCycle&, const AirProperties&);
        double get_heating_value();
        double get_work();
};
