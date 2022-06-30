#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "AritmeticaDeConjuntos.h"
using namespace std;


vector <string> maximizarG(vector <vector <string>> &F,vector <string> &U,vector <string> &S){
    int tamano=0;
    vector <string> aux;
    for (vector<vector <string>>::iterator i=F.begin();i!=F.end();++i){
        int n=interseca(U,*i);
        if(tamano<n){
            tamano=n;
            aux=*i;
        }
    }
    return aux;
}

vector <vector <string>> mscpG(vector <string> x,vector <vector <string>> F){
    vector <string> U=x;//{1,1,1,1,1,1,1,1}->{0,0,0,0,0,0,0,0,0,0}
    vector <vector <string>> C;
    vector <string> S;
    while (U.size()!=0){
        S=maximizarG(F,U,S);
        U=resta(U,S);
        C.push_back(S);
    }
    return C;
}

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
        S = maximizarGp(copia, U, S,k);
        U = restaVecConjunto(U, S);
        C=agregaVec(S,C);
    }
    S.clear();
    while (U.size() != 0){
        S = maximizarGp(copia, U,S,k);
        U = restaVecConjunto(U, S);
        C=agregaVec(S,C);
    }
    return C;
}
