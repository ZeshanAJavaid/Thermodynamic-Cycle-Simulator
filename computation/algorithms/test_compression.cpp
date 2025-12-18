#include "compression.h"
#include "../tools/gas.cpp"
#include <iostream>
int main()
{
    Compression compres(8,90,false);

    ThermodynamicCycle c;

    c.add_ThermodynamicStates(100, 400, AirProperties().get_R() * 400 / 100, 400.98, 286.16, AirProperties().get_entropy(400));

    compres.compute(c,AirProperties());

    for(auto val: c.get_ThermodynamicStates())
    {
        std::cout << val.pressure << " " << val.temperature << " " << val.specific_vol << " " << val.enthalpy << " " << val.internal_energy << " " << val.entropy << std::endl;
    }

    return 0;
}