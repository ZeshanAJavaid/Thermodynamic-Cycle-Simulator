#include "overall_performance.h"

Performance::Performance() {}

void Performance::compute(Compression& compres, HeatAddition& heat_add, Expansion& expans, HeatRejection& heat_rej)
{
    this->work_compres = compres.get_work();
    this->work_expan = expans.get_work();
    
    double work_combustion = heat_add.get_work(); 
    
    this->heat_addition = heat_add.get_heating_value();
    this->heat_rejection = heat_rej.get_heat();

    this->efficiency = ((this->work_expan + work_combustion - this->work_compres) / this->heat_addition);
}

void Performance::output_csv(string file_name)
{
    ofstream ofs("./output/"+file_name);

    ofs << "Efficiency, Work of Compressor (kJ / kg), Work of Turbine (kJ / kg), Work of Cycle (kJ / kg), Heat Addition (kJ / kg), Heat Rejection (kJ / kg)\n";
    ofs << (this->efficiency * 100) << "," << this->work_compres << "," << this->work_expan << "," << (this->work_expan - this->work_compres) << "," << this->heat_addition << "," << this->heat_rejection;

}

double Performance::get_work_cycle()
{
    return this->work_expan - this->work_compres;
}

double Performance::get_work_c()
{
    return this->work_compres;
}

double Performance::get_work_expan()
{
    return this->work_expan;
}

double Performance::get_heat_add()
{
    return this->heat_addition;
}

double Performance::get_heat_rej()
{
    return this->heat_rejection;
}

double Performance::get_eff()
{
    return this->efficiency;
}