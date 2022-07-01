#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
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
    while (k > 0){
        if (Conjunto.size() == 0){
            tamano = 0;
            for (vector<vector<string>>::iterator i = CopiaF.begin(); i != CopiaF.end(); ++i){
                n = interseca(U, *i);
                if (tamano < n){
                    tamano = n;
                    aux=*i;
                }
            }
            if(seEncuentra(aux,Conjunto)){
                k=0;
                break;
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
             if(seEncuentra(aux2,Conjunto)) break;
            Conjunto.push_back(aux2);
        }
        k--;
    }
    return Conjunto;
}


vector<vector<string>> mscpGp(vector<string> &x, vector<vector<string>> &F){
    vector<vector<string>> f= F;
    vector<string> U = x;

    vector<vector<string>> C;
    vector<vector<string>> S= optimizacion1(f);

    if (S.size()!=0){
        U = restaVecConjunto(U, S);
        C=agregaVec(S,C);
    }
    int limite=log2(min(x.size(),f.size()))+1;
    int k=rand()%limite+1;
    
    while (U.size() != 0){
        S = maximizarGp(f,U,S,k);
        U = restaVecConjunto(U,S);
        C=agregaVec(S,C);
    }
    return C;
}
