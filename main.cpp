#include "./computation/computation.h"

int main()
{
    Computation solver(Cycles(0),100.0,400.0,40,100.0,100.0);

    solver.compute();
}