#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

vector<string> unionVe(vector <string> &v1,vector <string> &v2){
    vector<string> unions=v1;
    vector<string> aux=v2;
    bool repite;
    while (aux.size()!=0){
        repite=false;
        for(vector <string>::iterator i=unions.begin();i!=unions.end();++i){
            if(*i==aux[0]){
                repite= true;
                aux.erase(aux.begin());
                break;
            }
        }
        if (!repite){
                unions.push_back(aux[0]);
                aux.erase(aux.begin());
            }
            
    }
    return unions;
}
vector <string> resta(vector <string> &U,vector <string> &S){
    for(vector <string>::iterator i=S.begin();i!=S.end();++i){
        for(vector <string>::iterator j=U.begin();j!=U.end();++j){
            if (*i==*j){
               U.erase(j);
               break; 
            }
        }
    } 
    return U;
}

int interseca(vector <string> &U,vector <string> &S){
    int tamaño=0;
    for(vector <string>::iterator i=S.begin();i!=S.end();++i){
        for(vector <string>::iterator j=U.begin();j!=U.end();++j){
            if (*i==*j){
               tamaño++;
               break;
            }
        }
    } 
    return tamaño;
}

vector <vector <string>> maximizar(vector <vector <string>> &F,vector <string> &U,vector <string> &S, int k){
    int tamaño=0;
    vector <string> aux;
    vector <vector <string>> Conjunto;
    for (vector<vector <string>>::iterator i=F.begin();i!=F.end();++i){
        for (vector<vector <string>>::iterator j=F.begin();j!=F.end();++j){
            aux=unionVe(*i,*j);
            int n=interseca(U,aux);
            if(tamaño<n){
                tamaño=n;
                Conjunto.clear();
                Conjunto.push_back(*i);
                Conjunto.push_back(*j);
            }
        }
    }
    return Conjunto;
}
void printVectorElements(vector <string> &vec)
{
    cout << "{ ";
    for (const auto &item : vec) {
        cout << item << ", ";
    }
    cout << "\b\b }" << endl;
}

vector <vector <string>> mscp(vector <string> x,vector <vector <string>> F, int k){
    vector <string> U=x;//{1,1,1,1,1,1,1,1}->{0,0,0,0,0,0,0,0,0,0}
    vector <vector <string>> C;
    vector <string> S;
    while (U.size()!=0){
        S=maximizar(F,U,S,k);
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
    vector <string> A{"1","2","3","4","5","6"};
    vector <string> B{"5","6","8","9"};
    vector <string> C{"1","4","7","10"};
    vector <string> D{"2","5","8","11"};
    vector <string> E{"3","6","9","12"};
    vector <string> G{"10","11","12"};
    vector <string> X{"1","2","3","4","5","6","7","8","9","10","11","12"};
    vector <vector <string>> F{A,B,C,D,E,G};
    int k=2;

    //vector <vector<string>> resultado=mscp(X,F,k);
    vector <string> K=unionVe(A,C);
    printVectorElements(K);
    //cout << endl;
    //cout<<resultado.size()<<endl;
    return 0;
}