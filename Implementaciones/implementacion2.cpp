//Min Set Cover (Unicost) Método Exhaustivo Optimizado
//Recibe Matriz binaria, donde cada fila es un set y cada columna un elemento del universo
//Entrega el menor conjunto de filas que cubren todos los elementos

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include "Funciones/tools1.h"
using namespace std;


vector<int> optimizedES(int m, int n, vector<bool> &matrix){
    vector<int> result(m);
    vector<bool> aux(n); //elementos cubiertos en cada combinacion
    vector<bool> combi(m); //vector ayuda para recorrer las combinaciones posibles
    int c; //numero de sets añadidos en cada instante
    initCombi(combi);
    initVector(result, m);

    //testea todas las 2^m combinaciones distintas de sets
    for(int i = 0; i < pow(2,m) - 1; i++){
        c = 0;
        restartVector(aux, n);
        for(int j = 0; j <= n; j++){
            //optimizacion 2: si los conjuntos agregados son mayores a la solucion parcial paso de largo
            if(combi[j] and result.size() > c){ 
                //Añade los elementos cubiertos por el conjunto al aux
                for(int l = 0; l < n; l++) aux[l] = aux[l] or matrix[(j * n) + l];
                c++;
            }
        }
        if(result.size() > c and setCover(aux, n)){
            result.clear();
            for(int k = 0; k < n; k++){
                if(combi[k]) result.push_back(k);
            }
        }
        plusOne(combi);
    }
    return result;
}

int main(){
    int m = 6; //numero de conjuntos
    int n = 12; //numero de elementos
    vector<bool> carlos(m*n); // matriz de prueba
    carlos = 
    {
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 
        1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
        0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 
        0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1
    };

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

    //creo una nueva matriz que no contiene los conjuntos con elem unicos ni los elem. que cubren
    deleteRows(sv, carlos, n);
    deleteColumns(m, n, carlos, aux1);

    vector<int> msc;
    msc = optimizedES(m1, n1, carlos);

    correctResultIndex(sv, msc);

    printf("el minimum set cover es de tamaño: ");
    cout << msc.size() << endl;
    printVector(msc);
    return 0;
}
 