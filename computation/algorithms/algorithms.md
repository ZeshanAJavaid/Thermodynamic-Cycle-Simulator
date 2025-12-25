# ALGORITHMS

This document contains the formulas required to compute the thermodynamic properties during each proccess. 

## 2. COMPRESSION EQUATIONS

The following equations were used to find the thermodynamic properties during compression.

### 1. Brayton Cycle Compressor

#### Pressure 

**1.** $\large p_2 = p_1 r_p$
- $p$ is pressure ($kPa$)
- $r_p$ is pressure ratio (unitless)

#### Temperature 

**2.1** $\large T_2 = T_1 r_p^{\frac{\gamma - 1}{\gamma}}$
*(Ideal Temperature)*
- $T$ is temperature ($K$)
- $r_p$ is pressure ratio (unitless)
- $\gamma$ is specific heat ratio (unitless)

**2.2** $\large T_2 \approx 298.15 + \frac{h(T_{approx})}{c_p(T_{approx})}$
*(Actual Temperature derived from Enthalpy)*
- $T$ is temperature ($K$)
- $h$ is specific enthalpy ($\frac{kJ}{kg}$)
- $c_p$ is isobaric specific heat capacity ($\frac{kJ}{kgK}$)

#### Specific Volume

**3.** $\large v_2 = \frac{RT_2}{p_2}$
- $p$ is pressure ($kPa$)
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)

#### Enthalpy

**4.1** Refer to **equation 2.3** in (Project Root Directory)/computation/tools/gas_calculations.md

**4.2** $\large h_2 = W_{compressor} + h_1$
- $W_{compressor}$ is the work of the compressor ($\frac{kJ}{kg}$)
- $h$ is specific enthalpy ($\frac{kJ}{kg}$)

#### Internal Energy

**5.1** Refer to **equation 2.4** in (Project Root Directory)/computation/tools/gas_calculations.md

#### Entropy

**6.** $\large s(T_2) = s(T_1) + \Delta s = s(T_1) + s^o(T_2) - s^o(T_1) - Rln(\frac{p_2}{p_1})$
- $s$ is entropy ($\frac{kJ}{kgK}$)
- $\Delta s$ is change of entropy ($\frac{kJ}{kgK}$)
- $p$ is pressure ($kPa$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)

#### Work of Compressor

**7.** $\large W_{compressor} = \frac{h_{2s} - h_1}{\eta} * 100$
- $W$ is work of compressor ($\frac{kJ}{kg}$)
- $h$ is specific enthalpy ($\frac{kJ}{kg}$)
- $\eta$ is isentropic efficiency (%)

### 2. Diesel/Otto Cycle Compression Stroke

#### Pressure 

**1.1** $\large p_2 = p_1(r_c)^\gamma$
- $p$ is pressure ($kPa$)
- $r_c$ is compression ratio (unitless)
- $\gamma$ is the specific heat ratio (unitless)

**1.2** $\large p_2 = \frac{RT_2}{v_2}$
- $p$ is pressure ($kPa$)
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)


#### Temperature 

**2.1** $\large T_2 = \frac{p_2v_2}{R}$
- $p$ is pressure ($kPa$)
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)

**2.2** $\large T_2 = T_1 r_c^{\frac{\gamma - 1}{\gamma}}$
*(Ideal Temperature)*
- $T$ is temperature ($K$)
- $r_c$ is compression ratio (unitless)
- $\gamma$ is specific heat ratio (unitless)

**2.3** $\large T_2 \approx 298.15 + \frac{u(T_{approx})}{c_v(T_{approx})}$
*(Actual Temperature Derived from Internal Energy)*
- $T$ is temperature ($K$)
- $u$ is specific internal energy ($\frac{kJ}{kg}$)
- $c_v$ is isochoric specific heat capacity ($\frac{kJ}{kgK}$)



#### Specific Volume

**3.** $\large v_2 = \frac{v_1}{r_c}$
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $r_c$ is compression ratio (unitless)

#### Enthalpy

**4.** Refer to **equation 2.3** in (Project Root Directory)/computation/tools/gas_calculations.md

