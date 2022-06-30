#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "Funciones/AritmeticaDeConjuntos.h"
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
    vector <string> U=x;
    vector <vector <string>> C;
    vector <string> S;
    while (U.size()!=0){
        S=maximizarG(F,U,S);
        U=resta(U,S);
        C.push_back(S);
    }
    return C;
}

int main(){
    vector <string> A{"1","2","3","4","5","6"};
    vector <string> B{"5","6","8","9"};
    vector <string> C{"1","4","7","10"};
    vector <string> D{"2","5","8","11"};
    vector <string> E{"3","6","9","12"};
    vector <string> G{"10","11","12"};
    vector <string> X{"1","2","3","4","5","6","7","8","9","10","11","12"};
    vector <vector <string>> F{A,B,C,D,E,G};

    vector <vector<string>> resultado=mscpG(X,F);
    
    cout << endl;
    cout<<resultado.size()<<endl;
    return 0;
}