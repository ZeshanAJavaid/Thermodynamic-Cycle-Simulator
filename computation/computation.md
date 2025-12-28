# Computations

The following document describes the layout of the Computation directory. 

## Directories

### Algorithms

This directory contains all the algorithms used to compute the thermodynamic stages.

#### Files

---

##### **source files**

The cpp files in this directory is as follows:
1. **compression.cpp:** this file contains all the compression process logic.
2. **expansion.cpp:** this file contains all the expansion process logic.
3. **heat_addition.cpp:** this file contains all the heat addition process logic.
4. **heat_rejection.cpp:** this file contains all the heat_rejection process logic.
5. **thermo_state.cpp:** this file contains the class that stores all the thermodynamic states.

---

##### **header files**

The header files in this directory is as follows:
1. **compression.h:** this file contains all the blueprint for the compression.cpp file.
2. **expansion.h:** this file contains all the blueprint for the expansion.cpp file.
3. **heat_addition.h:** this file contains all the blueprint for the heat_addition.cpp file.
4. **heat_rejection.h:** this file contains all the blueprint for the heat_rejection.cpp file.
5. **thermo_state.h:** this file contains all the blueprint for the thermo_state.cpp file.

---

##### **readme file**

The readme file in this directory defines all the equations used in the implementation of this thermodynamic simulator.

### Cycles

This directory contains the three different cycles this simulator supports; Brayton, Otto, and Diesel.

### Files

---

##### **source file**

The cpp files in this directory is as follows:
1. **brayton.cpp:** this file contains all the brayton cycle logic.
2. **diesel.cpp:** this file contains all the diesel cycle logic.
3. **otto.cpp:** this file contains all the otto cycle logic.
---
##### **header files**

The header files in this directory is as follows:
1. **brayton.h:** this file contains all the blueprint for the brayton.cpp file.
2. **diesel.h:** this file contains all the blueprint for the diesel.cpp file.
3. **otto.h:** this file contains all the blueprint for the otto.cpp file.

### Tools

This directory contains all the ideal gas implementations. 

### Files

---

#### **source files**

This directory contains the gas.cpp file. This file defines all the functions required to compute various thermodynamic properties with the ideal gas assumptions.

---

#### **header files**

This directory contains the gas.h file. This file lays out all the functions required to compute various thermodynamic properties with the ideal gas assumptions.

---

#### **readme file**

The readme in this directory defines all the equations used in order to compute selected thermodynamic properties.