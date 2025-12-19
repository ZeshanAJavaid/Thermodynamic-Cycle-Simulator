#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class HeatAddition {
    private:

        bool isOtto;
        double heating_value;

    public:

        HeatAddition(double, bool);
        void compute(ThermodynamicCycle&, const AirProperties&);

};
