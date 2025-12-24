#include "gas.h"

using namespace std;

AirProperties::AirProperties()
{
       this->molar_mass = (this->air.N2.at(0).at(0) * this->air.N2.at(0).at(1)
                        + this->air.O2.at(0).at(0) * this->air.O2.at(0).at(1)
                        + this->air.Ar.at(0).at(0) * this->air.Ar.at(0).at(1)
                        + this->air.CO2.at(0).at(0) * this->air.CO2.at(0).at(1)
                        + this->air.He.at(0).at(0) * this->air.He.at(0).at(1)
                        + this->air.CH4.at(0).at(0) * this->air.CH4.at(0).at(1)
                        + this->air.Kr.at(0).at(0) * this->air.Kr.at(0).at(1)
                        + this->air.H2.at(0).at(0) * this->air.H2.at(0).at(1)) / 100;

       this->polynomial_consts_high = {
                                 (this->air.N2.at(1).at(0) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(1).at(0) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(1).at(0) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(1).at(0) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(1).at(0) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(1).at(0) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(1).at(0) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(1).at(0) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(1).at(1) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(1).at(1) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(1).at(1) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(1).at(1) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(1).at(1) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(1).at(1) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(1).at(1) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(1).at(1) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(1).at(2) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(1).at(2) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(1).at(2) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(1).at(2) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(1).at(2) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(1).at(2) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(1).at(2) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(1).at(2) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(1).at(3) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(1).at(3) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(1).at(3) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(1).at(3) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(1).at(3) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(1).at(3) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(1).at(3) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(1).at(3) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(1).at(4) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(1).at(4) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(1).at(4) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(1).at(4) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(1).at(4) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(1).at(4) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(1).at(4) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(1).at(4) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(1).at(5) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(1).at(5) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(1).at(5) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(1).at(5) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(1).at(5) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(1).at(5) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(1).at(5) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(1).at(5) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(1).at(6) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(1).at(6) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(1).at(6) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(1).at(6) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(1).at(6) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(1).at(6) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(1).at(6) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(1).at(6) * this->air.H2.at(0).at(1)) / 100,
       };

       this->polynomial_consts_low = {
                                 (this->air.N2.at(2).at(0) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(2).at(0) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(2).at(0) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(2).at(0) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(2).at(0) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(2).at(0) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(2).at(0) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(2).at(0) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(2).at(1) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(2).at(1) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(2).at(1) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(2).at(1) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(2).at(1) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(2).at(1) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(2).at(1) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(2).at(1) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(2).at(2) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(2).at(2) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(2).at(2) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(2).at(2) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(2).at(2) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(2).at(2) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(2).at(2) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(2).at(2) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(2).at(3) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(2).at(3) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(2).at(3) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(2).at(3) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(2).at(3) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(2).at(3) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(2).at(3) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(2).at(3) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(2).at(4) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(2).at(4) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(2).at(4) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(2).at(4) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(2).at(4) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(2).at(4) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(2).at(4) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(2).at(4) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(2).at(5) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(2).at(5) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(2).at(5) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(2).at(5) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(2).at(5) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(2).at(5) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(2).at(5) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(2).at(5) * this->air.H2.at(0).at(1)) / 100,

                               (this->air.N2.at(2).at(6) * this->air.N2.at(0).at(1)
                               + this->air.O2.at(2).at(6) * this->air.O2.at(0).at(1)
                               + this->air.Ar.at(2).at(6) * this->air.Ar.at(0).at(1)
                               + this->air.CO2.at(2).at(6) * this->air.CO2.at(0).at(1)
                               + this->air.He.at(2).at(6) * this->air.He.at(0).at(1)
                               + this->air.CH4.at(2).at(6) * this->air.CH4.at(0).at(1)
                               + this->air.Kr.at(2).at(6) * this->air.Kr.at(0).at(1)
                               + this->air.H2.at(2).at(6) * this->air.H2.at(0).at(1)) / 100,
       };
}

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
    double T = 300.0;
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
    double T = 300.0; 
    for(int i = 0; i < 50; i++)
    {
       double u_guess = this->get_internal_energy(T);
       double error = u_guess - target_u;
       
       if(abs(error) < 0.01) return T; 
       
       T = T - error / this->get_cv(T);
    }
    return T;
}