#### Internal Energy

**5.1** Refer to **equation 2.4** in (Project Root Directory)/computation/tools/gas_calculations.md

**5.2** $\large u_2 = W_{compression} + u_1$
- $W_{compression}$ is the work of the compression stroke ($\frac{kJ}{kg}$)
- $u$ is internal energy ($\frac{kJ}{kg}$)

#### Entropy

**6.** $\large s(T_2) = s(T_1) + \Delta s = s(T_1) + s^o(T_2) - s^o(T_1) + Rln(\frac{1}{r_c})$
- $s$ is entropy ($\frac{kJ}{kgK}$)
- $\Delta s$ is change of entropy ($\frac{kJ}{kgK}$)
- $r_c$ is compression ratio (unitless)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)

#### Work of Compression Stroke

**7.** $\large W_{compression} = \frac{u_2 - u_1}{\eta} * 100$
- $W$ is work of compression stroke ($\frac{kJ}{kg}$)
- $u$ is internal energy ($\frac{kJ}{kg}$)
- $\eta$ is isentropic efficiency (%)


## 3. HEAT ADDITION EQUATIONS

The following equations were used to find the thermodynamic properties during heat addition.

### 1. Brayton Cycle Combustion Chamber / Diesel Cycle Combustion Stroke

#### Pressure 

**1.** $\large p_3 = p_2$
- $p$ is pressure ($kPa$)

#### Temperature 

**2** $\large T_2 \approx 298.15 + \frac{h(T_{approx})}{c_p(T_{approx})} $
*(Temperature derived from Enthalpy)*
- $T$ is temperature ($K$)
- $h$ is specific enthalpy ($\frac{kJ}{kg}$)
- $c_p$ is isobaric specific heat capacity ($\frac{kJ}{kgK}$)

#### Specific Volume

**3.** $\large v_3 = \frac{RT_3}{p_3}$
- $p$ is pressure ($kPa$)
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)

#### Enthalpy

**4.** $\large h_3 = Q_{in} - h_2$
- $Q$ is the heat added ($\frac{kJ}{kg}$)
- $h$ is specific enthalpy ($\frac{kJ}{kg}$)

#### Internal Energy

**5.** Refer to **equation 2.4** in (Project Root Directory)/computation/tools/gas_calculations.md

#### Entropy

**6.** $\large s(T_2) = s(T_1) + \Delta s = s(T_1) + s^o(T_2) - s^o(T_1)$
- $s$ is entropy ($\frac{kJ}{kgK}$)
- $\Delta s$ is change of entropy ($\frac{kJ}{kgK}$)
- $T$ is temperature ($K$)

#### Heat In

**7.** $\large Q_{in} = h_3 - h_2$
- $Q$ is the heat added ($\frac{kJ}{kg}$)
- $h$ is specific enthalpy ($\frac{kJ}{kg}$)

#### Work Done

**8.** $\large W_{done} = \int_{v_2}^{v_3} p \, dv =p(v_3 - v_2)$
- $W_{done}$ is work done ($\frac{kJ}{kg}$)
- $p$ is heat in ($kPa$)
- $v$ is specific internal energy ($\frac{m^3}{kg}$)


### 2. Otto Cycle Combustion Stroke

#### Pressure 

**1.** $\large p_3 = \frac{RT_3}{v_3}$
- $p$ is pressure ($kPa$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)
- $v$ is specific volume ($\frac{m^3}{kg}$)

#### Temperature 

**2.** $\large T_3 \approx 298.15 + \frac{u(T_{approx})}{c_v(T_{approx})}$
*(Derived from Internal Energy)*
- $T$ is temperature ($K$)
- $u$ is specific internal energy ($\frac{kJ}{kg}$)
- $c_v$ is isochoric specific heat capacity ($\frac{kJ}{kgK}$)

#### Specific Volume

**3.** $\large v_3 = v_2$
- $v$ is specific volume ($\frac{m^3}{kg}$)
*(Constant volume process)*

#### Enthalpy

