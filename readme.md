# Thermodynamic Simulator 

This project was created because I failed my aerthormodynamics final badly. After failing my first ever exam in college, I wanted to learn the topics I wasn't able to master at that time. As such, I started this project to ensure that I understand the topics while gaining more experience in software development.

## Thermodynamic Choices

As you may have noticed, this project only takes into account of 3 cycles: Brayton, Otto, and Diesel. The reason for this is due to the fact that these cycles do not have any phase changes. This allows for the usage of ideal standard assumptions and the associated methods of solving for various different thermodynamic proccesses. 

## Future Goals

This project will be finished once the Ts and Pv Diagrams have been implemented. I plan to make a turbojet, turbofan, turboprop and ramjet simulator later during my college career; I will probably create this simulator after taking AERO 351 during my junior year at Texas A&M University. As such, this project will have two versions: 1.0 and 1.1. 

## Compilation

The following proccess is used to compile this project: 

1. Open WSL through terminal
2. Run the following commands
```
chmod +x ./compilation.sh
./compilation.sh
./build/sim
```
