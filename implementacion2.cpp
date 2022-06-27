//Min Set Cover (Unicost) Método Exhaustivo Optimizado
//Recibe Matriz binaria, donde cada fila es un set y cada columna un elemento del universo
//Entrega el menor conjunto de filas que cubren todos los elementos

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include "tools1.h"
using namespace std;

void deleteRows(vector<int> base, vector<bool> &mat, int n){
    //elimina filas
    int c = 0; 
    for(int i = (base.size()) - 1; i >= 0; i--){
        c = base[i] * n;
        mat.erase(mat.begin() + c, mat.begin() + (c + n)); 
    }
}

void deleteColumns(int m, int n, vector<bool> &mat, vector<bool> &aux, int m1, int n1){
    vector<bool> newMat = {};
    
    
    //elimina columnas
    for(int d= 0; d < mat.size(); d++){
        if(not aux[d%n]) newMat.push_back(mat[d]);
    }
    mat.swap(newMat);
    newMat.clear();

    //imprime matriz
    for(int j = 0; j < mat.size(); j++){
            if((j % n1) == 0) cout << endl;
            cout << mat[j] << " ";
            
        }
        cout << endl;
}

vector<int> optimizedES(int m, int n, vector<bool> &matrix){
    vector<int> result(m);
    vector<bool> aux(n);
    vector<bool> combi(m);
    int c;
    initCombi(combi);
    initVector(result, m);

    //testea todas las 2^m combinaciones distintas de sets
    for(int i = 0; i < pow(2,m) - 1; i++){
        c = 0;
        restartVector(aux, n);
        for(int j = 0; j <= n; j++){
            if(combi[j]){
                //Añade la fila al aux
                for(int l = 0; l < n; l++){
                aux[l] = aux[l] or matrix[(j * n) + l];
                }
                c++;
            }
        }
        if(setCover(aux, n) and result.size() > c){
            result.clear();
            for(int k = 0; k < n; k++){
                if(combi[k]) result.push_back(k);
            }
        }
        plusOne(combi);
    }
    return result;
}

//añade los indices de los conjuntos con elementos unicos(que quitamos de la matriz) y corrige los indices para 
//calzar con la matriz original
void correctResultIndex(vector<int> &orig, vector<int> &final){
    for(int i: orig){
        for(int j = 0; j < final.size(); j++){
            if(i <= final[i]) final[j] += 1;
        }
    }
    for(int k: orig) final.push_back(k);

}

int main(){
    int m = 6;
    int n = 12;
    vector<bool> carlos(m*n); // matriz de prueba
    carlos = 
    {
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 
        1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
        0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1
    };

    for(int j = 0; j < (m * n); j++){
            if((j % 12) == 0) cout << endl;
            cout << carlos[j] << " ";
            
        }
    cout << endl;

    set<int> s;
    s = uniqueElem(m, n, carlos);
    int m1 = m - s.size(); //nuevo numero de conjuntos

    vector<int> sv={}; 
    for(int a: s) sv.push_back(a);

    //union de los sets con elemento unico
    vector<bool> aux1(n);
    restartVector(aux1, n);
    for(int b: sv){
        for(int l = 0; l < n; l++){
            aux1[l] = aux1[l] or carlos[(b * n) + l];
            } 
    }

    int n1 = 0; //Nuevo numero de elementos
    for (bool a: aux1) a ? n1 += 0 : n1 += 1; 

    deleteRows(sv, carlos, n);
    deleteColumns(m, n, carlos, aux1, m1, n1);

    vector<int> msc;
    msc = optimizedES(m1, n1, carlos);

    correctResultIndex(sv, msc);

    printf("el minimum set cover es de tamaño: ");
    cout << msc.size() << endl;
    printVector(msc);
    return 0;
}