**4.** Refer to **equation 2.3** in (Project Root Directory)/computation/tools/gas_calculations.md

#### Internal Energy

**5.** $\large u_3 = u_2 + Q_{in}$
- $u$ is specific internal energy ($\frac{kJ}{kg}$)
- $Q_{in}$ is heat added ($\frac{kJ}{kg}$)

#### Entropy

**6.** $\large s(T_2) = s(T_1) + \Delta s = s(T_1) + s^o(T_2) - s^o(T_1)$
- $s$ is entropy ($\frac{kJ}{kgK}$)
- $\Delta s$ is change of entropy ($\frac{kJ}{kgK}$)
- $T$ is temperature ($K$)

#### Heat In

**7.** $\large Q_{in} = u_3 - u_2$
- $Q$ is heat in ($\frac{kJ}{kg}$)
- $u$ is specific internal energy ($\frac{kJ}{kg}$)

#### Work Done

**8.** $\large W_{done} = \int_{v_2}^{v_3} p \, dv =p(v_3 - v_2)$
- $W_{done}$ is work done ($\frac{kJ}{kg}$)
- $p$ is heat in ($kPa$)
- $v$ is specific internal energy ($\frac{m^3}{kg}$)


## 4. EXPANSION EQUATIONS

The following equations were used to find the thermodynamic properties during expansion.

### 1. Brayton Cycle Turbine

#### Pressure 

**1.** $\large p_4 = p_1$
- $p$ is pressure ($kPa$)

#### Temperature 

**2.1** $\large T_{4} = T_3 (\frac{p_4}{p_3})^{\frac{\gamma - 1}{\gamma}}$
*(Ideal Temperature)*
- $T$ is temperature ($K$)
- $r_c$ is compression ratio (unitless)
- $\gamma$ is the specific heat ratio (unitless)

**2.2** $\large T_4 \approx 298.15 + \frac{h(T_4)}{c_p(T_4)}$
*(Actual Temperature derived from Enthalpy)*
- $T$ is temperature ($K$)
- $u$ is specific internal energy ($\frac{kJ}{kg}$)
- $c_v$ is isochoric specific heat capacity ($\frac{kJ}{kgK}$)

#### Specific Volume

**3.** $\large v_4 = \frac{RT_4}{p_4}$
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)
- $p$ is pressure ($kPa$)

#### Enthalpy

**4.1**Refer to **equation 2.3** in (Project Root Directory)/computation/tools/gas_calculations.md


**4.2** $\large h_4 = h_3 - W_{turbine}$
- $h$ is specific enthalpy ($\frac{kJ}{kg}$)
- $W$ is work ($\frac{kJ}{kg}$)

#### Internal Energy

**5.** Refer to **equation 2.4** in (Project Root Directory)/computation/tools/gas_calculations.md

#### Entropy

**6.** $\large s_4 = s_3 + s^o(T_4) - s^o(T_3) - Rln(r_p)$
- $s$ is entropy ($\frac{kJ}{kgK}$)
- $R$ is ideal gas constant ($\frac{kJ}{kgK}$)
- $r_p$ is pressure ratio (unitless)

#### Work of Turbine

**7.** $\large W_{turbine} = \frac{h_3 - h_{4s}}{\eta} * 100$
- $W$ is work of turbine ($\frac{kJ}{kg}$)
- $h$ is specific enthalpy ($\frac{kJ}{kg}$)
- $\eta$ is isentropic efficiency (%)

### 2. Diesel/Otto Cycle Power Stroke

#### Pressure 

**1.1** $\large p_4 = \frac{RT_4}{v_4}$
- $p$ is pressure ($kPa$)
- $v$ is specific volume ($\frac{m^3}{kg}$)
- $R$ is ideal gas constant ($\frac{kJ}{kg K}$)
- $T$ is temperature ($K$)

**1.2** $\large p_2 = p_1(r_c)^\gamma$
- $p$ is pressure ($kPa$)
- $r_c$ is compression ratio (unitless)
- $\gamma$ is the specific heat ratio (unitless)

#### Temperature 

