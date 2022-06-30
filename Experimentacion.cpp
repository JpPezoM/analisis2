#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime> 
/* #include "implementacion1.cpp"
#include "implementacion2.cpp"
#include "implementacion4.cpp"*/
#include "greedy.h"
using namespace std;

vector<string> generaConjunto(int U){
    int num,n;
    vector<string> conjunto;
    n=rand()%U+1;
    for(int i=0;i<n;i++){
        num=rand()%1000000000;
        conjunto.push_back(to_string(num));
    }
    return conjunto;
}



int main(int argc, char **argv){
    if(argc != 3){
		cout << "Error. Debe ejecutarse como ./Experimentacion n m NumeroMasAlto" << endl;
		exit(EXIT_FAILURE);
	} 
	int TamañoU= atoi(argv[1]);
    int NumeroConjuntos= atoi(argv[2]);

    unsigned t0, t1;
 
    t0=clock();
    vector<vector<string>>F;
    for(int i=0;i<NumeroConjuntos;i++){
        F.push_back(generaConjunto(TamañoU));
    }
    vector<string>X;
    for(int i=0;i<NumeroConjuntos;i++){
        X=unionVectores(X,F[i]);
    }
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Creacion de la Matriz: " << time << endl;
    t0=clock();
    vector<vector<string>> resultado=mscpG(X,F);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Ejecucion Algoritmo Greedy:" << time << endl;
    cout << endl;
    cout<<resultado.size()<<endl;
    
    return 0;
}