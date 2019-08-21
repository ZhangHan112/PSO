#include "PSO.h"

int main(int argc,char**argv){
    int Iteration = atoi(argv[1]);
    int Group = atoi(argv[2]);
    int Number = atoi(argv[3]);
    int Dimension = atoi(argv[4]);
    int Run = atoi(argv[5]);

    PSO pso(Iteration,Group,Number,Dimension,Run);
    pso.Pso();
}