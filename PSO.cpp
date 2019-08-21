#include "PSO.h"

PSO::PSO(int Iteration,int Group,int Number,int Dimension,int Run):
    iter(Iteration),group(Group),num(Number),dim(Dimension),run(Run){

    srand(time(NULL));
}

void PSO::Pso(){
    
    Ackley_Initialize(40);
}

void PSO::Iris_Initialize(){

    position = set(10);
    for(int i=0;i<num;i++){
        solution s = solution(dataset.size());
        for(int j=0;j<dataset.size();j++){
            int random = rand()%group;
            s[j] = random;
        }
        position[i] = s;
    }
}

double PSO::SSE(solution sol){
    double sum = 0;

    for(int g=0;g<group;g++){
        solution Centroid = solution(dim);
        int vertices = 0;
        for(int i=0;i<dataset.size();i++){
            if(sol[i] == g){
                vertices++;
                for(int j=0;j<dim;j++)
                    Centroid[j] += dataset[i][j];
            }
        }
    
        for(int i=0;i<dim;i++) //頂點座標總合除以頂點數
            Centroid[i] /= vertices;

        // for(int i=0;i<dim;i++)
        //     cout << Centroid[i] << " ";
        // cout << endl;

        
        for(int i=0;i<dataset.size();i++){
            if(sol[i]==g){ 
                double temp=0;
                for(int j=0;j<dim;j++)
                    temp += pow( dataset[i][j]-Centroid[j],2 ); //計算同一群的每一點,和質心的距離
                sum += temp; 
            }
        }
    
    }

    return sum;
}

void PSO::Ackley_Initialize(double bound){
    position = set(num,solution(dim));
    volecity = set(num,solution(dim));
    Pb = set(num,solution(dim));
    Gb = solution(dim);

    for(int n=0;n<num;n++)
        for(int d=0;d<dim;d++){
            int random =  rand()%2; 
            double temp = bound*(rand()%RAND_MAX)/RAND_MAX;
            if(random==0)
                temp *= -1;
            position[n][d] = temp;
            Pb[n][d] = position[n][d];
        }

    for(int n=0;n<num;n++)
        for(int d=0;d<dim;d++){
            int random =  rand()%2;
            double temp = bound*(rand()%RAND_MAX)/RAND_MAX;
            if(random==0)
                temp *= -1;
            volecity[n][d] = temp;
        }


    double minPos;
    double min = numeric_limits<double>::infinity();
    for(int n=0;n<num;n++){ 
        double temp = Ackley_Function(position[n]);
        if(min>temp){
            minPos = n;
            min = temp;
        }
    }

    Gb = position[minPos];

}

double PSO::Ackley_Function(solution x){
    
    double temp1=0,temp2=0;
    for(int d=0;d<dim;d++)
        temp1 = pow(x[d],2);
    temp1 /= (double)dim;
    temp1 = (double)sqrt(temp1);
    temp1 *= (double)-0.2;

    for(int d=0;d<dim;d++)
        temp2 += (double)cos(2*M_PI*x[d]);
    temp2 /= dim;

    return (double)-20*exp(temp1)-exp(temp2)+20+exp(1);
}

void PSO::ReadFile(){
    string inputStr, token;
    ifstream file("iris.data");
    if (file.is_open()){
        while (file >> inputStr) { 
            vector<double> data;
            istringstream splitStr(inputStr);
            for (int i = 0; getline(splitStr, token, ','); ++i) {
                if(i == 4) continue;
                data.push_back( stod(token) );
            }
            dataset.push_back(data);
        }
    }
    file.close();

}

