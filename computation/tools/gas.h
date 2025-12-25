#pragma once
#include <vector>
#include <cmath>

using namespace std;

/** 
*   Define the NASA Polynomial constants for various gasses in the atmosphere
*   @details The format is as follows:
*   [[Molar Mass (g / mol), Percentage of Atmosphere (%)],
*   [The 6 low-polynomial constants for cp,cv,h,u, and s],
*   [The 6 high-polynomial constants for cp,cv,h,u, and s]]
*/
struct Air_Mixture
{

    const vector<vector<double>> N2 = {{28.01348, 78.084}, 
                {2.95257626E+00, 1.39690057E-03, -4.92631691E-07, 7.86010367E-11, -4.60755321E-15, -9.23948645E+02, 5.87189252E+00},
                {3.53100528E+00, -1.23660987E-04, -5.02999437E-07, 2.43530612E-09, -1.40881235E-12, -1.04697628E+03, 2.96747468E+00}};

    const vector<vector<double>>O2 = {{31.99880, 20.946},
                {3.66096083E+00, 6.56365523E-04, -1.41149485E-07, 2.05797658E-11, -1.29913248E-15, -1.21597725E+03, 3.41536184E+00},
                {3.78245636E+00, -2.99673415E-03, 9.84730200E-06, -9.68129508E-09, 3.24372836E-12, -1.06394356E+03, 3.65767573E+00}};

    const vector<vector<double>> Ar = {{39.94800, 0.9340},
                {2.50000000E+00, 0.0, 0.0, 0.0, 0.0, -7.45375000E+02, 4.37967491E+00},
                {2.50000000E+00, 0.0, 0.0, 0.0, 0.0, -7.45375000E+02, 4.37967491E+00}};

    const vector<vector<double>> CO2 = {{44.00980, 0.0407},
                {4.63659493E+00, 2.74131991E-03, -9.95828531E-07, 1.60373011E-10, -9.16103468E-15, -4.90249341E+04, -1.93534855E+00},
                {2.35677352E+00, 8.98459677E-03, -7.12356269E-06, 2.45919022E-09, -1.43699548E-13, -4.83719697E+04, 9.90105222E+00}};

    const vector<vector<double>> Ne = {{20.17970, 0.001818},
                {2.50000000E+00, 0.0, 0.0, 0.0, 0.0, -7.45375000E+02, 3.35532272E+00},
                {2.50000000E+00, 0.0, 0.0, 0.0, 0.0, -7.45375000E+02, 3.35532272E+00}};

    const vector<vector<double>> He = {{4.00260, 0.000524},
                {2.50000000E+00, 0.0, 0.0, 0.0, 0.0, -7.45375000E+02, 9.28724724E-01},
                {2.50000000E+00, 0.0, 0.0, 0.0, 0.0, -7.45375000E+02, 9.28724724E-01}};

    const vector<vector<double>> CH4 = {{16.04276, 0.00018},
                {1.63552643E+00, 1.00842795E-02, -3.36916254E-06, 5.34958667E-10, -3.15518833E-14, -1.00056455E+04, 9.99313326E+00},
                {5.14987613E+00, -1.36709788E-02, 4.91800599E-05, -4.84743026E-08, 1.66693956E-11, -1.02466476E+04, -4.64130376E+00}};

    const vector<vector<double>> Kr = {{83.80000, 0.000114},
                {2.50000000E+00, 0.0, 0.0, 0.0, 0.0, -7.45375000E+02, 5.49095651E+00},
                {2.50000000E+00, 0.0, 0.0, 0.0, 0.0, -7.45375000E+02, 5.49095651E+00}};

    const vector<vector<double>> H2 = {{2.01588, 0.000055},
                {2.93286579E+00, 8.26607967E-04, -1.46402335E-07, 1.54100359E-11, -6.88804432E-16, -8.13065597E+02, -1.02432887E+00},
                {2.34433112E+00, 7.98052075E-03, -1.94781510E-05, 2.01572094E-08, -7.37611761E-12, -9.17935173E+02, 6.83010238E-01}};
};


class AirProperties
{
    private:
        // Define a struct-object for air
        Air_Mixture air;

        // Define the Ideal-Gas Constant with the units, (J / mol * K)
        const double R = 8.31446261815324;

        // Define the Molar Mass of Air with the units, (g / mol)
        const double molar_mass = (this->air.N2.at(0).at(0) * this->air.N2.at(0).at(1)
                        + this->air.O2.at(0).at(0) * this->air.O2.at(0).at(1)
                        + this->air.Ar.at(0).at(0) * this->air.Ar.at(0).at(1)
                        + this->air.CO2.at(0).at(0) * this->air.CO2.at(0).at(1)
                        + this->air.He.at(0).at(0) * this->air.He.at(0).at(1)
                        + this->air.CH4.at(0).at(0) * this->air.CH4.at(0).at(1)
                        + this->air.Kr.at(0).at(0) * this->air.Kr.at(0).at(1)
                        + this->air.H2.at(0).at(0) * this->air.H2.at(0).at(1)) / 100;

