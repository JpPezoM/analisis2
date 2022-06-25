#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


vector<int> resta(vector<int> &U,vector<int> &S){
    for(vector<int>::iterator i=S.begin();i!=S.end();++i){
        for(vector<int>::iterator j=U.begin();j!=U.end();++j){
            if (*i==*j){
               U.erase(j);
               break; 
            }
        }
    } 
    return U;
}

int interseca(vector<int> &U,vector<int> &S){
    int tamaño=0;
    for(vector<int>::iterator i=S.begin();i!=S.end();++i){
        for(vector<int>::iterator j=U.begin();j!=U.end();++j){
            if (*i==*j){
               tamaño++;
               break;
            }
        }
    } 
    return tamaño;
}

vector<int> maximizar(vector <vector <int>> &F,vector<int> &U,vector<int> &S){
    int tamaño=0;
    vector<int> aux;
    for (vector<vector<int>>::iterator i=F.begin();i!=F.end();++i){
        int n=interseca(U,*i);
        if(tamaño<n){
            tamaño=n;
            aux=*i;
        }
    }
    return aux;
}
void printVectorElements(vector<int> &vec)
{
    cout << "{ ";
    for (const auto &item : vec) {
        cout << item << ", ";
    }
    cout << "\b\b }" << endl;
}

vector<vector<int>> mscp(vector<int> x,vector <vector <int>> F){
    vector<int> U=x;
    vector<vector<int>> C;
    vector<int> S;
    while (U.size()!=0){
        S=maximizar(F,U,S);
        cout<<"U:"<<endl;
        printVectorElements(U);
        U=resta(U,S);
        cout<<"S:"<<endl;
        printVectorElements(S);
        cout<<"U-S:"<<endl;
        printVectorElements(U);
        
        cout<<"sali de la resta"<<endl;
        C.push_back(S);
    }
    return C;
}

int main(){
    vector <int> A{1,2,3,4,5,6};
    vector <int> B{5,6,8,9};
    vector <int> C{1,4,7,10};
    vector <int> D{2,5,8,11};
    vector <int> E{3,6,9,12};
    vector <int> G{10,11,12};
    vector <int> X{1,2,3,4,5,6,7,8,9,10,11,12};
    vector <vector <int>> F{A,B,C,D,E,G};

    vector <vector <int>> resultado=mscp(X,F);
    cout << endl;
    cout<<resultado.size()<<endl;
    return 0;
}