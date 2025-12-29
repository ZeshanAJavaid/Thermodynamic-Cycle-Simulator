# Thermodynamic Cycle Simulator 🚀

> **"When getting an 'A' isn't enough: Bridging the gap between grades and understanding."**

## 📖 Background
After finishing my final exam for **AERO 212: Introduction to Aerothermodynamics** at Texas A&M University, I had a realization. Even though I secured an 'A' in the course, I felt a disconnect between the grade on my screen and my actual grasp of thermodynamics during the exam.

I didn't want to just pass; I wanted to master the material. As a result, I decided to turn that academic uncertainty into an engineering challenge by coding the physics from the ground up. This simulator is the result of merging my Aerospace curriculum with the software development skills I gained in **CSCE 120: Intro to Program Design and Concepts.**

---

## 🛠️ Project Features

### The Physics Engine 🔥
The simulator handles the complex relationships between state variables $(P, v, T, u, h, s)$ using:
* **Ideal Gas Law & Isentropic Relations:** Dynamically solves for missing variables across different states.
* **Performance Metrics:** Automatically calculates Thermal Efficiency ($\eta$), Net Work ($W_{net}$), and Heat Transfers ($Q_{in}$ and $Q_{out}$).
* **Cold Air Standard Assumptions:** By focusing on cycles without phase changes, the engine utilizes constant specific heats for high-speed computation and logic verification.

### Supported Cycles 🔁
The simulator currently models three fundamental power cycles:
1. **Brayton Cycle:** The foundation of Jet Propulsion ✈️
2. **Otto Cycle:** Internal combustion for Gasoline engines 🚗
3. **Diesel Cycle:** High-compression cycles for heavy-duty transport 🚛



### Software Architecture 📦
* **Object-Oriented Design:** Developed with a modular architecture where thermodynamic processes are treated as objects, allowing for easy expansion.
* **Graphical User Interface (GUI):** Leveraged the **Qt Framework** to move beyond simple scripts, creating a full GUI that enhances the user experience.
* **Environment:** Developed and tested within **WSL (Windows Subsystem for Linux)**.

---

## 🚀 Future Roadmap (The Path to AERO 351)
This project is an evolving tool. As I progress through my Aerospace Engineering degree at **Texas A&M**, I plan to release:

* **Version 1.1 - 1.2:** Implementation of dynamic **T-s (Temperature-Entropy)** and **P-v (Pressure-Specific Volume)** diagrams.
* **Version 2.0:** After taking **AERO 351** during my junior year, I will write a new thermodynamic simulator that expands this simulator to compute th thermodynamic processes of:
    * Turbojets & Turbofans
    * Turboprops
    * Ramjets
---

## 💻 Compilation & Installation

To run the simulator locally using WSL:

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/ZeshanAJavaid/Thermodynamic-Cycle-Simulator](https://github.com/ZeshanAJavaid/Thermodynamic-Cycle-Simulator)
   cd Thermodynamic-Cycle-Simulator

2. **Run the compilation script:**
    ```bash
    chmod +x ./compilation.sh
    ./compilation.sh

3. **Run the Project**
    ```bash
    ./build/sim


Gig'em 👍