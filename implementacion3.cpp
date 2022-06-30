#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "AritmeticaDeConjuntos.h"
using namespace std;



/* vector<bool> Fila(vector<int> &U,vector<int> &S){
    vector<bool> elementos;
    for(int i=0;i<U.size();i++){
        elementos.push_back(false);
        for(int j=0;j<S.size();j++){
            if(U[i]==S[j]){
                elementos[i]=true;
                break;
            }
        }
    }
    return elementos;
}

vector<vector<bool>> creaMatriz(vector<vector<int>> &F,vector<int> &U){
    vector<vector<bool>> matriz;
    for (int i = 0; i < F.size(); i++){
        matriz.push_back(Fila(U,F[i]));
    }
    return matriz;
}
 */

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

/*int main(){
    vector <string> A{"1","2","3","4","5","6"};
    vector <string> B{"5","6","8","9"};
    vector <string> C{"1","4","7","10"};
    vector <string> D{"2","5","8","11"};
    vector <string> E{"3","6","9","12"};
    vector <string> G{"10","11","12"};
    vector <string> X{"1","2","3","4","5","6","7","8","9","10","11","12"};
    vector <vector <string>> F{A,B,C,D,E,G};
    //vector<bool> xd=Fila(X,A);
    //printVectorElements(xd);
    //vector <vector <bool>> M=creaMatriz(F,X);
    //for (int i = 0; i < M.size(); i++)
    //{
    //    printVectorElements(M[i]);
    //}

    vector <vector<string>> resultado=mscp(X,F);
    cout << endl;
    cout<<resultado.size()<<endl;
    return 0;
}*/