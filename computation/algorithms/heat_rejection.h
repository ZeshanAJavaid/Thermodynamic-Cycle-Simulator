#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class HeatRejection {
    private:

        bool isBrayton;
        double heat;

    public:

        HeatRejection(bool);
        void compute(ThermodynamicCycle&, const AirProperties&);
        double get_heat();

};
