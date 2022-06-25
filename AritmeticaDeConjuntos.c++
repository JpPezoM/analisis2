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


void printVectorElements(vector <string> &vec)
{
    cout << "{ ";
    for (const auto &item : vec) {
        cout << item << ", ";
    }
    cout << "\b\b }" << endl;
}

vector<string> unionVe(vector <string> &v1,vector <string> &v2){
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