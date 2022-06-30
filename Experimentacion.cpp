#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <ctime> 
#include "Implementaciones/Funciones/greedy.h"
#include "Implementaciones/Funciones/busqueda.h"
using namespace std;

vector<vector<string>> generaConjunto(int n,int m){
    int num,x;
    vector<string> S;
    vector<vector<string>> C;

    vector<bool> aux100(n); //vector para mantener rastro de que elementos se han añadido
    initV(aux100);

    for(int j=0;j<m;j++){
        x=rand()%n+1;//Tamaño del Conjunto S
        for(int i=0;i<x;i++){
            num=rand()%x+1;
            aux100[num-1] = true; //si aparece el elemento lo actualizo en el vector
            S.push_back(to_string(num));
        }
        sort(S.begin(), S.end());
        S.erase(unique(S.begin(), S.end()), S.end());
        C.push_back(S);
        S.clear();
    }

    //agrego los elementos que no aparecieron en el for anterior a un conjunto aleatorio, de esa manera
    //estan todos los elem del universo en algun conjunto
    int y = 0;
    for(int z = 0;  z < n; z++){
        if(not aux100[z]){
            y = rand() % n;
            C[y].push_back(to_string(z + 1));
        }
    }
    return C;
}

vector<bool> TraduceVector(int n,int m,vector<vector<string>> F){
    //Inicia la matriz con todos sus valores en 0
    vector<bool> matrixB(m*n);
    for(int j = 0; j < (m * n); j++) matrixB[j] = false;

    //Añade 1 en la pos que indica el elemento de matriz original
    int a = 0;
    for(int i = 0; i < F.size(); i++){
        for(string s: F[i]){
        a = atoi(s.c_str()) -1;
        matrixB[(i * n) + a] = true; 
        }
   }
    return matrixB;
}



int main(int argc, char **argv){
    if(argc != 3){
		cout << "Error. Debe ejecutarse como ./Experimentacion n m" << endl;
		exit(EXIT_FAILURE);
	} 
	int n= atoi(argv[1]);
    int m= atoi(argv[2]);

    unsigned t0, t1;
    //Creacion de las matrices con las que se trabajara
    t0=clock();
    vector<vector<string>>F=generaConjunto(n,m);
    //Universo
    vector<string>X;
    for(int i=0;i<m;i++){
        X=unionVectores(X,F[i]);
    }

    vector<bool> binario=TraduceVector(n,m,F);

    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Creacion de la Matriz: " << time << endl;

     //Ejecucion de soluciones
    //Exhaustivo
    t0=clock();
    vector<int> resul=exhaustiveSearch(m,n,binario);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Ejecucion Algoritmo Busqueda exhaustiva:" << time << endl;
    cout<<resul.size()<<endl;
    //Busqueda optimizada
    t0=clock();
    resul=mscBusquedaOp(n,m,binario);
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
    //Greedy Optimizado
    t0=clock();
    resultado=mscpGp(X,F);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Ejecucion Algoritmo Greedy Optimizado:" << time << endl;
    cout<<resultado.size()<<endl;

    cout<< "Universo:";
    printVectorstring(X);
    printConjunto(F);
    cout<<"bool:"<<binario.size()<<endl;
    printVectorsbool(binario,X.size());

    
    return 0;
}