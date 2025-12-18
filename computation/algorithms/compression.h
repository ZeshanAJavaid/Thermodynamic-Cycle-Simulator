#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class Compression {
    private:
        double work, pressure_ratio, isentropic_efficiency;
        bool isBrayton;

    public:
        Compression(double,double,bool);
        void compute(ThermodynamicCycle&, const AirProperties&);
        double get_work();
        double get_heat();

};

