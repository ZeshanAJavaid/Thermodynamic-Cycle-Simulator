#include "compression.h"
#include "heat_addition.h"
#include "expansion.h"
#include "heat_rejection.h"
#include "../tools/gas.cpp"
#include <iostream>
int main()
{
    ThermodynamicCycle c;
    double pressure = 100, temperature = 400, specific_vol = AirProperties().get_R() * 400 / 100, enthalpy = AirProperties().get_enthalpy(400), internal_energy =AirProperties().get_internal_energy(400), entropy = AirProperties().get_entropy(400);
    c.add_ThermodynamicStates(pressure, temperature, specific_vol, enthalpy, internal_energy, entropy);


    Compression compres(6,90,false);
    HeatAddition heatadd(4280, false);
    Expansion exp(90,true);
    HeatRejection heatrej(true);

    compres.compute(c,AirProperties());
    heatadd.compute(c,AirProperties());
    exp.compute(c,AirProperties());
    heatrej.compute(c,AirProperties());

    std::string names[5] = {"Initial State: ","Compression State: ","Heat Addition State: ","Expansion State: ", "Heat Rejection State: "};

    size_t i{0};

    for(auto val: c.get_ThermodynamicStates())
    {
        std::cout << names[i] << val.pressure << " " << val.temperature << " " << val.specific_vol << " " << val.enthalpy << " " << val.internal_energy << " " << val.entropy << std::endl;
        i++;
    }

    return 0;
}