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
        double work_compres, heat_addition, work_expan, heat_rejection;
        double efficiency, max_efficiency;

    public:

        Performance();
        void compute(Compression&, HeatAddition&, Expansion&, HeatRejection&);
        void output_csv(string);
        double get_eff();
        double get_work_c();
        double get_work_expan();
        double get_work_cycle();
        double get_heat_add();
        double get_heat_rej();
};