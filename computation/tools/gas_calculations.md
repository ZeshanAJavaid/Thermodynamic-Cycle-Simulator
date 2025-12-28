# Thermodynamic Property Calculations of Ideal Gasses

This following document will contain the ideal gas relationships and the NASA Polynomial Functions that define the specific heats, enthalpy, internal energy and entropy as a function temperature.

## 1. IDEAL GAS EQUATIONS

The following formulas describe the ideal gas relationships used in the implementation of these classes:

#### **Ideal Gas Equation:**

**1.** $\large pv = RT$
- $p$ is pressure ($kPa$)
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)

---

#### **Isothermal Proccesses**

**2.** $\large p_1v_1 = p_2v_2 $
    - $p$ is pressure ($kPa$)
    - $v$ is specific volume ($\frac{m^3}{kg}$)

**3.** $\Large \frac{p_1}{T_1} = \frac{p_2}{T_2}$
- $p$ is pressure ($kPa$)
- $T$ is temperature (K)

**4.** $\Large \frac{v_1}{T_1} = \frac{v_2}{T_2}$
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $T$ is temperature (K)

---

#### **Adiabatic/Isentropic Proccesses**

**5.** $\large p_1v_1^\gamma = p_2v_2^\gamma $
- $p$ is pressure ($kPa$)
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $\gamma$ is the specific heat ratio (unitless)

**6.** $\Large \frac{T_2}{T_1} = (\frac{p_2}{p_1})^{\frac{\gamma - 1}{\gamma}}$
- $p$ is pressure ($kPa$)
- $T$ is temperature ($K$)
- $\gamma$ is the specific heat ratio (unitless)

**7.** $\Large \frac{T_2}{T_1} = (\frac{v_1}{v_2})^{\gamma - 1}$
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $T$ is temperature ($K$)
- $\gamma$ is the specific heat ratio (unitless)

---

#### **Polytropic Proccesses**

**8.** $\large p_1v_1^n = p_2v_2^n $
- $p$ is pressure ($kPa$)
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $n$ is the polytropic index  (unitless)

**9.** $\Large \frac{T_2}{T_1} = (\frac{p_2}{p_1})^{\frac{n - 1}{n}}$
- $p$ is pressure ($kPa$)
- $T$ is temperature ($K$)
- $n$ is the polytropic index  (unitless)

**10.** $\Large \frac{T_2}{T_1} = (\frac{v_1}{v_2})^{n - 1}$
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $T$ is temperature ($K$)
- $n$ is the polytropic index  (unitless)


---

## 2. NASA POLYNOMIALS

The following formulas use the NASA POLYNOMIALS to find various thermodynamic properties.

---

#### **Isobaric Specific Heat Constant: $c_p(T)$**

**1.** $\large c_p(T) = \frac{R(a_1 + a_2T + a_3T^2 + a_4T^3 + a_5T^4)}{m}$
- $c_p(T)$ is the isobaric specific heat constant $(\frac{kJ}{kgK})$
- $a_1 \rightarrow a_5$ are the polynomial constants 
- $T$ is temperature ($K$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $m$ is molar mass of air ($\frac{kg}{kmol}$)

---

#### **Isochoric Specific Heat Constant: $c_v(T)$**

**2.** $\large c_v(T) = c_p(T) - R =\frac{R(a_1 + a_2T + a_3T^2 + a_4T^3 + a_5T^4) - R}{m}$
- $c_v(T)$ is the Isochoric specific heat constant $(\frac{kJ}{kgK})$
- $c_p(T)$ is the isobaric specific heat constant $(\frac{kJ}{kgK})$
- $a_1 \rightarrow a_5$ are the polynomial constants 
- $T$ is temperature ($K$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $m$ is molar mass of air ($\frac{kg}{kmol}$)

---

#### **Specific Enthalpy: $h(T)$**

**3.** $\large h(T) = \int_{298.15}^{T} c_p(T) \, dT =\frac{RT(a_1 + \frac{a_2}{2}T + \frac{a_3}{3}T^2 + \frac{a_4}{4}T^3 + \frac{a_5}{5}T^4 + \frac{a_6}{T})}{m}$
- $h$ is the specific enthalpy ($\frac{kJ}{kg}$)
- $a_1 \rightarrow a_5$ are the polynomial constants 
- $T$ is temperature ($K$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $m$ is molar mass of air ($\frac{kg}{kmol}$)

---

#### **Specific Internal Energy: $h(T)$**

**4.** $\large u(T) = \int_{298.15}^{T} c_v(T) \, dT =\frac{RT(a_1 + \frac{a_2}{2}T + \frac{a_3}{3}T^2 + \frac{a_4}{4}T^3 + \frac{a_5}{5}T^4 + \frac{a_6}{T} - 1)}{m}$
- $u$ is the specific internal energy ($\frac{kJ}{kg}$)
- $a_1 \rightarrow a_5$ are the polynomial constants 
- $T$ is temperature ($K$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $m$ is molar mass of air ($\frac{kg}{kmol}$)

---

#### **Specific Entropy: $s^o(T)$**

**5.** $\large s^o(T) = \int_{0}^{T} \frac{c_p(T)}{T} \, dT = \frac{R(a_1\ln{T} + a_2T + \frac{a_3}{2}T^2 + \frac{a_4}{3}T^3 + \frac{a_5}{4}T^4 + a_7)}{m}$
- $s^o$ is the epecific entropy ($\frac{kJ}{kg K}$)
- $a_1 \rightarrow a_5$ are the polynomial constants 
- $T$ is temperature ($K$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $m$ is molar mass of air ($\frac{kg}{kmol}$)

---