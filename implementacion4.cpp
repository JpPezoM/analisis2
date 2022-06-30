#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "AritmeticaDeConjuntos.h"
using namespace std;




vector<vector<string>> optimizacion1(vector<vector<string>> &F){
    vector<vector<string>> Resultado;
    int Semejantes=0;
    for(vector<vector<string>>::iterator i=F.begin();i!=F.end();++i){
        for(vector<vector<string>>::iterator j=F.begin();j!=F.end();++j){
            if(elementosEnComun(*i,*j)>1){
                Semejantes++;
            }
        }
        if(Semejantes==1) Resultado.push_back(*i);
        
        Semejantes=0;
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

vector<vector<string>> mscpGp(vector<string> &x, vector<vector<string>> &F, int k){
    vector<vector<string>> C;
    vector<vector<string>> copia= F;
    vector<string> U = x;
    vector<vector<string>> S= optimizacion1(copia);
    if (S.size()!=0){
        S = maximizar(copia, U, S,k);
        U = restaVecConjunto(U, S);
        C=agregaVec(S,C);
    }
    S.clear();
    while (U.size() != 0){
        printVector(U);
        S = maximizargP(copia, U,S,k);
        U = restaVecConjunto(U, S);
        printConjunto(S);
        C=agregaVec(S,C);
    }
    return C;
}

/*int main(){
    vector<string> A{"1", "2", "3", "4", "5", "6"};
    vector<string> B{"5", "6", "8", "9"};
    vector<string> C{"1", "4", "7", "10"};
    vector<string> D{"2", "5", "8", "11"};
    vector<string> E{"3", "6", "9"};
    vector<string> G{"10", "11", "12"};
    vector<string> X{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    vector<vector<string>> F{A, B, C, D, E, G};
    int k = 2;
    vector <vector<string>> resultado=mscp(X,F,k);
    cout<<resultado.size()<<endl;
    // cout << endl;
    return 0;
}*/