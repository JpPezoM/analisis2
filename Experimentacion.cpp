#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <ctime> 
#include "greedy.h"
#include "busqueda.h"
using namespace std;

vector<string> generaConjunto(int U){
    int num,n;
    vector<string> conjunto;
    n=rand()%U+1;
    for(int i=0;i<n;i++){
        num=rand()%n;
        conjunto.push_back(to_string(num));
    }
    sort(conjunto.begin(), conjunto.end());
    conjunto.erase(unique(conjunto.begin(), conjunto.end()), conjunto.end());
    return conjunto;
}
vector<bool> generaConjuntoBinario(int n,int m){
    int num;
    vector<bool> conjunto(n*m);
    for(int i=0;i<n*m;i++){
        num=rand()%2;
        conjunto.push_back(num);
    }
    return conjunto;
}



int main(int argc, char **argv){
    if(argc != 3){
		cout << "Error. Debe ejecutarse como ./Experimentacion n m" << endl;
		exit(EXIT_FAILURE);
	} 
	int TamanoU= atoi(argv[1]);
    int NumeroConjuntos= atoi(argv[2]);

    unsigned t0, t1;
    //Creacion de las matrices con las que se trabajara
    t0=clock();
    vector<vector<string>>F;
    for(int i=0;i<NumeroConjuntos;i++){
        F.push_back(generaConjunto(TamanoU));
    }
    vector<string>X;
    for(int i=0;i<NumeroConjuntos;i++){
        X=unionVectores(X,F[i]);
    }
    vector<bool> binario=generaConjuntoBinario(TamanoU,NumeroConjuntos);

    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Creacion de la Matriz: " << time << endl;

    //Ejecucion de soluciones
    //Exhaustivo
    t0=clock();
    vector<int> resul=exhaustiveSearch(NumeroConjuntos,TamanoU,binario);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Ejecucion Algoritmo Busqueda exhaustiva:" << time << endl;
    cout<<resul.size()<<endl;
    //Busqueda optimizada
    t0=clock();
    resul=mscBusquedaOp(TamanoU,NumeroConjuntos,binario);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Ejecucion Algoritmo Busqueda optimizada:" << time << endl;
    cout<<resul.size()<<endl;

    //Greedy
    t0=clock();
    vector<vector<string>> resultado=mscpG(X,F);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Ejecucion Algoritmo Greedy:" << time << endl;
    cout<<resultado.size()<<endl;
    t0=clock();
    int limite=log2(min(TamanoU,NumeroConjuntos))+1;
    int k=rand()%limite;
    //resultado=mscpGp(X,F,k);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Ejecucion Algoritmo Greedy Optimizado:" << time << endl;
    cout<<resultado.size()<<endl;
    printVectorstring(X);
    
    return 0;
}