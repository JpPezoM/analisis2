#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <ctime> 
#include "greedy.h"
#include "busqueda.h"
using namespace std;

vector<vector<string>> generaConjunto(int n,int m){
    int num,x;
    vector<string> S;
    vector<vector<string>> C;
    for(int j=0;j<m;j++){
        x=rand()%n+1;//Tamaño del Conjunto S
        for(int i=0;i<x;i++){
            num=rand()%x+1;
            S.push_back(to_string(num));
        }
        sort(S.begin(), S.end());
        S.erase(unique(S.begin(), S.end()), S.end());
        C.push_back(S);
        S.clear();
    }
    return C;
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
vector<bool> TraduceVector(int n,int m,vector<vector<string>> &F,vector<string> &U){
    vector<bool> traducido(U.size()*m);
    vector <string> S;
    initV(traducido);
    int numS=0;
    for(vector<vector <string>>::iterator i=F.begin();i!=F.end();++i){
        S=*i;
        for(vector <string>::iterator j=U.begin();j!=U.end();++j){
            int pos=findIndex(U,*j);
            if (*find(S.begin(), S.end(), *j) == *j){
                pos=findIndex(U,*j);
                traducido[(pos+(U.size()*numS))]=true;
            }
          else traducido[(pos*numS)]=false;
        }
        numS++;
    }
    return traducido;
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

    vector<bool> binario=TraduceVector(n,m,F,X);

    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Creacion de la Matriz: " << time << endl;

    /* //Ejecucion de soluciones
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
    t0=clock();
    int limite=log2(min(n,m))+1;
    int k=rand()%limite;
    //resultado=mscpGp(X,F,k);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Ejecucion Algoritmo Greedy Optimizado:" << time << endl;
    cout<<resultado.size()<<endl; */
    cout<< "Universo:";
    printVectorstring(X);
    printConjunto(F);
    cout<<"bool:"<<binario.size()<<endl;
    printVectorsbool(binario,X.size());

    
    return 0;
}