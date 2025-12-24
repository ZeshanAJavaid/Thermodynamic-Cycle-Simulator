#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class Expansion{
    private:

        double work, isentropic_efficiency;
        bool isBrayton;

    public:

        Expansion(double,bool);
        double get_work();
        void compute(ThermodynamicCycle&, const AirProperties&);


};

