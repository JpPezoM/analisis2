#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    int tamano=0;
    for(vector <string>::iterator i=S.begin();i!=S.end();++i){
        for(vector <string>::iterator j=U.begin();j!=U.end();++j){
            if (*i==*j){
               tamano++;
               break;
            }
        }
    } 
    return tamano;
}


/* void printVector(vector <string> &vec)
{
    cout << "{ ";
    for (const auto &item : vec) {
        cout << item << ", ";
    }
    cout << "\b\b }" << endl;
}
void printConjunto(vector<vector<string>> &vec)
{
    for (vector<vector<string>>::iterator i=vec.begin();i!=vec.end();++i){ 
        cout << "{ ";
        for (const auto &item : *i) {
            cout << item << ", ";
        }
        cout << "\b\b }" << endl;
    }
    
    
} */

vector<string> unionVectores(vector <string> &v1,vector <string> &v2){
    if(v1.size()==0){
        return v2;
    }
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

vector<string> restaVecConjunto(vector<string> &U, vector<vector<string>> &S){
    for (vector<vector<string>>::iterator i = S.begin(); i != S.end(); ++i){
        U=resta(U,*i);
    }
    return U;
}

int elementosEnComun(vector <string> &v1,vector <string> &v2){
    int encomun=0;
    for (vector<string>::iterator i=v1.begin();i!=v1.end();++i){
        for (vector<string>::iterator j=v2.begin();j!=v2.end();++j){
            if(*i==*j)
                encomun++;
        }
    }
    return encomun;
}

vector<string> unionConVec(vector<vector<string>> &v1, vector<string> &v2){
    vector<string> unions;
    for (vector<vector<string>>::iterator i = v1.begin(); i != v1.end(); ++i){
        unions=unionVectores(unions,*i);
    }
    vector<string> aux = v2;
    bool repite;
    while (aux.size() != 0){
        repite = false;
        for (vector<string>::iterator i = unions.begin(); i != unions.end(); ++i){
            if (*i == aux[0]){
                repite = true;
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

vector<vector<string>> agregaVec(vector<vector<string>> &S,vector<vector<string>> &C){
    for (vector<vector<string>>::iterator i = S.begin(); i != S.end(); ++i){
            C.push_back(*i);
        }
    return C;
}