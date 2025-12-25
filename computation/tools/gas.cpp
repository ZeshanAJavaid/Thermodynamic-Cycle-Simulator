#include "gas.h"

using namespace std;

AirProperties::AirProperties() {}

double AirProperties::get_cp(double temp) const{ 
       return temp > 1000 ? (this->polynomial_consts_high.at(0) + this->polynomial_consts_high.at(1) * temp + this->polynomial_consts_high.at(2) * temp * temp + this->polynomial_consts_high.at(3) * temp * temp * temp + this->polynomial_consts_high.at(4) * temp * temp * temp * temp) * this->R / (this->molar_mass)
                          : (this->polynomial_consts_low.at(0) + this->polynomial_consts_low.at(1) * temp + this->polynomial_consts_low.at(2) * temp * temp + this->polynomial_consts_low.at(3) * temp * temp * temp  + this->polynomial_consts_low.at(4) * temp * temp * temp * temp) * this->R / (this->molar_mass);
}

double AirProperties::get_cv(double temp) const{
       return temp > 1000 ? ((this->polynomial_consts_high.at(0) + this->polynomial_consts_high.at(1) * temp + this->polynomial_consts_high.at(2) * temp * temp + this->polynomial_consts_high.at(3) * temp * temp * temp + this->polynomial_consts_high.at(4) * temp * temp * temp * temp) * this->R - this->R ) / (this->molar_mass)
                          : ((this->polynomial_consts_low.at(0) + this->polynomial_consts_low.at(1) * temp + this->polynomial_consts_low.at(2) * temp * temp + this->polynomial_consts_low.at(3) * temp * temp * temp  + this->polynomial_consts_low.at(4) * temp * temp * temp * temp) * this->R - this->R ) / (this->molar_mass);
}

double AirProperties::get_gamma(double temp) const{ 
       return this->get_cp(temp) / this->get_cv(temp);
}

double AirProperties::get_enthalpy(double temp) const{
       return temp > 1000 ? (((this->polynomial_consts_high.at(0) + this->polynomial_consts_high.at(1) * temp / 2 + this->polynomial_consts_high.at(2) * temp * temp / 3 + this->polynomial_consts_high.at(3) * temp * temp * temp / 4 + this->polynomial_consts_high.at(4) * temp * temp * temp * temp / 5 + this->polynomial_consts_high.at(5) / temp) * this->R * temp / (this->molar_mass)) + this->get_cp(temp) * 259.55)
                          : (((this->polynomial_consts_low.at(0) + this->polynomial_consts_low.at(1) * temp / 2 + this->polynomial_consts_low.at(2) * temp * temp / 3 + this->polynomial_consts_low.at(3) * temp * temp * temp / 4 + this->polynomial_consts_low.at(4) * temp * temp * temp * temp / 5 + this->polynomial_consts_low.at(5) / temp) * this->R * temp / (this->molar_mass)) + this->get_cp(temp) * 301.236);
}

double AirProperties::get_internal_energy(double temp) const{
       return this->get_enthalpy(temp) - R * temp / this->molar_mass;
}

double AirProperties::get_entropy(double temp) const{
       return temp > 1000 ? (this->polynomial_consts_high.at(0) * log(temp) + this->polynomial_consts_high.at(1) * temp + this->polynomial_consts_high.at(2) * temp * temp / 2 + this->polynomial_consts_high.at(3) * temp * temp * temp / 3 + this->polynomial_consts_high.at(4) * temp * temp * temp * temp / 4 + this->polynomial_consts_high.at(6)) * this->R / (this->molar_mass) 
                          : (this->polynomial_consts_low.at(0) * log(temp) + this->polynomial_consts_low.at(1) * temp + this->polynomial_consts_low.at(2) * temp * temp / 2 + this->polynomial_consts_low.at(3) * temp * temp * temp / 3 + this->polynomial_consts_low.at(4) * temp * temp * temp * temp / 4 + this->polynomial_consts_low.at(6)) * this->R / (this->molar_mass); 
}
double AirProperties::get_R() const
{
       return this->R / this->molar_mass;
}

vector<double> AirProperties::get_high_polynomials() const
{
       return this->polynomial_consts_high;
}

vector<double> AirProperties::get_low_polynomials() const
{
       return this->polynomial_consts_low;
}

double AirProperties::get_temperature_from_enthalpy(double target_h) const
{
    double T = 298.15;
    for(int i = 0; i < 50; i++)
    {
       double h_guess = this->get_enthalpy(T);
       double error = h_guess - target_h;
       
       if(abs(error) < 0.01) return T;
       
       T = T - error / this->get_cp(T);
    }
    return T;
}

double AirProperties::get_temperature_from_internal_energy(double target_u) const
{
    double T = 298.15; 
    for(int i = 0; i < 50; i++)
    {
       double u_guess = this->get_internal_energy(T);
       double error = u_guess - target_u;
       
       if(abs(error) < 0.01) return T; 
       
       T = T - error / this->get_cv(T);
    }
    return T;
}