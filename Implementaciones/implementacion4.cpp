#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include "Funciones/AritmeticaDeConjuntos.h"
using namespace std;


vector<vector<string>> optimizacion1(vector<vector<string>> &F){
    vector<vector<string>> Resultado;
    vector<string> elementos;
    vector<string> S;
    bool NewElem=false;
    int pos;
    for(vector<vector<string>>::iterator i=F.begin();i!=F.end();++i){
        S=*i;
        for(vector<string>::iterator j=S.begin();j!=S.end();++j){
            pos=findIndex(elementos,*j);
            if(pos==-1){
                elementos.push_back(*j);
                NewElem=true;
            }
        }
        if (NewElem){
            Resultado.push_back(S);
        }
        NewElem=false;
    }
    return Resultado;
}

vector<vector<string>> maximizarGp(vector<vector<string>> &F, vector<string> &U,vector<vector<string>> &C, int k){
    int tamano = 0;
    int n=0;
    vector<string> aux;
    vector<vector<string>> Conjunto=C;
     if (Conjunto.size() != 0) 
        k=k-C.size(); 
    vector<vector<string>> CopiaF=F;
    while (k != 0){
        if (Conjunto.size() == 0){
            tamano = 0;
            for (vector<vector<string>>::iterator i = CopiaF.begin(); i != CopiaF.end(); ++i){
                n = interseca(U, *i);
                if (tamano < n){
                    tamano = n;
                    aux=*i;
                }
            }
            if(seEncuentra(aux,Conjunto)) break;
            Conjunto.push_back(aux);
        }
        else{
            vector<string> aux2;
            for (vector<vector<string>>::iterator i = CopiaF.begin(); i != CopiaF.end(); ++i){
                aux = unionConVec(Conjunto, *i);
                n = interseca(U, aux);
                if (tamano < n){
                    tamano = n;
                    aux2=*i;
                }
            }
             if(seEncuentra(aux2,Conjunto)) break;
            Conjunto.push_back(aux2);
        }
        k--;
    }
    return Conjunto;
}

vector<vector<string>> mscpGp(vector<string> &x, vector<vector<string>> &F){

    int limite=log2(min(x.size(),F.size()))+1;
    int k=rand()%limite+1;
    cout<<"K="<<k<<" "<<x.size()<<" "<<F.size()<<" "<<limite<<endl;

    vector<vector<string>> C;
    vector<vector<string>> copia= F;
    vector<string> U = x;
    vector<vector<string>> S= optimizacion1(copia);

    if (S.size()!=0){
        cout<<"entre"<<endl;
        U = restaVecConjunto(U, S);
        C=agregaVec(S,C);
    }
    printVectorstring(U);
    cout<<endl;
    printConjunto(S);
    cout<<endl;
    printConjunto(C);
    S.clear();
    cout<<"Sali de la optimizacion"<<endl;
    while (U.size() != 0){
        S = maximizarGp(copia,U,S,k);
        U = restaVecConjunto(U,S);
        C=agregaVec(S,C);
    }
    return C;
}

int main(){
    vector<string> A{"1", "2", "3", "4", "5", "6"};
    vector<string> B{"5", "6", "8", "9"};
    vector<string> C{"1", "4", "7", "10"};
    vector<string> D{"2", "5", "8", "11"};
    vector<string> E{"3", "6", "9","12"};
    vector<string> G{"10", "11", "12"};
    vector<string> X{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    vector<vector<string>> F{A, B, C, D, E, G};
    vector <vector<string>> resultado=mscpGp(X,F);
    cout<<resultado.size()<<endl;
    // cout << endl;
    return 0;
}