**2.1** $\large T_{4s} = T_3 (r_c)^{\gamma - 1}$
*(Ideal Temperature)*
- $T$ is temperature ($T$)
- $r_c$ is compression ratio (unitless)
- $\gamma$ is the specific heat ratio (unitless)

**2.2** $\large T_4 \approx 298.15 + \frac{u(T_4)}{c_v(T_4)}$
*(Actual Temperature derived from Internal Energy)*
- $T$ is temperature ($T$)
- $u$ is internal energy ($\frac{kJ}{kg}$)
- $c_v$ is the isochoric specific heat constant ($\frac{kJ}{kgK}$)

#### Specific Volume

**3.** $\large v_4 = v_1$
*(Expands to initial cylinder volume)*
- $v$ is specific volume ($\frac{m^3}{kg}$)

#### Enthalpy

**4.** Refer to **equation 2.3** in (Project Root Directory)/computation/tools/gas_calculations.md

#### Internal Energy

**5.1** Refer to **equation 2.4** in (Project Root Directory)/computation/tools/gas_calculations.md

**5.2** $\large u_4 = u_3 - W_{power}$
- $u$ is specific internal energy ($\frac{kJ}{kg}$)
- $W$ is work ($\frac{kJ}{kg}$)

#### Entropy

**6.** $\large s_4 = s_3 + s^o(T_4) - s^o(T_3) + Rln(\frac{1}{r_c})$
- $s$ is entropy ($\frac{kJ}{kgK}$)
- $R$ is ideal gas Constant ($\frac{kJ}{kgK}$)
- $r_c$ is compression ratio (unitless)

#### Work of Power Stroke

**7.** $\large W_{power} = (u_3 - u_{4s})*\eta / 100$
- $W$ is work of power stroke ($\frac{kJ}{kg}$)
- $u$ is specific internal energy ($\frac{kJ}{kg}$)
- $\eta$ is isentropic efficiency (%)


## 5. HEAT REJECTION EQUATIONS

The following equations were used to find the thermodynamic properties during heat rejection.

### 1. Brayton/Diesel/Otto Cycle Exhaust

#### Pressure 

**1.** $\large p_5 = p_1$
*(System returns to initial state)*

#### Temperature 

**2.** $\large T_5 = T_1$
*(System returns to initial state)*

#### Specific Volume

**3.** $\large v_5 = v_1$
*(System returns to initial state)*

#### Enthalpy

**4.** $\large h_5 = h_1$
*(System returns to initial state)*

#### Internal Energy

**5.** $\large u_5 = u_1$
*(System returns to initial state)*

#### Entropy

**6.** $\large s_5 = s_1$
*(System returns to initial state)*

#### Heat Out

**7.1** $\large Q_{out} = h_4 - h_1$
*(For Brayton Cycle - Isobaric)*

- $h$ is enthalpy ($\frac{kJ}{kg}$)

**7.2** $\large Q_{out} = u_4 - u_1$
*(For Otto/Diesel Cycle - Isochoric)*

- $u$ is internal energy ($\frac{kJ}{kg}$)

## 6. OVERALL PERFORMANCE

The following formulas describe the overall efficiency and work of the cycle.


#### Work of Cycle

**1.** $\large W_{cycle} = W_{expansion} + W_{combustion} - W_{compression}$
- $W$ is work ($\frac{kJ}{kg}$)


#### Thermal Efficiency

**2.** $\large \eta_{thermal} = \frac{(\frac{W_{cycle}}{Q_{in}}) + (1 - \frac{Q_{out}}{Q_{in}})}{2}$
- $\eta_{thermal}$ is thermodynamic efficiency (%)
- $W_{expansion}$ is work generated by turbine/power stroke ($\frac{kJ}{kg}$)
- $W_{combustion}$ is work generated during heat addition (Diesel Only) ($\frac{kJ}{kg}$)
- $W_{compression}$ is work consumed by compressor ($\frac{kJ}{kg}$)
- $Q_{in}$ is total heat added ($\frac{kJ}{kg}$)
- $Q_{out}$ is total heat rejected ($\frac{kJ}{kg}$)