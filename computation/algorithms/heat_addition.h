#pragma once
#include "thermo_state.h"

class HeatAddition {
    private:
        double heating_val;
    public:
        void compute(ThermodynamicCycle);

};