#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "AritmeticaDeConjuntos.h"
using namespace std;


vector<string> unionVecdeVec(vector<vector<string>> &v1, vector<string> &v2){
    vector<string> unions;
    for (vector<vector<string>>::iterator i = v1.begin(); i != v1.end(); ++i){
        unions=unionVe(unions,*i);
    }
    vector<string> aux = v2;
    bool repite;
    while (aux.size() != 0)
    {
        repite = false;
        for (vector<string>::iterator i = unions.begin(); i != unions.end(); ++i)
        {
            if (*i == aux[0])
            {
                repite = true;
                aux.erase(aux.begin());
                break;
            }
        }
        if (!repite)
        {
            unions.push_back(aux[0]);
            aux.erase(aux.begin());
        }
    }
    return unions;
}

vector<string> restaMayor(vector<string> &U, vector<vector<string>> &S){
    for (vector<vector<string>>::iterator i = S.begin(); i != S.end(); ++i){
        U=resta(U,*i);
    }
    return U;
}

vector<vector<string>> maximizar(vector<vector<string>> &F, vector<string> &U, int k){
    int tamano = 0;
    int n=0;
    vector<string> aux;
    vector<vector<string>> Conjunto;
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
                aux = unionVecdeVec(Conjunto, *i);
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

vector<vector<string>> mscp(vector<string> x, vector<vector<string>> F, int k){
    vector<string> U = x; 
    vector<vector<string>> C;
    vector<vector<string>> S;
    while (U.size() != 0){
        S = maximizar(F, U, k);
        cout << "U:" << endl;
        printVectorElements(U);
        U = restaMayor(U, S);
        cout << "U-S:" << endl;
        printVectorElements(U);
        for (vector<vector<string>>::iterator i = S.begin(); i != S.end(); ++i){
            C.push_back(*i);
        }
        
    }
    return C;
}

int main()
{
    vector<string> A{"1", "2", "3", "4", "5", "6"};
    vector<string> B{"5", "6", "8", "9"};
    vector<string> C{"1", "4", "7", "10"};
    vector<string> D{"2", "5", "8", "11"};
    vector<string> E{"3", "6", "9", "12"};
    vector<string> G{"10", "11", "12"};
    vector<string> X{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    vector<vector<string>> F{A, B, C, D, E, G};
    int k = 3;

    vector <vector<string>> resultado=mscp(X,F,k);
    cout<<resultado.size()<<endl;
    // cout << endl;
    return 0;
}