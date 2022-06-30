//Min Set Cover(Unicost) Metodo Exhaustivo O(2^N * m)
//Recibe una matriz binaria (1 y 0) y entrega un subconjunto de filas tal que en todas las columnas existan al menos un 1
//TODO programar la lectura/conversion de la entrada y quitar un poco de for-loop's

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include "Funciones/tools1.h"
using namespace std;


vector<int> exhaustiveSearch(int m, int n, vector<bool> &matrix){
    vector<int> result(m);//msc mas pequeño encontrado hasta el momento
    vector<bool> aux(n); //elementos cubiertos en cada iteracion
    vector<bool> combi(m); //vector ayuda para recorrer las combinaciones posibles
    int c; //numero de sets añadidos en cada iteracion
    initCombi(combi);
    initVector(result, m);

    //testea todas las 2^m combinaciones distintas de sets
    for(int i = 0; i < pow(2,m) - 1; i++){
        c = 0;
        restartVector(aux, n);
        for(int j = 0; j <= n; j++){
            if(combi[j]){
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

    vector<int> msc;
    msc = exhaustiveSearch(m, n, carlos);
    printf("el minimum set cover es de tamaño: ");
    cout << msc.size() << endl;
    printVector(msc);
    return 0;
}