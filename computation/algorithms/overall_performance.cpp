#include "overall_performance.h"

Performance::Performance() {}

void Performance::compute(Compression& compres, HeatAddition& heat_add, Expansion& expans, HeatRejection& heat_rej)
{
    this->work_compres = compres.get_work();
    this->work_expan = expans.get_work();
    double work_combustion = heat_add.get_work(); 
    // Calculate efficiency using formula 6.1 in the readme
    this->work_cycle = this->work_expan + work_combustion - this->work_compres;
    
    this->heat_addition = heat_add.get_heating_value();
    this->heat_rejection = heat_rej.get_heat();

    // Calculate efficiency using formula 6.2 in the readme
    this->efficiency = ((this->work_cycle / this->heat_addition) + (1 - this->heat_rejection / this->heat_addition)) / 2;
}

void Performance::output_csv(string file_name)
{
    ofstream ofs(string(PROJECT_PATH) + "/output/"+file_name); // PROJECT_PATH is a macro created by the cmake to indicate the root directory of this project

    ofs << "Efficiency, Work of Compressor (kJ / kg), Work of Turbine (kJ / kg), Work of Cycle (kJ / kg), Heat Addition (kJ / kg), Heat Rejection (kJ / kg)\n";
    ofs << (this->efficiency * 100) << "," << this->work_compres << "," << this->work_expan << "," << (this->work_expan - this->work_compres) << "," << this->heat_addition << "," << this->heat_rejection;

}



// Getters
double Performance::get_work_cycle(){return this->work_expan - this->work_compres;}

double Performance::get_work_c(){return this->work_compres;}

double Performance::get_work_expan(){return this->work_expan;}

double Performance::get_heat_add(){return this->heat_addition;}

double Performance::get_heat_rej(){return this->heat_rejection;}

double Performance::get_eff(){return this->efficiency;}


// Setters
void Performance::set_work_cycle(double work_cycle){this->work_cycle = work_cycle;}

void Performance::set_work_c(double work_c){this->work_compres = work_c;}

void Performance::set_work_expan(double work_expan){this->work_expan = work_expan;}

void Performance::set_heat_add(double heat_add){this->heat_addition = heat_add;}

void Performance::set_heat_rej(double heat_rej){this->heat_rejection = heat_rej;}

void Performance::set_eff(double eff){this->efficiency = eff;}