        // Define the NASA Polynomials for enthalpy, internal energy, and entropy 
        const vector<double> polynomial_consts_low = {
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
        const vector<double> polynomial_consts_high = {
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
    
    public:

        // Default Constructor
        AirProperties();

        /** 
        *   @brief  Specific Heat as a function of Temperature: Cp(T). 
        *   This function uses the NASA Polymonials to approximate the specific heat as a function of temperature in Kelvins.  
        *   @param  temp -> Temperature with the units, Kelvin (K). 
        *   @return Cp -> The constant specific heat when pressure is constant with the units, (kJ / K * kg).
        */
        double get_cp(double temp) const;

        /** 
        *   @brief  Specific Heat as a function of Temperature: Cv(T). 
        *   This function uses the NASA Polymonials to approximate the specific heat as a function of temperature in Kelvins.  
        *   @param  temp -> Temperature with the units, Kelvin (K).
        *   @return Cv -> The constant specific heat when volume is constant with the units, (kJ / K * kg).
        */
        double get_cv(double temp) const;

        /** 
        *   @brief  Specific Heat Ratio as a function of Temperature: 𝛾(T). 
        *   This function uses the get_cp(double temp) and the get_cv(double temp) functions to find the specific heat ratio. 
        *   @param  temp -> Temperature with the units, Kelvin (K).
        *   @return 𝛾 -> The specific heat ratio when volume is constant. This property is unitless.
        */
        double get_gamma(double temp) const;

        /** 
        *   @brief  Enthalpy as a function of Temperature: h(T). 
        *   This function uses the NASA Polymonials to approximate the enthalpy as a function of temperature in Kelvins.
        *   @note This function DOES NOT RELY on get_cp(double temp). This functions integrates the polynomial found in get_cp(double temp) with respect to temperature to get enthalpy.
        *   @param  temp -> Temperature with the units, Kelvin (K).
        *   @return h -> The enthalpy with the units, (kJ / kg)
        */
        double get_enthalpy(double temp) const;

        /** 
        *   @brief  Internal Energy as a function of Temperature: u(T). 
        *   This function uses the NASA Polymonials to approximate the internal energy as a function of temperature in Kelvins.
        *   @note This function DOES NOT RELY on get_cv(double temp). This functions integrates the polynomial found in get_cv(double temp) with respect to temperature to get internal energy.
        *   @param  temp -> Temperature with the units, Kelvin (K).
        *   @return u -> The internal energy with the units, (kJ / kg)
        */
        double get_internal_energy(double temp) const;

        /** 
        *   @brief  Entropy as a function of Temperature: s(T). 
        *   This function uses the NASA Polymonials to approximate the internal energy as a function of temperature in Kelvins.
        *   This function DOES NOT RELY on get_cp(double temp) or get_cv(double temp). This functions integrates the polynomial found in get_cp(double temp) with respect to temperature to get entropy.
        *   @note This function DOES NOT TAKE INTO ACCOUNT OF OTHER PROPERTIES SUCH AS PRESSURE OR VOLUME
        *   @param  temp -> Temperature with the units, Kelvin (K).
        *   @return u -> The entropy with the units, (kJ / kg)
        */
        double get_entropy(double temp) const;

        /**
         * @brief   Returns the Ideal Gas Constant
         * @param   none -> Takes no input
         * @return  R -> THe Ideal Gas Constant (J / mol * K)
         */
        double get_R() const;

        /**
         * @brief   Returns the Low-Temperature Polynomials
         *          This function returns the NASA Polynomials for temperatures under 1000 K. 
         * @param   none -> Takes no input 
         * @return  Polynomial Constants -> Each Constant have a different unit.
         */
        vector<double> get_low_polynomials() const;

        /**
         * @brief   Returns the High-Temperature Polynomials
         *          This function returns the NASA Polynomials for temperatures over 1000 K. 
         * @note    These NASA Polynomials start behaving less accurate above 3000 K. 
         * @param   none -> Takes no input 
         * @return  Polynomial Constants -> Each Constant have a different unit.
         */
        vector<double> get_high_polynomials() const;

        /**
         * @brief   Returns the Temperature as a function of enthalpy
         *          Due to Enthalpy being represented as a polynomial with respect to temperature, h / cp = T is inaccurate. As such, This function loops to find the best approximate Temperature.
         * @param   target_h -> Enthalpy with the units, (kJ / kg).
         * @return  Temperature -> Temperature with the units, (K).
         */
        double get_temperature_from_enthalpy(double target_h) const;

        /**
         * @brief   Returns the Temperature as a function of internal energy
         *          Due to Internal Energy being represented as a polynomial with respect to temperature, u / cv = T is inaccurate. As such, This function loops to find the best approximate Temperature.
         * @param   target_u -> Internal Energy with the units, (kJ / kg).
         * @return  Temperature -> Temperature with the units, (K).
         */
        double get_temperature_from_internal_energy(double target_u) const;
};