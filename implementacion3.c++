#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


vector<int> resta(vector<int> &U,vector<int> &S){
    for(vector<int>::iterator i=S.begin();i!=S.end();++i){
        for(vector<int>::iterator j=U.begin();j!=U.end();++j){
            if (*i==*j)
               U.erase(j); 
        }
    } 
    return U;
}

vector<int> maximizar(vector <vector <int>> &F,vector<int> &U,vector<int> &S){
    for (vector<vector<int>>::iterator i=F.begin();i!=F.end();++i)
    {
        /* code */
    }
    
    return U;
}

vector<vector<int>> mscp(vector<int> x,vector <vector <int>> F){
    vector<int> U=x;
    vector<vector<int>> C;
    vector<int> S;
    while (U.size()!=0){
        S=maximizar(F,U,S);
        U=resta(U,S);
        C.push_back(S);
    }
    return C;
}

int main(){
    vector <int> s1{0,1,2,3,5,6,7,8};
    vector <int> s2{2,4,6,8,9,5};
    vector <int> s3{4,6,9,1};
    vector <int> X{0,1,2,3,4,5,6,7,8,9};
    vector <vector <int>> F{s1,s2,s3};


    cout<<"hola mundo"<<endl;
    return 0;
}