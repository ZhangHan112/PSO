#ifndef __PSO_H__
#define __PSO_H__

#include<iostream>
#include<cstdio>
#include<ctime>
#include<vector>
#include<cmath>
#include<fstream>
#include<limits>
#include<sstream>
using namespace std;

typedef vector<double> solution;
typedef vector<solution> set;

class PSO{
    int iter;
    int group;
    int num;
    int run;

    int dim;
    set dataset;
    set position;
    set volecity;
    set Pb;
    solution Gb;

    void Iris_Initialize();
    double SSE(solution sol);
    void Ackley_Initialize(double bound);
    double Ackley_Function(solution x);
    void ReadFile();

public:
    PSO(int Iteration,int Group,int Number,int Dimension,int Run);
    void Pso();
};

#endif