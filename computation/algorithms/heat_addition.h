#pragma once
#include "thermo_state.h"
#include "../tools/gas.h"
#include <cmath>

class HeatAddition {
    private:
        bool isOtto;
<<<<<<< HEAD
        double heating_value, work;
=======
        bool isClosedSystem; 
        double heating_value;
        double work_done;  
>>>>>>> parent of e8b4a44 (Merge branch 'main' of https://github.com/ZeshanAJavaid/Thermodynamic-Cycle-Simulator)

    public:
        HeatAddition(double, bool, bool); 
        void compute(ThermodynamicCycle&, const AirProperties&);
        double get_heating_value();
        double get_work();
<<<<<<< HEAD

};
=======
};
>>>>>>> parent of e8b4a44 (Merge branch 'main' of https://github.com/ZeshanAJavaid/Thermodynamic-Cycle-Simulator)
